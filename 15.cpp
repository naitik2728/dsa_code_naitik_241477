// deletion at middle

#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
  int data ;
  struct node* next ;
};

struct node* deletion(struct node *head , int value){

  struct node * temp = head ;
  while(temp!= NULL){
    if(temp->next->data == value ){
         temp->next = temp->next->next ;
         break ;
    }
    temp = temp->next ;
  }

  return head ;
}
int main(){

  struct node*n1 = (struct node*)malloc(sizeof(struct node));
  struct node*n2 = (struct node*)malloc(sizeof(struct node));
  struct node*n3 = (struct node*)malloc(sizeof(struct node));
  struct node*n4 = (struct node*)malloc(sizeof(struct node));

  n1->data = 10 ;
  n2->data = 20 ;
  n3->data = 30 ;
  n4->data = 40 ;

  n1->next = n2 ;
  n2->next = n3 ;
  n3->next = n4 ;
  n4->next = NULL;

  int value =   20 ;

  struct node*head = n1 ;

  struct node* start = deletion(head,value);


  struct node *temp = start ;
  while(temp!=NULL){
    cout<<temp->data<<" -> ";
    temp = temp->next ;
  }
  cout<<" NULL "<<endl;

  return 0;
}