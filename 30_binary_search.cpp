// in binary search tree atmost two element are present 
// left to right concept in binary search tree in not valid
// in binary search tree root node ka left child is smaller than root node and root nade ka right child grater than root node

// first two condition also for binary tree 

// no duplicates allow in bst
// duplicate allow in binary tree 

// insertion in bst

#include<iostream>
#include<queue>
using namespace std ;

  struct node{
    int data ;
    node * left ;
    node * right ;

    node(int val){
      data = val ;
      left = right = nullptr ;
    }
  } ; 


  node* insert(root * node , int val){
    node * newnode = new node(val) ;

    if(root == NULL){
      return nullptr ;
    }
    queue<node*> q ;
    q.push(root) ;

    while(!q.empty()){
      node * temp = q.front() ;
      q.pop() ;
    }

    if(temp->left == nullptr){
      temp->left = newnode ;
      return root ;
    }
    else {
      q.push(temp->left);
    }

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        }
        else {
            q.push(temp->right);
    }
    return root ;
  }
  int height(node * root){

    if(root == NULL){
      return 0 ;
    }
    int lh = height(root->left) ;
    int rh = height(root->right) ;

    return 1 + max(lh , rh) ;
  }

  int countnode(node * root){

    if(root == 0){
      return 0 ;
    }
    return 1 + countnode(root->left) + countnode(root->right) ;
  }

  bool search(node * root , int key){


    if(root == NULL){
      return false ;
    }

    if(root->data == key){
      return true ;
    }
    return search(root->left , key) || search(root->right , key) ;
  }

  void deletetree(node * root){

    if(root == NULL){
      return ;
    }
    deletetree(root->left) ;
    deletetree(root->right) ;

    delete root ;
    root = NULL ;
  }

  Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            delete root;
            return NULL;
        } else {
            return root;
        }
    }

    queue<Node*> q;
    q.push(root);

    Node* temp;
    Node* keyNode = NULL;

    // find keyNode & deepest node
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == key)
            keyNode = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    // if key not found
    if (keyNode != NULL) {
        int x = temp->data; // deepest node value
        deleteDeepest(root, temp); // delete deepest
        keyNode->data = x; // replace
    }

    return root;
}

int main(){

  node * root = NULL ;

  root.insert(root ,10) ;
  root.insert(root ,20) ;
  root.insert(root ,30) ;
  root.insert(root ,40) ;
  
  
  cout<<"height :"<<root.height(root)<<endl ;

  cout<<"cout node"<<root.countnode(root)<<endl ;
  
  cout<<"search it :"<<root.search(root ,30)<<endl ; 

  root.deletetree(root) ;
  return 0 ;
}