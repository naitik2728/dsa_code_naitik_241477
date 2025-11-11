//  A Binary Tree is a tree data structure where each node has at most two children,

#include <iostream>
#include <queue>
using namespace std;

//-----------------------------------------------------
// Node structure
//-----------------------------------------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//-----------------------------------------------------
// INSERT (Level Order)
//-----------------------------------------------------
Node* insertNode(Node* root, int val) {
    Node* newNode = new Node(val);

    if (root == NULL)
        return newNode;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        }
        else
            q.push(temp->left);

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        }
        else
            q.push(temp->right);
    }
    return root;
}

//-----------------------------------------------------
// PREORDER (Root -> Left -> Right)
//-----------------------------------------------------
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//-----------------------------------------------------
// INORDER (Left -> Root -> Right)
//-----------------------------------------------------
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//-----------------------------------------------------
// POSTORDER (Left -> Right -> Root)
//-----------------------------------------------------
void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//-----------------------------------------------------
// LEVEL ORDER (BFS)
//-----------------------------------------------------
void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
}

//-----------------------------------------------------
// HEIGHT OF TREE
//-----------------------------------------------------
int height(Node* root) {
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}

//-----------------------------------------------------
// COUNT NODES
//-----------------------------------------------------
int countNodes(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

//-----------------------------------------------------
// SEARCH
//-----------------------------------------------------
bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key) return true;

    return search(root->left, key) || search(root->right, key);
}

//-----------------------------------------------------
// DELETE TREE (Free memory)
//-----------------------------------------------------
void deleteTree(Node* &root) {
    if (root == NULL) return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
    root = NULL;
}

//-----------------------------------------------------
// MAIN FUNCTION (Testing all)
//-----------------------------------------------------
int main() {

    Node* root = NULL;

    // insert nodes
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Level Order: ";
    levelOrder(root);
    cout << endl;

    cout << "Height: " << height(root) << endl;
    cout << "Total Nodes: " << countNodes(root) << endl;

    cout << "Search 30: " << (search(root, 30) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (search(root, 90) ? "Found" : "Not Found") << endl;

    deleteTree(root);
    cout << "Tree deleted!";

    return 0;
}
