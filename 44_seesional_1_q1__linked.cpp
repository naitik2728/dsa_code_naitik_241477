#include <iostream>
using namespace std;

struct Node {
    int h, m, s;
    Node *next;
};

Node* createClock(int hh, int mm, int ss) {
    Node* temp = new Node();
    temp->h = hh;
    temp->m = mm;
    temp->s = ss;
    temp->next = NULL;
    return temp;
}

void updateClock(Node* head, int ah, int am, int as) {
    // Add new values
    head->s += as;
    head->m += am + head->s / 60;
    head->s = head->s % 60;

    head->h += ah + head->m / 60;
    head->m = head->m % 60;

    head->h = head->h % 24; // 24-hour clock
}

void printClock(Node* head) {
    cout << "Time = " << head->h << ":" << head->m << ":" << head->s << endl;
}

int main() {
    Node* clock = createClock(10, 20, 30); // initial time
    printClock(clock);

    updateClock(clock, 2, 45, 50); // add 2h 45m 50s
    printClock(clock);

    return 0;
}
