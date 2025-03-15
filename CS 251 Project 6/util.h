/* util.h
 * Omkarnath Halleppanawar ohalle2
 *
 * util.h houses all the functions that are needed to encode and
 * decode files as well as compress and decompress.
 * The Huffman algorithm for lossless compression
 * is utilized in this program.
 */

#include <iostream>
#include <fstream>
#include <map>
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include <string>
#include "bitstream.h"
#include "hashmap.h"
#include "mymap.h"
#pragma once

/*
 * struct that is the Huffman nodes used to build the encoding tree
 */
struct HuffmanNode {
    int character;
    int count;
    HuffmanNode* zero;
    HuffmanNode* one;
};

/*
 * Struct for priority_queue that gives how HuffmanNodes are
 * ordered
 */
struct prioritize {
 public:
    bool operator()(const HuffmanNode* h1, const HuffmanNode* h2) const {
        return h1->count > h2->count;
    }
};

//
// *This method frees the memory allocated for the Huffman tree.
//
void freeTree(HuffmanNode* node) {
    if (node == nullptr) {
        return;
    }
    freeTree(node->zero);
    freeTree(node->one);
    delete node;
}

/*
 * helper function for buildFrequencyMap
 * this function adds a pair to the hashmap
 * if a key is already in the map, it updates its value
 */
void addToMap(char c, hashmap& map) {
    if (!map.containsKey(int(c))) {
        map.put(int(c), 1);
    } else {
        int newFreq = map.get(int(c)) + 1;
        map.put(int(c), newFreq);
    }
}
//
// *This function build the frequency map.  If isFile is true, then it reads
// from filename.  If isFile is false, then it reads from a string filename.
//
void buildFrequencyMap(string filename, bool isFile, hashmap &map) {
    if (isFile) {
        ifstream inFS(filename);
        char c;
        while (inFS.get(c)) {
            addToMap(c, map);
        }
        inFS.close();
    } else {
        for (char& c : filename) {
            addToMap(c, map);
        }
    }
    map.put(PSEUDO_EOF, 1);
}

//
// *This function builds an encoding tree from the frequency map.
//
HuffmanNode* buildEncodingTree(hashmap &map) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, prioritize> pq;
    vector<int> v = map.keys();
    // add all nodes to queue
    for (auto& e : v) {
        HuffmanNode* h1 = new HuffmanNode();
        h1->character = e;
        h1->count = map.get(e);
        pq.push(h1);
    }
    while (pq.size() > 1) {
        HuffmanNode* first = pq.top();
        pq.pop();
        HuffmanNode* second = pq.top();
        pq.pop();
        HuffmanNode* node = new HuffmanNode();
        node->character = NOT_A_CHAR;
        node->count = first->count + second->count;
        node->zero = first;
        node->one = second;
        pq.push(node);
    }
    return pq.top();
}

/*
 * recursive helper function for buildEncodingMap
 * this function traverses the tree recursively and builds a string
 * that is added to the map
 */
void _buildEncodingMap(HuffmanNode* node, string str, mymap<int, string>& encodingMap) {
    if (node->character != NOT_A_CHAR) {
        encodingMap.put(node->character, str);
        return;
    }
    _buildEncodingMap(node->zero, str + "0", encodingMap);
    _buildEncodingMap(node->one, str + "1", encodingMap);
}

//
// *This function builds the encoding map from an encoding tree.
//
mymap <int, string> buildEncodingMap(HuffmanNode* tree) {
    mymap<int, string> encodingMap;
    if (tree == nullptr) {
        return encodingMap;
    }
    string str = "";
    _buildEncodingMap(tree, str, encodingMap);
    return encodingMap;
}

//
// *This function encodes the data in the input stream into the output stream
// using the encodingMap.  This function calculates the number of bits
// written to the output stream and sets result to the size parameter, which is
// passed by reference.  This function also returns a string representation of
// the output file, which is particularly useful for testing.
//
string encode(ifstream& input, mymap <int, string> &encodingMap,
              ofbitstream& output, int &size, bool makeFile) {
    string encoded;
    char c;
    while (input.get(c)) {
        encoded += encodingMap.get(int(c));
    }
    encoded += encodingMap.get(PSEUDO_EOF);
    size = encoded.size();
    if (makeFile) {
        for (char& c : encoded) {
            output.writeBit((int)(c - '0'));
        }
    }
    return encoded;
}


//
// *This function decodes the input stream and writes the result to the output
// stream using the encodingTree.  This function also returns a string
// representation of the output file, which is particularly useful for testing.
//
string decode(ifbitstream &input, HuffmanNode* encodingTree, ofstream &output) {
    string decoded = "";
    HuffmanNode* curr = encodingTree;
    while (!input.eof()) {
        if (curr->character == PSEUDO_EOF) {
            break;
        }
        if (curr->character != NOT_A_CHAR) {
            output.put(curr->character);
            decoded += curr->character;
            curr = encodingTree;
        }
        int bit = input.readBit();
        if (bit == 0) {
            curr = curr->zero;
        } else {
            curr = curr->one;
        }
    }
    return decoded;
}

//
// *This function completes the entire compression process.  Given a file,
// filename, this function (1) builds a frequency map; (2) builds an encoding
// tree; (3) builds an encoding map; (4) encodes the file (don't forget to
// include the frequency map in the header of the output file).  This function
// should create a compressed file named (filename + ".huf") and should also
// return a string version of the bit pattern.
//
string compress(string filename) {
    hashmap frequencyMap;
    buildFrequencyMap(filename, true, frequencyMap);
    HuffmanNode* encodingTree = buildEncodingTree(frequencyMap);
    mymap<int, string> encodingMap = buildEncodingMap(encodingTree);
    ofbitstream output(filename + ".huf");
    output << frequencyMap;
    ifstream input(filename);
    int size;
    string compressed = encode(input, encodingMap, output, size, true);
    freeTree(encodingTree);
    input.close();
    output.close();
    return compressed;
}

//
// *This function completes the entire decompression process.  Given the file,
// filename (which should end with ".huf"), (1) extract the header and build
// the frequency map; (2) build an encoding tree from the frequency map; (3)
// using the encoding tree to decode the file.  This function should create a
// compressed file using the following convention.
// If filename = "example.txt.huf", then the uncompressed file should be named
// "example_unc.txt".  The function should return a string version of the
// uncompressed file.  Note: this function should reverse what the compress
// function did.
//
string decompress(string filename) {
    ifbitstream input(filename);
    int pos = filename.find(".");
    string newName = filename.substr(0, pos);
    ofstream output(newName + "_unc.txt");
    hashmap frequencyMap;
    input >> frequencyMap;
    HuffmanNode* encodingTree = buildEncodingTree(frequencyMap);
    string decoded = decode(input, encodingTree, output);
    freeTree(encodingTree);
    input.close();
    output.close();
    return decoded;
}
