// codde for stack
#include<iostream>
using namespace std ;

#define size 5
int stack[size] ; 
int top = -1 ;

bool isfull(){
  return top == size-1 ;
}
bool isempty(){
  return top == -1 ;
}
void push(int value){
  if(isfull()){
    return ;
  }
  stack[++top] = value ;
}

void pop(){
  if(isempty()){
    return  ; 
  }
  int value = stack[top--] ;
  return  ;
}
int peek(){
  if(isempty())
  return -1 ;

  return stack[top] ;
}

void display(){
  if(isempty()){
    cout<<" STACK IS FULL !"<<endl ;
    return ;
  }
  for(int i = top ; i >= 0  ; i--){
    cout<<stack[i]<<" " ;
  }
  return ;
}
int main(){
  

  push(10) ;
  push(20) ;
  push(30) ; 

  pop() ;

  display() ;
  return 0 ;
}