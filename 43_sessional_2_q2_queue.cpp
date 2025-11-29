#include <iostream>
using namespace std;

struct Time {
    int h, m, s;
};

class Queue {
    Time arr[20];
    int front, rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(Time t) {
        if (rear == 19) {
            cout << "Queue full!\n";
            return;
        }
        rear++;
        arr[rear] = t;
    }

    bool isEmpty() {
        return front > rear;
    }

    Time dequeue() {
        Time t = arr[front];
        front++;
        return t;
    }
};

class Clock {
    Time current;
public:
    Clock(int h=0,int m=0,int s=0) {
        current = {h,m,s};
    }

    void applyUpdate(Time t) {
        current = t;
        cout << "Clock updated to: "
             << current.h << ":" 
             << current.m << ":" 
             << current.s << endl;
    }

    void print() {
        cout << "Current Clock: "
             << current.h << ":" 
             << current.m << ":" 
             << current.s << endl;
    }
};

// Apply all updates (FIFO Order)
void applyUpdates(Clock &clk, Queue &q) {
    while (!q.isEmpty()) {
        Time t = q.dequeue();
        clk.applyUpdate(t);
    }
}

int main() {
    Clock clk(6,0,0);
    clk.print();

    Queue q;
    q.enqueue({6,30,0});
    q.enqueue({7,0,0});
    q.enqueue({12,15,10});
    q.enqueue({18,45,5});

    cout << "\nApplying Queue Updates:\n";
    applyUpdates(clk, q);

    cout << "\nFinal Clock Time:\n";
    clk.print();

    return 0;
}
