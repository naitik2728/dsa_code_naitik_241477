// code for queue
#include<iostream>
using namespace std ;

#define size 5 
int queue[size];
int front = -1 ;
int rear = -1 ;

bool isfull(){
  if(rear == size-1){
    return true ;
  }
  else{
    return false ;
  }
}
bool isempty(){
  if(front == -1 ||  front > rear){
    return true ;
  }
  else{
    return false ;
  }
}
void enqueue(int value){
  if(isfull()){
    return  ;
  }
  if(front == -1){
    front = 0 ;
  }
  rear++ ;
  queue[rear] = value ;
  return  ;
}
int dequeue(){
  if(isempty()){
    return  ;
  }
  // we consider those elements which inbetween in front and rear 
  int val = queue[front] ;
  front++ ;
  if(front > rear){
    front = rear = -1 ;
  }
  return val ;
}

int peek(){
  if(isempty()){
    return -1 ;
  }
  return queue[front] ;
}

void display(){
  if(isempty()){
    cout<<"queue is empty !" ;
    return ;
  }
  for(int i = front ; i <= rear ; i++){
    cout<<queue[i]<<" ";
  }
  
}

int main(){
  
  enqueue(10) ;
  enqueue(20) ;
  enqueue(30) ;
  enqueue(40);
  cout<<dequeue();
  cout<<dequeue();

  cout<<peek()<<endl ; // for find front element 

  display() ;
  return 0 ;
}