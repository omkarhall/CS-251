// mymap.h
// Omkarnath Halleppanawar ohalle2
// mymap is a custom class that imitates the c++ standard map.
// mymap is a threaded, self-balancing bst which allows lookup, etc.
// to be done in logarithmic time
#pragma once

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template<typename keyType, typename valueType>
class mymap {
 private:
    struct NODE {
        keyType key;  // used to build BST
        valueType value;  // stored data for the map
        NODE* left;  // links to left child
        NODE* right;  // links to right child
        int nL;  // number of nodes in left subtree
        int nR;  // number of nodes in right subtree
        bool isThreaded;
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of key/value pairs in the mymap

    //
    // iterator:
    // This iterator is used so that mymap will work with a foreach loop.
    //
    struct iterator {
     private:
        NODE* curr;  // points to current in-order node for begin/end

     public:
        iterator(NODE* node) {
            curr = node;
        }

        keyType operator *() {
            return curr -> key;
        }

        bool operator ==(const iterator& rhs) {
            return curr == rhs.curr;
        }

        bool operator !=(const iterator& rhs) {
            return curr != rhs.curr;
        }

        bool isDefault() {
            return !curr;
        }

        //
        // operator++:
        //
        // This function should advance curr to the next in-order node.
        // O(logN)
        //
        iterator operator++() {
            if (curr->isThreaded) {
                curr = curr->right;
            } else {
                
                if (curr->right == nullptr) {
                    curr = nullptr;
                    return iterator(curr);
                }
                
                curr = curr->right;
                while (curr->left != nullptr) {
                    curr = curr->left;
                }
            }
            return iterator(curr);
        }
    };
    
    /*
     * Recursive helper function for toString
     * builds in order traversal of map
     */
    void _buildString(NODE* node, ostream& output) {
        // Base case, node is null, do nothing
        if (node == nullptr) {
            return;
        }
        _buildString(node->left, output);
        output << "key: " << node->key << " " << "value: " << node->value << endl;
        /*
        if(node->left !=nullptr)
            output << "left: " << node->left->key << " ";
        if(node->right != nullptr)
            output << "right: " << node->right->key << " ";
        output << "IsThreaded: " << node->isThreaded;
         */
        _buildString((node->isThreaded) ? nullptr : node->right, output);
    }
    
    /*
     * Recursive helper function for clear
     * deletes all nodes in tree given node
     */
    void _clear(NODE* node) {
        if (node == nullptr) {
            return;
        }
        _clear(node->left);
        _clear((node->isThreaded) ? nullptr : node->right);
        delete node;
    }
    
    /*
     * Recursive helper function for copy constructor
     * copies all nodes in tree given node
     */
    NODE* _copyTree(NODE* otherNode) {
        if (otherNode == nullptr) {
            return nullptr;
        }
        NODE* thisNode = new NODE();
        thisNode->key = otherNode->key;
        thisNode->value = otherNode->value;
        thisNode->isThreaded = otherNode->isThreaded;
        thisNode->nL = otherNode->nL;
        thisNode->nR = otherNode->nR;
        // call on left and right subtrees
        thisNode->left = _copyTree(otherNode->left);
        thisNode->right = _copyTree((otherNode->isThreaded) ? nullptr : otherNode->right);
        return thisNode;
    }
    
    /*
     * Recursive helper function for toVector
     * builds in order traversal of nodes in tree
     */
    void _buildVector(NODE* node, vector<pair<keyType, valueType>>& v) {
        if (node == nullptr) {
            return;
        }
        _buildVector(node->left, v);
        v.push_back(make_pair(node->key, node->value));
        _buildVector((node->isThreaded) ? nullptr : node->right, v);
    }
    
    /*
     * Recursive helper function for checkBalance
     * pre order traversal to check balance
     */
    void _checkBalance(NODE* node, ostream& output) {
        if (node == nullptr) {
            return;
        }
        output << "key: " << node->key << ", ";
        output << "nL: " << node->nL << ", " << "nR: " << node->nR << endl;
        _checkBalance(node->left, output);
        _checkBalance((node->isThreaded) ? nullptr : node->right, output);
    }
    
    /*
     * Recursive helper function for put
     * builds vector of nodes that need to be rebalanced in order
     */
    void _buildVectorNodes(NODE* node, vector<NODE*>& v) {
        if (node == nullptr) {
            return;
        }
        _buildVectorNodes(node->left, v);
        v.push_back(node);
        _buildVectorNodes((node->isThreaded) ? nullptr : node->right, v);
    }

    /*
     * Recursive helper function for put
     * rebalances subtree at node that violates seesaw property
     * this subtree is not threaded, it will be threaded by rethread()
     */
    NODE* _rebalance(vector<NODE*> v, NODE* parent, int left, int right) {
        /*
        cout << "begin _rebalance: ";
        if (parent != nullptr)
            cout << "parent:" << parent->key << endl;
        cout << "left:" << left << endl;
        cout << "right:" << right << endl;
        */
        /*
        if (v.size() == 0) {
            return nullptr;
        } else if (v.size() == 1) {
            return v[0];
        }
        
        
        int left = 0;
        int right = v.size() - 1;
        int mid = (left + right) / 2;
        vector<NODE*> leftV(v.begin(), v.begin() + mid);
        vector<NODE*> rightV(v.begin() + mid + 1, v.end());
         */
        
        if (left > right) {
            return nullptr;
        }
        
        /*
        if(left>=0 && left==right) {
            return v[left];
        }
         */
        int mid = (left + right) / 2;
        NODE* curr = v[mid];
        curr->nL = mid - left;
        curr->nR = right - mid;
        //curr->left = nullptr;
        //curr->right = nullptr;
        curr->isThreaded = false;
        //cout << "curr:" << curr->key << endl;
        NODE* temp;
        //root->left =
        
       // curr->left =_rebalance(v, curr, left, mid - 1);
        temp = _rebalance(v, curr, left, mid - 1);
        curr->left = temp;
       /*veena:--- if (temp !=nullptr) {
            cout << "Rebalance left:" << temp->key << endl;
            temp->right = curr;
            temp->isThreaded = true;

        }
        curr->left = temp;
        
 
        /*
        if (parent != nullptr && tempLeft != nullptr) {
            tempLeft->right = parent;
            parent->left = tempLeft;
            tempLeft->isThreaded = true;
        }
        */
        //NODE* tempRight
        //root->right =
        temp = _rebalance(v, curr, mid + 1, right);
        //curr->right = _rebalance(v, curr, mid + 1, right);
        /*if(temp != NULL){
            temp->right = curr->right;
            temp->isThreaded = true;
        }*/
        /* veena --- if (temp !=nullptr) {
            cout << "Rebalance right:" << temp->key << endl;
       
            if(curr->right != nullptr){
                if(parent != nullptr){
                    if(curr->right->key == parent->key) {
                       curr->isThreaded=true;
                       cout << "curr->right->key: " << curr->right->key << " already set. setting isthreaded to true";
                    } else {
                        curr->right = temp;
                        curr->isThreaded = false;
                    }
                }
                else {
                    curr->right = temp;
                    curr->isThreaded = false;
                }
            } else {
                curr->right = temp;
                curr->isThreaded = false;
                
            }
        }
         */
        
        curr->right = temp;
        /*
        if(temp->key < curr->key) {
            curr->left = temp;
        } else {
            curr->right = temp;
        }
        
        if (parent != nullptr && curr != nullptr && curr->key < parent->key) {
            parent->left = curr;
            curr->right = parent;
            curr->isThreaded = true;
        }
        if (parent != nullptr && curr != nullptr && curr->key > parent->key) {
            curr->right = parent->right;
            parent->right = curr;
            curr->isThreaded = true;
            parent->isThreaded = false;
        }
        */
        /*
        if (parent != nullptr && tempRight != nullptr) {
            tempRight->right = parent->right;
            parent->right = tempRight;
            parent->isThreaded = false;
            tempRight->isThreaded = true;
        }
        */
        /*
        if (tempRight != nullptr) {
            tempRight->isThreaded = true;
            root->right = tempRight;
            root->isThreaded = false;
        }
        */
        //cout << "Rebalance end:" << endl;
        
        return curr;
    }
    
    /*
     * Takes root node as input
     * rethreads subtree that was rebalanced
     */
    NODE* rethread(NODE* root) {
        //NODE* node = nullptr;
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }
        if (root->left != nullptr) {
            NODE* node = rethread(root->left);
            node->right = root;
            node->isThreaded = true;
        }
        /*
        if (root->right != nullptr) {
            node = rethread(root->right);
            node->right = root->right;
            node->isThreaded = true;
            root->isThreaded = false;
            
        }
        */
        if (root->right == nullptr) {
            return root;
        }
        //return node;
        return rethread(root->right);
    }
    
    /*
     * helper function for put
     * finds rightmost node in subtree given a node
     */
    NODE* findRightmost(NODE* curr) {
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        return curr;
    }
    
    /*
     * helper function for put
     * checks to see if seesaw balance property is violated
     */
    void checkViolation(bool& violation, NODE* prev, NODE* curr, NODE*& violatorParent, NODE*& violator) {
        if (!violation) {
            if (max(curr->nL, curr->nR) > 2 * min(curr->nL, curr->nR) + 1) {
                violatorParent = prev;
                violator = curr;
                violation = true;
            }
        }
    }
    
    /*
     * helper function for put
     * inserts new node in tree and threads it
     */
    void createNode(keyType key, valueType value, NODE*& prev) {
        NODE* n = new NODE();
        n->key = key;
        n->value = value;
        n->left = nullptr;
        n->right = nullptr;
        n->isThreaded = true;
        n->nL = 0;
        n->nR = 0;
        if (prev == nullptr) {
            root = n;
        } else if (key < prev->key) {
            n->right = prev;
            prev->left = n;
        } else {
            n->right = prev->right;
            prev->right = n;
            prev->isThreaded = false;
        }
        size++;
        // return n;
    }
    
    /*
     * helper function for put
     * put calls rebalance when there is a violation and the tree must be balanced
     */
    void rebalance(bool violation, NODE*& violatorParent, NODE* violator) {
        if (violation) {
            vector<NODE*> subtree;
            _buildVectorNodes(violator, subtree);
            NODE* fixedSubtree = _rebalance(subtree, nullptr, 0, subtree.size() - 1);
            rethread(fixedSubtree);
            if (violator == root) {
                root = fixedSubtree;
            } else if (violatorParent->left == violator) {
                //fixedSubtree->right = violatorParent;
                violatorParent->left = fixedSubtree;
                NODE* rightMost = findRightmost(fixedSubtree);
                rightMost->right = violatorParent;
                rightMost->isThreaded = true;
                //violator->isThreaded = true;
            } else if (violatorParent->right == violator) {
                //fixedSubtree->right = violatorParent->right;
                violatorParent->right = fixedSubtree;
                NODE* rightMost = findRightmost(fixedSubtree);
                rightMost->right = nullptr;
                rightMost->isThreaded = true;
                //violator->isThreaded = true;
                //violatorParent->isThreaded = false;
            }
            
        }
    }

 public:
    //
    // default constructor:
    //
    // Creates an empty mymap.
    // Time complexity: O(1)
    //
    mymap() {
        root = nullptr;
        size = 0;
    }

    //
    // copy constructor:
    //
    // Constructs a new mymap which is a copy of the "other" mymap.
    // Sets all member variables appropriately.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    mymap(const mymap& other) {
        this->root = _copyTree(other.root);
        this->size = other.size;
    }

    //
    // operator=:
    //
    // Clears "this" mymap and then makes a copy of the "other" mymap.
    // Sets all member variables appropriately.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    mymap& operator=(const mymap& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        this->root = _copyTree(other.root);
        this->size = other.size;
        return *this;
    }

    // clear:
    //
    // Frees the memory associated with the mymap; can be used for testing.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    void clear() {
        _clear(root);
        root = nullptr;
        size = 0;
    }

    //
    // destructor:
    //
    // Frees the memory associated with the mymap.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    ~mymap() {
        _clear(root);
        root = nullptr;
    }

    //
    // put:
    //
    // Inserts the key/value into the threaded, self-balancing BST based on
    // the key.
    // Time complexity: O(logn + mlogm), where n is total number of nodes in the
    // threaded, self-balancing BST and m is the number of nodes in the
    // sub-tree that needs to be re-balanced.
    // Space complexity: O(1)
    //
    void put(keyType key, valueType value) {
        NODE* prev = nullptr;
        NODE* curr = root;
        bool keyPresent = contains(key);  // if key is in map do not change nL/nR
        bool violation = false;  // true if there is a seesaw property violation
        NODE* violator = nullptr; // holds violator closest to root
        NODE* violatorParent = nullptr; // holds violator parent node
        while (curr != nullptr) {
            if (key == curr->key) {
                curr->value = value;
                return;
            }
            // ## mymap MS1: If you found the key, change value
            // ## mymap MS5: Don’t change all nL & nR if key found
            if (key < curr->key) {
                if (!keyPresent) {
                    curr->nL++;
                    /*
                    if (!violation) {
                        if (max(curr->nL, curr->nR) > 2 * min(curr->nL, curr->nR) + 1) {
                            violatorParent = prev;
                            violator = curr;
                            violation = true;
                        }
                    }
                     */
                    checkViolation(violation, prev, curr, violatorParent, violator);
                }
                prev = curr;
                curr = curr->left;
            } else {
                if (!keyPresent) {
                    curr->nR++;
                    /*
                    if (!violation) {
                        if (max(curr->nL, curr->nR) > 2 * min(curr->nL, curr->nR) + 1) {
                            violatorParent = prev;
                            violator = curr;
                            violation = true;
                        }
                    }
                     */
                    checkViolation(violation, prev, curr, violatorParent, violator);
                }
                prev = curr;
                curr = (curr->isThreaded) ? nullptr : curr->right;
            }
        }
        /*
        NODE* n = new NODE();
        n->key = key;
        n->value = value;
        n->left = nullptr;
        n->right = nullptr;
        n->isThreaded = true;
        n->nL = 0;
        n->nR = 0;
         */
        /*NODE* n = */createNode(key, value, prev);
        // ## Your NODE will have more variables, of course
        // ## value, nL, nR, isThreaded: think default values...
        /*
        if (prev == nullptr) {
            root = n;
        } else if (key < prev->key) {
            n->right = prev;
            prev->left = n;
        } else {
            n->right = prev->right;
            prev->right = n;
            prev->isThreaded = false;
        }
        size++;
         */
        // rebalance tree if needed
        /*
        if (violation) {
            vector<NODE*> subtree;
            _buildVectorNodes(violator, subtree);
            NODE* fixedSubtree = _rebalance(subtree, nullptr, 0, subtree.size() - 1);
            rethread(fixedSubtree);
            if (violator == root) {
                root = fixedSubtree;
            } else if (violatorParent->left == violator) {
                //fixedSubtree->right = violatorParent;
                violatorParent->left = fixedSubtree;
                //violator->isThreaded = true;
            } else if (violatorParent->right == violator) {
                //fixedSubtree->right = violatorParent->right;
                violatorParent->right = fixedSubtree;
                //violator->isThreaded = true;
                //violatorParent->isThreaded = false;
            }
        }
         */
        rebalance(violation, violatorParent, violator);
    }

    //
    // contains:
    // Returns true if the key is in mymap, return false if not.
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    bool contains(keyType key) {
        NODE* curr = root;
        while (curr != nullptr) {
            if (key == curr->key) {
                return true;
            }
            if (key < curr->key) {  // Search left
                curr = curr->left;
            } else {
                curr = (curr->isThreaded) ? nullptr : curr->right;  // Search Right
            }
        }
        return false;  // If we get here, not found
    }

    //
    // get:
    //
    // Returns the value for the given key; if the key is not found, the
    // default value, valueType(), is returned (but not added to mymap).
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    valueType get(keyType key) {
        NODE* curr = root;
        while (curr != nullptr) {
            if (key == curr->key) {
                return curr->value;
            }
            if (key < curr->key) {  // Search left
                curr = curr->left;
            } else {
                curr = (curr->isThreaded) ? nullptr : curr->right;  // Search Right
            }
        }
        return valueType();  // If we get here, not found
    }

    //
    // operator[]:
    //
    // Returns the value for the given key; if the key is not found,
    // the default value, valueType(), is returned (and the resulting new
    // key/value pair is inserted into the map).
    // Time complexity: O(logn + mlogm), where n is total number of nodes in the
    // threaded, self-balancing BST and m is the number of nodes in the
    // sub-trees that need to be re-balanced.
    // Space complexity: O(1)
    //
    valueType operator[](keyType key) {
        NODE* curr = root;
        while (curr != nullptr) {
            if (key == curr->key) {
                return curr->value;
            }
            if (key < curr->key) {  // Search left
                curr = curr->left;
            } else {
                curr = (curr->isThreaded) ? nullptr : curr->right;  // Search Right
            }
        }
        valueType v = valueType();
        put(key, v);
        return v;  // If we get here, not found
    }

    //
    // Size:
    //
    // Returns the # of key/value pairs in the mymap, 0 if empty.
    // O(1)
    //
    int Size() {
        return size;
    }

    //
    // begin:
    //
    // returns an iterator to the first in order NODE.
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    iterator begin() {
        NODE* curr = root;
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        return iterator(curr);
    }

    //
    // end:
    //
    // returns an iterator to the last in order NODE.
    // this function is given to you.
    //
    // Time Complexity: O(1)
    //
    iterator end() {
        return iterator(nullptr);
    }

    //
    // toString:
    //
    // Returns a string of the entire mymap, in order.
    // Format for 8/80, 15/150, 20/200:
    // "key: 8 value: 80\nkey: 15 value: 150\nkey: 20 value: 200\n
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    string toString() {
        stringstream ss;
        _buildString(root, ss);
        return ss.str();
    }

    //
    // toVector:
    //
    // Returns a vector of the entire map, in order.  For 8/80, 15/150, 20/200:
    // {{8, 80}, {15, 150}, {20, 200}}
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    vector<pair<keyType, valueType>> toVector() {
        vector<pair<keyType, valueType>> v;
        _buildVector(root, v);
        return v;
    }

    //
    // checkBalance:
    //
    // Returns a string of mymap that verifies that the tree is properly
    // balanced.  For example, if keys: 1, 2, 3 are inserted in that order,
    // function should return a string in this format (in pre-order):
    // "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    string checkBalance() {
        stringstream ss;
        _checkBalance(root, ss);
        return ss.str();
    }
};
