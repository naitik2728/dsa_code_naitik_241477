// creqate linked list throw function
#include <iostream>
#include <stdlib.h>  // malloc, free
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        cout << "Memory not allocated!" << endl;
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate nodes using function
    head = createNode(10);
    second = createNode(20);
    third = createNode(30);

    // link nodes
    head->next = second;
    second->next = third;
    third->next = NULL;

    // print list
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
   cout<<"NULL";

    return 0;
}
