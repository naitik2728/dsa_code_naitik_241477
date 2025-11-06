// write the code for circular queue 
#include<iostream>
using namespace std ;

#define size 10 
int queue[size] ;
int front = -1 ;
int rear = -1 ;

bool isfull(){
  
    return ((rear + 1) % size == front ) ;
  
  
}
bool isempty(){
   
    return (front == -1) ;
  
}

void enqueue(int value){
   if(isfull()){
    return ;
   }
   if(isempty()){
    front = 0 ;
    rear = 0 ;
   }
   else{
    rear = (rear + 1)%size ;
   }

   queue[rear] = value ;
   return ;
}
int  dequeue(){

  if(isempty()){
    return ;
  }
  if(front == rear){
    front = -1 ;
    rear = -1 ;
    // only in one condition when 1 element present 
    
  }
  
    int value = queue[front] ;
    front = front+1 % size ;
  
  return value ;

}


int  peek(){
  if(isempty()){
    cout<<" queue is empty !" ;
    return -1 ;
     
  }
  return queue[front] ;
}
void display(){
   if(isempty()){
    cout<<"queue is empty !"<<endl ;
    return ;
   }
   for(int i = front ; i <= rear ; i++){
    cout<<queue[i]<<" ";
   }
   return ;
}
int main(){
  enqueue(10);
  enqueue(20);
  enqueue(30);

  cout<<dequeue();
  display();
  return 0 ;
}