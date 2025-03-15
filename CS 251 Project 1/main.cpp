/* Project 1 - DNA Profiling
 * Omkar Halleppanawar
 *
 * Project Description:
 * An app that builds DNA strands using provided ourvector
 * implementation and and then determine who the DNA matches
 * to in a given database. The user communicates with the program
 * through a menu.
 *
 * CREATIVE COMPONENT:
 * I created an extra function called countAll. This function counts
 * all instances of the given STRs in a particular DNA strand. To
 * call the function, type "count" into the menu. The function needs
 * load_db and load_dna to be called before using it. When the function
 * is called it will display the STRs in the database and how many
 * times they appeared in the DNA strand.
 */

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "ourvector.h"

using namespace std;


 /*
  * Struct containing person's name and sequence count
  */
struct Person {
    string name;
    ourvector<int> dnaCount;
};

/*
 * Helper function to store people's data for load_db (name and dnaCount)
 * Parameters:
 *    string otherLines - all lines containing person data
 *    ourvector<Person>& peopleVector - will store person data
 * Return: void
 */
void personData(string otherLines, ourvector<Person>& peopleVector) {
    stringstream ss(otherLines);
    string pName;
    string count;
    Person p1 = Person();

    getline(ss, pName, ',');
    p1.name = pName;

    while (getline(ss, count, ',')) {
        p1.dnaCount.push_back(stoi(count));
    }
    peopleVector.push_back(p1);
}

/*
 * Helper function to store first line's data for load_db
 * Parameters:
 *    ourvector<ourvector<char>>& strData - will store STR sequences
 * Return: void
 */
void sequenceData(string firstLine, ourvector<ourvector<char>>& strData) {
    stringstream ss(firstLine);
    string sequence;

    while (getline(ss, sequence, ',')) {
        ourvector<char> temp;
        for (char& ch : sequence) {
            temp.push_back(ch);
        }
        strData.push_back(temp);
    }
}

/*
 * Function to load the database
 * Parameters:
 *    string filename - name of database file
 *    ourvector<Person>& peopleVector - stores person data
 *    ourvector<ourvector<char>>& strData - stores STR sequences
 * Return: void
 */
void load_db(string filename, ourvector<Person>& peopleVector,
             ourvector<ourvector<char>>& strData) {
    ifstream inFS(filename);
    cout << "Loading database..." << endl;
    if (!inFS.is_open()) {
        cout << "Error: unable to open " << "'" << filename << "'" << endl;
        return;
    }
    peopleVector.clear();  // make sure vectors do not have old information
    strData.clear();
    string tempName;
    getline(inFS, tempName, ',');  // move past name since it is not needed

    string firstLine;
    getline(inFS, firstLine);
    sequenceData(firstLine, strData);

    string otherLines;
    while (getline(inFS, otherLines)) {
        personData(otherLines, peopleVector);
    }
    inFS.close();
}
/*
 * Helper function that displays the database for display
 * Parameters:
 *       ourvector<Person>& peopleVector - stores person data
 * Return: void
 */
void displayDatabase(ourvector<Person>& peopleVector) {
    if (peopleVector.size() > 0) {
        cout << "Database loaded: " << endl;
        for (Person& p1 : peopleVector) {
            cout << p1.name;
            for (int& count : p1.dnaCount) {
                cout << " " << count;
            }
            cout << endl;
        }
    } else {
        cout << "No database loaded.";
    }
    cout << endl;
}

/*
 * Helper function that displays the dna sequence for display
 * Parameters:
 *       ourvector<char>& dnaSequence - stores dna sequence data
 * Return: void
 */
void displayDna(ourvector<char>& dnaSequence) {
    if (dnaSequence.size() > 0) {
        cout << "DNA loaded: " << endl;
        for (char& ch : dnaSequence) {
            cout << ch;
        }
        cout << endl;
    } else {
        cout << "No DNA loaded." << endl;
    }
    cout << endl;
}

/*
 * Helper function that displays the process command for display
 * Parameters:
 *       ourvector<ourvector<char>>& strData - stores STR sequences
 *       ourvector<int>& processVector - stores results of processing DNA
 * Return: void
 */
void displayProcess(ourvector<ourvector<char>>& strData,
                    ourvector<int>& processVector) {
    if (processVector.size() > 0) {
        cout << "DNA processed, STR counts: " << endl;
        for (int i = 0; i < strData.size(); i++) {
            for (char& ch : strData.at(i)) {
                cout << ch;
            }
            cout << ": " << processVector.at(i) << endl;
        }
        cout << endl;
    } else {
        cout << "No DNA has been processed." << endl;
    }
}

/*
 * CREATIVE COMPONENT
 * Helper function that displays the count command for the function
 * Parameters:
 *       ourvector<ourvector<char>>& strData - stores STR sequences
 *       ourvector<int>& instanceVector - stores how many times STR
 *                                        shows up in sequence
 * Return: void
 */
void displayCount(ourvector<ourvector<char>>& strData,
                  ourvector<int>& instanceVector) {
    if (instanceVector.size() > 0) {
        cout << "Instances of STRs: " << endl;
        for (int i = 0; i < strData.size(); i++) {
            for (char& ch : strData.at(i)) {
                cout << ch;
            }
            cout << ": " << instanceVector.at(i) << endl;
        }
        cout << endl;
    }
}

/*
 * Function to display contents of database and dna process, etc.
 * Parameters:
 *       ourvector<Person>& peopleVector - stores person data
 *       ourvector<ourvector<char>>& strData - stores STR sequences
 *       ourvector<int>& processVector - stores results of processing DNA
 *       ourvector<string>& nameVector - name of match found in search
 * Return: void
 */
void display(ourvector<Person>& peopleVector,
             ourvector<ourvector<char>>& strData,
             ourvector<char>& dnaSequence, ourvector<int>& processVector) {
    displayDatabase(peopleVector);
    displayDna(dnaSequence);
    displayProcess(strData, processVector);
}

/*
 * Loads the entire dna sequence for the program
 * Parameters:
 *       string filename - file containing DNA sequence
 *       ourvector<char>& dnaSequence - stores DNA sequence
 * Return: void
 */
void load_dna(string filename, ourvector<char>& dnaSequence) {
    ifstream inFS(filename);
    cout << "Loading DNA..." << endl;
    if (!inFS.is_open()) {
        cout << "Error: unable to open " << "'" << filename << "'" << endl;
        return;
    }
    dnaSequence.clear();  // make sure sequence is clear before loading
    string line;
    while (getline(inFS, line)) {
        for (char& ch : line) {
            dnaSequence.push_back(ch);
        }
    }
    inFS.close();
}

/*
 * Helper function that finds consecutive STR sequences for process
 * Parameters:
 *       ourvector<ourvector<char>>& strData - stores STR sequences
 *       ourvector<char>& dnaSequence - stores DNA sequence
 *       ourvector<int>& processVector - stores results of processing DNA
 * Return: void
 */
void findRepeat(ourvector<char>& str, ourvector<char>& dnaSequence,
                ourvector<int>& processVector) {
    int dnaFindIndex = 0;  // index being compared in dna sequence
    int dnaCurrIndex = 0;  // old index to return to if no match
    int strCharIndex = 0;  // indec of letter in STR
    int currentLong = 0;  // current longest repeat
    int maxLong = 0;  // max longest repeat

    while (dnaCurrIndex + str.size() <= dnaSequence.size()) {
        // until reached end of dna sequence
        while (strCharIndex < str.size() && str.at(strCharIndex)
               == dnaSequence.at(dnaFindIndex)) {
            // chexk if str letter match dna letter
            strCharIndex++;
            dnaFindIndex++;
        }
        if (str.size() == strCharIndex) {
            // check if all characters for str at str index matched
            currentLong++;
            dnaCurrIndex = dnaFindIndex;  // compare from letter after str match
            strCharIndex = 0;  // restart str to look for more matches
            if (currentLong > maxLong) {
                maxLong = currentLong;
            }
        } else {
            dnaCurrIndex++;
            dnaFindIndex = dnaCurrIndex;
            currentLong = 0;
        }
        strCharIndex = 0;
    }
    processVector.push_back(maxLong);
}

/*
 * Function that finds langest repeated STR sequences given a sequence of DNA
 * Parameters:
 *       ourvector<Person>& peopleVector - stores person data
 *       ourvector<ourvector<char>>& strData - stores STR sequences
 *       ourvector<char>& dnaSequence - stores DNA sequence
 *       ourvector<int>& processVector - stores results of processing DNA
 * Return: void
 */
void process(ourvector<Person>& peopleVector,
             ourvector<ourvector<char>>& strData,
             ourvector<char>& dnaSequence, ourvector<int>& processVector) {
    if (peopleVector.size() == 0) {
        cout << "No database loaded." << endl;
        return;
    }
    if (dnaSequence.size() == 0) {
        cout << "No DNA loaded." << endl;
        return;
    }
    processVector.clear();
    cout << "Processing DNA..." << endl;
    for (ourvector<char>& str : strData) {
        findRepeat(str, dnaSequence, processVector);
    }
}

/*
 * Helper function for search that finds person with matching STR counts
 * Parameters:
 *       ourvector<Person>& peopleVector - stores person data
 *       ourvector<int>& processVector - stores results of processing DNA
 *       ourvector<string>& nameVector - name of match found in search
 * Return: void
 */
void findMatch(ourvector<Person>& peopleVector, ourvector<int>& processVector,
               ourvector<string>& nameVector) {
    for (int i = 0; i < peopleVector.size(); i++) {
        int count = 0;  // tracks number of STR counts that match
        for (int j = 0; j < processVector.size(); j++) {
            if (processVector.at(j) == peopleVector.at(i).dnaCount.at(j)) {
                count++;
            }
            if (count == processVector.size()) {
                nameVector.push_back(peopleVector.at(i).name);
                break;  // match found, exit loop
            }
        }
    }
}

/*
 * Function that seaches the database for person with matching STR counts
 * Parameters:
 *       ourvector<Person>& peopleVector - stores person data
 *       ourvector<char>& dnaSequence - stores DNA sequence
 *       ourvector<int>& processVector - stores results of processing DNA
 *       ourvector<string>& nameVector - name of match found in search
 * Return: void
 */
void search(ourvector<Person>& peopleVector, ourvector<char>& dnaSequence,
            ourvector<int>& processVector, ourvector<string>& nameVector) {
    if (peopleVector.size() == 0) {
        cout << "No database loaded." << endl;
        return;
    }
    if (dnaSequence.size() == 0) {
        cout << "No DNA loaded." << endl;
        return;
    }
    if (processVector.size() == 0) {
        cout << "No DNA processed." << endl;
        return;
    }
    nameVector.clear();
    cout << "Searching database..." << endl;
    findMatch(peopleVector, processVector, nameVector);

    if (nameVector.size() > 0) {
        cout << "Found in database! DNA matches: " << nameVector.at(0) << endl;
    } else {
        cout << "Not found in database." << endl;
    }
}

/*
 * CREATIVE COMPONENT:
 * Helper function that finds all STR instances for countAll
 * Parameters:
 *       ourvector<ourvector<char>>& strData - stores STR sequences
 *       ourvector<char>& dnaSequence - stores DNA sequence
 *       ourvector<int>& instanceVector - stores instances of STRS
 * Return: void
 */
void findAll(ourvector<char>& str, ourvector<char>& dnaSequence,
             ourvector<int>& instanceVector) {
    int dnaFindIndex = 0;  // index being compared in dna sequence
    int dnaCurrIndex = 0;  // old index to return to if no match
    int strCharIndex = 0;  // take the first letter of first str
    int instances = 0;  // number of STR instances

    while (dnaCurrIndex + str.size() <= dnaSequence.size()) {
        // not reached end of dna sequence
        while (strCharIndex < str.size() && str.at(strCharIndex)
                == dnaSequence.at(dnaFindIndex)) {
            // chexk if str letter match dna letter
            strCharIndex++;
            dnaFindIndex++;
        }
        if (str.size() == strCharIndex) {
            // check if all characters for str at str index matched
            instances++;
            dnaCurrIndex = dnaFindIndex;  // compare from letter after str match
            strCharIndex = 0;  // restart str to look for more matches
        } else {
            dnaCurrIndex++;
            dnaFindIndex = dnaCurrIndex;
        }
        strCharIndex = 0;
    }
    instanceVector.push_back(instances);
}

/*
 * CREATIVE COMPONENT:
 * Function that counts all instances of STRs given a sequence of DNA
 * Parameters:
 *       ourvector<Person>& peopleVector - stores person data
 *       ourvector<ourvector<char>>& strData - stores STR sequences
 *       ourvector<char>& dnaSequence - stores DNA sequence
 *       ourvector<int>& processVector - stores results of processing DNA
 * Return: void
 */
void countAll(ourvector<Person>& peopleVector,
              ourvector<ourvector<char>>& strData,
              ourvector<char>& dnaSequence, ourvector<int>& instanceVector) {
    if (peopleVector.size() == 0) {
            cout << "No database loaded." << endl;
            return;
    }
    if (dnaSequence.size() == 0) {
            cout << "No DNA loaded." << endl;
            return;
    }
    instanceVector.clear();
    cout << "Counting STRs..." << endl;
    for (ourvector<char>& str : strData) {
        findAll(str, dnaSequence, instanceVector);
    }
    displayCount(strData, instanceVector);
}

int main() {
    ourvector<Person> peopleVector;
    ourvector<ourvector<char>> strData;
    ourvector<char> dnaSequence;
    ourvector<int> processVector;
    ourvector<string> nameVector;
    ourvector<int> instanceVector;

    cout << "Welcome to the DNA Profiling Application." << endl;
    string command, filename1, filename2;

    while (command != "#") {
        cout << "Enter command or # to exit: ";
        cin >> command;
        if (command == "load_db") {
            cin >> filename1;
            load_db(filename1, peopleVector, strData);
        } else if (command == "display") {
            display(peopleVector, strData, dnaSequence, processVector);
        } else if (command == "load_dna") {
            cin >> filename2;
            load_dna(filename2, dnaSequence);
        } else if (command == "process") {
            process(peopleVector, strData, dnaSequence, processVector);
        } else if (command == "search") {
            search(peopleVector, dnaSequence, processVector, nameVector);
        } else if (command == "count") {
            countAll(peopleVector, strData, dnaSequence, instanceVector);
        }
    }
    return 0;
}
