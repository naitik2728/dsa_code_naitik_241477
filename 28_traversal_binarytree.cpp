// preorder traversal root + left + right 
// inordertraversal  left + root + right
// postorder traversal left + right + root 





#include <iostream>
using namespace std;
#include<queue> // for dynamic queue

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder Traversal
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";   // Visit Root
    preorder(root->left);        // Traverse Left
    preorder(root->right);       // Traverse Right

   
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);      // Traverse Left
    cout << root->data << " "; // Visit Root
    inorder(root->right);     // Traverse Right

    
}


void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);    // Traverse Left
    postorder(root->right);   // Traverse Right
    cout << root->data << " "; // Visit Root

    
}

void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}


int main() {
    // Creating tree manually
    Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

 


    preorder(root);  // 10, 20, 40, 50, 30
     cout<<endl ;
    inorder(root) ;  // 40 ,20 , 50 , 10 , 30
     cout<<endl ;
    postorder(root) ; // 40 50 20 30 10
     cout<<endl ;
    levelOrder(root) ;
     cout<<endl ;


    return 0;
}
