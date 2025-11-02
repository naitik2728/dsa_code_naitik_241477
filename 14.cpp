#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
  int data ;
  struct node* next ;
};

struct node* deletelast(struct node*head){
  
   if (head == NULL) {
        cout << "linked list is empty." << endl;
        return NULL;
    }

   
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

int main(){
  struct node * n1 = (struct node*)malloc(sizeof(struct node));
  struct node * n2 = (struct node*)malloc(sizeof(struct node));
  struct node * n3 = (struct node*)malloc(sizeof(struct node));
  struct node * n4 = (struct node*)malloc(sizeof(struct node));

  n1->data = 10 ;
  n2->data = 20 ;
  n3->data = 30 ;
  n4->data = 40 ;

  n1->next = n2 ;
  n2->next = n3 ;
  n3->next = n4 ;
  n4->next = NULL ;

  struct node * head = n1 ;

  struct node *start = deletelast(head);


  struct node *temp = start ;
  while(temp != NULL){
    cout<<temp->data<<" -> ";
    temp = temp->next ;
  }

  cout<<"NULL"<<endl ;

  return 0;
}