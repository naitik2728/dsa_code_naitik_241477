#include<iostream>
using namespace std ;
struct Time{
  int h , m , s ;
};

struct Node{
  Time t ;
  Node * left , * right  ;
} ;

Node * createNode(Time t){
  Node * n = new Node() ;
  n->t = t ;
  n->left = n->right = NULL ;
  return n ;
}

Node * insertNode(Node * root , Time t){
  if(root == NULL){
    return createNode(t) ;
  }
  if(t.h < root->t.h){
    root->left = insertNode(root->left , t) ;
  }
  else{
    root->right = insertNode(root->right , t) ;
  }
  return root ;
}
void inorder(Node * root){
  if(root == NULL)
  return ;

  inorder(root->left) ;
  cout<< root->t.h << " : " << root->t.m << " : " << root->t.s << endl ;
  inorder(root->right) ;
}

int main(){
  Node * root = NULL ;
  root = insertNode(root, {10,20,30});
    root = insertNode(root, {5,10,0});
    root = insertNode(root, {15,0,10});
    root = insertNode(root, {12,30,45});
  return 0 ;

}