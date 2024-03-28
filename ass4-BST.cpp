// Write a menu driven C++ program to construct a binary search tree by insertNewNodeing the values in the order give, considering at the beginning with an empty binary search tree, After constructing a binary tree- 
// i. InsertNewNode new node, 
// ii. Find number of nodes in longest path from newNode, 
// iii. Minimum value value found in the tree 
// iv. Search a value 
// v. Print values in ascending and descending order

#include<iostream>
using namespace std;

class Node {
    public:
        int value;
        Node *right;
        Node *left;
};

class BST {
    Node *root = new Node;
    Node *key;
    public:
        void getRoot(int data) {
            root->value = data;
            root->left = NULL;
            root->right = NULL;
            cout<< "root is set to " << data << endl;
        }

        void insertNewNode(int data) {
            key = root;
            Node *newNode = new Node;
            while (true) {
                if (data > key->value) {
                    if (key->right == NULL) {
                        key->right = newNode;
                        newNode->value = data;
                        newNode->left = NULL;
                        newNode->right = NULL;
                        cout<<"node("<<data<<") inserted successfully"<<endl;
                        return;
                    }
                    key = key->right;
                }
                else {
                    if (key->left == NULL) {
                        key->left = newNode;
                        newNode->value = data;
                        newNode->left = NULL;
                        newNode->right = NULL;
                        cout<<"node("<<data<<") inserted successfully"<<endl;
                        return;
                    }
                    key = key->left;
                }
            }
        }

        void longestPath() {
            int pathLenL = 0;
            int pathLenR = 0;
            key = root;
            while (key->left != NULL) {
                key = key->left;
                pathLenL++;
            }
            key = root;
            while (key->right != NULL) {
                key = key->right;
                pathLenR++;
            }
            if (pathLenL > pathLenR) {
                key = root;
                cout<<endl<<"longest path is of "<<pathLenL + 1<<" nodes"<<endl;
                while (key->left != NULL) {
                    cout<< key->value <<" -> ";
                    key = key->left;
                }
                cout<< key->value << endl;
            }
            else {
                key = root;
                cout<<endl<<"longest path is of "<<pathLenR + 1<<" nodes"<<endl;
                while (key->right != NULL) {
                    cout<<key->value << " -> ";
                    key = key->right;
                }
                cout<< key->value << endl;
            }
        }

        void minValue() {
            key = root;
            while (key->left != NULL) {
                key = key->left;
            }
            cout<<endl<< "Minimum value: " << key->value << endl;
        }

        void searchNode(int data) {
            key = root;
            while (true) {         
                if (data > key->value) {
                    if (key->right == NULL) {
                        cout<< endl << data << " isn't present in the tree" <<endl ;
                        return;
                    }
                    key = key->right;
                }
                else if (data < key->value) {
                    if (key->left == NULL) {
                        cout<< endl << data << " isn't present in the tree" <<endl ;
                        return;
                    }
                    key = key->left;
                }
                else {
                    cout<< endl << data << " is present in the tree" << endl;
                    return;
                }
            }
        }

        void acsOrder() {
            int ascArray[12];
            key = root;
        }
};

int main() {
    BST obj;
    obj.getRoot(38);

    obj.insertNewNode(45);
    obj.insertNewNode(36);
    obj.insertNewNode(67);
    obj.insertNewNode(21);
    obj.insertNewNode(33);
    obj.insertNewNode(9);

    obj.longestPath();

    obj.minValue();

    obj.searchNode(67);

    return 0;
}
