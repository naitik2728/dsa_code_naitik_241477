#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
  int data;
  struct node *next;
};

struct node *deletefront(struct node *temp)
{

  if(temp == NULL){
    return NULL ;
  }
  temp = temp->next;
  return temp;
}

int main()
{
  struct node *n1 = (struct node *)malloc(sizeof(struct node));
  struct node *n2 = (struct node *)malloc(sizeof(struct node));
  struct node *n3 = (struct node *)malloc(sizeof(struct node));
  struct node *n4 = (struct node *)malloc(sizeof(struct node));

  n1->data = 10;
  n2->data = 20;
  n3->data = 30;
  n4->data = 40;

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = NULL;

  struct node *head = n1;

  struct node *start = deletefront(head);

  struct node *temp = start;
  while (temp != NULL)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }

  cout << "NULL" << endl;

  return 0;
}