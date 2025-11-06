// either 0 or 2 children  == full binary tree
// all level are completely filled except the last level , fill from left to right == complete binary tree 

/// binary tree representation throw linked list



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

class BinaryTree {
public:
    int arr[100];
    int size;

    BinaryTree() {   // constructor 
       size = 0; 
      }  

    void insert(int value) {
        arr[size] = value;
        size++;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    
    Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    cout << "Root: " << root->data << endl;
    cout << "Left child of root: " << root->left->data << endl;
    cout << "Right child of root: " << root->right->data << endl;

    


////   binary tree representation throw array///////////////////////////////////////////////////////////////////////////




 BinaryTree t;  // make the object 
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);

    t.display();
   
    return 0 ;
}   
