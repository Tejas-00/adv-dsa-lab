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
    Node *key;
    int orderedList[20];
    int listIndex = 0;
    public:
        void getRoot(Node *root, int data) {
            root->value = data;
            root->left = NULL;
            root->right = NULL;
            cout<< "root is set to " << data << endl;
        }

        void insertNewNode(Node *root, int data) {
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

        void longestPath(Node *root) {
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

        void minValue(Node *root) {
            key = root;
            while (key->left != NULL) {
                key = key->left;
            }
            cout<<endl<< "Minimum value: " << key->value << endl;
        }

        void searchNode(Node *root, int data) {
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

        void inorderTraversal(Node *root) {
            if (root == nullptr) {
                return;
            }

            inorderTraversal(root->left);
            
            orderedList[listIndex] = root->value;
            listIndex++;
            
            inorderTraversal(root->right);
        }

        void AscDesc() {
            cout<< endl << "Ascending order" << endl;
            for (int i = 0; i < listIndex; i++) {
                cout<< orderedList[i] << " ";
            }

            cout<< endl << "Descending order" << endl;
            for (int i = listIndex - 1; i >= 0; i--) {
                cout<< orderedList[i] << " ";
            }
        }
};

int main() {
    Node *root = new Node;

    BST obj;

    obj.getRoot(root, 38);

    obj.insertNewNode(root, 45);
    obj.insertNewNode(root, 36);
    obj.insertNewNode(root, 67);
    obj.insertNewNode(root, 21);
    obj.insertNewNode(root, 33);
    obj.insertNewNode(root, 9);

    obj.longestPath(root);

    obj.minValue(root);

    obj.searchNode(root, 67);

    obj.inorderTraversal(root);

    obj.AscDesc();

    return 0;
}
