// stack using linked list 
// Linked list makes stack operations dynamic → No fixed size.
#include<iostream>
using namespace std ;

class node{
  public :
     int data ;
     node * next ;
} ;

class stack{
  node * top ;
  public : 
    stack(){    // constructor 
      top = NULL ;
    }
  
    bool isempty(){
      return top == NULL ;
    }

    // So the only time a linked-list stack becomes “full” is when the system cannot provide more memory (heap full).
    bool isfull() {
    node* temp = new(nothrow) node();
    if (temp == NULL)   // memory not allocated
        return true;
    delete temp;
    return false;
}

void push(int x){
   if(isfull()){  // overflow 
    return ;
   }
   node * temp = new node() ;
   temp->data = x ;
   temp->next = top ;
   top = temp ;
   return ;

}
int pop(){
   if(isempty()){  // underflow 
    return -1 ;
   }
   node * temp = top ;
   int x = temp->data ;
   top = top->next ;
   delete temp ;
   return x ;
}

int peek(){
  if(isempty()){
    return -1 ;
  }
  return top->data ;
}

void display(){
  if(isempty()){
    cout<<" STACK IS EMPTY !" ;
  }

  node * ptr = top ;
  cout<<" STACK ELEMENT IS - " ;

  while(ptr != NULL){
    cout<< ptr->data << " " ;
    ptr = ptr->next ;
  }
  cout<<endl ;
}
   

} ;
int main(){
  stack st ;
  st.push(10) ;
  st.push(20) ;
  st.push(30) ;
  st.push(40) ;

  st.display() ;

  cout<<" TOP ELEMENT IS : "<<st.peek()<< endl ;

  cout<<st.pop()<< " " ;
  
  st.display() ;

  return  0 ;
}