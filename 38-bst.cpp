#include<iostream>
#include<queue> // for level order traversal 
using namespace std ;

// tc for insertion same as binary search o(logn)
// tc for search o(logn)
// if tree ek hi direction me jaa raha hee then o(n) for search
// sc for search through recursion o(n) ;
// we also perform searching without recursion sothat sc is o(1)



// inorder is always sorted in BST   


//  inorder redecessor 
//  mean in case of inorder we have node 30 , usse pahle jo aayega vo nikalo 
//  inorder succesor 
//  which node after the 30 


class Node {
   
  public:
  int data ;
  Node * left ;
  Node * right ;

  Node(int d){
    this->data = d ;
    this->left = NULL ;
    this->right = NULL ;

  }
} ;


////////////////////////////////////////////////////////

Node * insertIntoBST(Node * root , int d){

  if(root == NULL){
    root = new Node(d) ;
      return root ;
  }

  if(d > root -> data){
    // right part me insert karo 
    root->right = insertIntoBST(root->right , d) ;
  }
  else{
    // left part me insert karo 
    root->left = insertIntoBST(root->left , d) ;
  }
  return root ;
}

void takeInput(Node * &root){ // its call root by reference 

  // we use root by refernece due to , if we are not use this then the root of main still null , and ye starting me hi change kar rahe he to baki ke function me no require of reference root 
  int data ;
  cin>> data ;
 
  while(data != -1){ // mean me jab tak -1 naa pass kar duu 

    root = insertIntoBST(root , data) ;
      cin>> data ;
    

  }
}

//////////////////////////////////////////////////////////////

// level order traversal  for print the element 
void levelOrderTraversal(Node * root){
  queue<Node*> q ;
  q.push(root) ;
  
  while(!q.empty()){
    Node * node = q.front() ;
    q.pop() ;
    
    cout<<node->data<<" " ;

    if(node->left) 
    q.push(node->left) ;

    if(node->right)
    q.push(node->right) ;
  }

}

///////////////////////////////////////////////////////////////

// inorder follows left root right

void inorderTraversal(Node * root){

  if(root == NULL)
  return ;

  
  inorderTraversal(root->left) ;
  cout<<root->data<<" " ;
  inorderTraversal(root->right) ;

  return ;
}

//////////////////////////////////////////////////////////////

// preorder foolows  root left right

void preorderTraversal(Node * root){
  if(root == NULL)
  return ;

  cout<<root->data<<" " ;
  preorderTraversal(root->left) ;
  preorderTraversal(root->right) ;

  return  ;
}

//////////////////////////////////////////////////////////////

// postorder follows left right root 

void  postorderTraversal(Node * root){
  if(root == NULL)
  return ;

  postorderTraversal(root->left) ;
  postorderTraversal(root->right) ;
  cout<<root->data<<" " ;

  return ;
}

//////////////////////////////////////////////////////////////

bool searchBST(Node * root , int x){

  if(root == NULL)
  return false ; // base case 

  if(root->data == x)
  return true ;

  if(root->data > x)
  // left part me jao 
  return searchBST(root->left , x) ;
  
  else{
    // right part me jao 
  return searchBST(root->right , x) ;
  }
}

bool searchBSTwithoutRecursion(Node * root , int x){
  // without recursion 

  Node * temp = root ;

  while(temp != NULL){
    if(temp->data == x)
    return true ;

    if(temp->data > x)
    temp = temp->left ;

    else
      temp = temp->right ;
    
  }
  return false ;
}

////////////////////////////////////////////////////////////////// 


// how to find minimum value of root in bst 

int minBST(Node * root){
  Node * temp = root ;
  while(temp->left != NULL){

      temp = temp->left ;
  }
  return temp->data ;
}


//////////////////////////////////////////////////////////////////

// find max value in bst 

int maxBST(Node * root){
  Node * temp = root ;
  while(temp->right != NULL){

    temp = temp->right ;
  }
  return temp->data ;
}

///////////////////////////////////////////////////////////////////

// deletion 
// too much important with respect of interview 
// algo says.........................

Node * deleteFromBST(Node * root , int val){

  // base case 
  if(root == NULL)
  return root ;

  if(root->data == val ){
    // 0 child 
    if(root->left == NULL && root->right == NULL){
      delete root ;
      return NULL ;
    }

    // 1 child 
    // left 

    if(root->left != NULL && root->right == NULL){
       Node * temp = root->left ; 
       delete root ;
       return temp ;
    }

    // right 
    if(root->left == NULL && root->right != NULL){
      Node * temp = root->right ;
      delete root ;
      return temp ;
    }

    // 2 child 
    if(root->left != NULL && root->right != NULL){


      // we have two options
      // pick min value from right 
      // pick max value from left
      int mini = minBST(root->right) ;
      root->data = mini ;
      root->right = deleteFromBST(root->right , mini) ;
      return root ;
    }
  }
  else if(root->data > val){
    // left part 

    root->left = deleteFromBST(root->left , val) ;
    return root ;
  }
  else{
    // right part me jao 
    root->left = deleteFromBST(root->left , val) ;
    return root ;
  }
}





int main(){

  Node * root = NULL ;

  cout<< " ENTER DATA TO CREATE BST :"<<endl ;
  takeInput(root) ;

  cout<<" printing the BST :" ;
  levelOrderTraversal(root) ; 
  cout<<endl ;

  cout<<" printing inorder :" ;
  inorderTraversal(root) ;
  cout<<endl ;


  cout<<" printing preorder :" ;
  preorderTraversal(root) ;
  cout<<endl ;

  cout<<" printing postorder : " ;
  postorderTraversal(root) ;
  cout<<endl ;

  bool a = searchBST(root , 5) ;
  cout<<a<<endl ;

  cout<<"min value is :"<<minBST(root)<<endl ;
  cout<<"max value is :"<<maxBST(root)<<endl ;
  

  return  0 ;
}