#include <iostream>
using namespace std;


struct node {
    int data;
    node* next;
};

node* head = NULL;   // global head 


//   Display Function 

void display() {
    node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


// Insert at Front 
void insertionFront(int value) {

    node* newNode = new node;
    newNode->data = value;
    newNode->next = head;   

    head = newNode;         // update head
}


// Insert at End 
void insertionEnd(int value) {

    node* newNode = new node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {     // if list empty
        head = newNode;
        return;
    }

    node* temp = head;

    // move to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;  // attach new node at end
}


// Insert After a Given Value 
void insertionAnyPoint(int afterValue, int newValue) {

    node* temp = head;

    // search for the value
    while (temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value " << afterValue << " not found!" << endl;
        return;
    }

    node* newNode = new node;
    newNode->data = newValue;

    newNode->next = temp->next;  // link new node
    temp->next = newNode;
}


// MAIN FUNCTION 
int main() {

    insertionFront(30);
    insertionFront(20);
    insertionFront(10);
    display();

    insertionEnd(40);
    insertionEnd(50);
    display();

    insertionAnyPoint(30, 25);   // insert 25 after 30
    display();

    return 0;
}
