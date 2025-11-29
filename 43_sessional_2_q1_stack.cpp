#include <iostream>
using namespace std;

struct Time {
    int h, m, s;
};

class Clock {
    Time current;
    Time history[10];  // stack of last 10 updates
    int top;           // stack pointer

public:
    Clock(int hh=0, int mm=0, int ss=0) {
        current = {hh, mm, ss};
        top = -1;
    }

    void print() {
        cout << "Current Time = "
             << current.h << ":" 
             << current.m << ":" 
             << current.s << endl;
    }

    // Store old time + update to new time
    void pushUpdate(int hh, int mm, int ss) {
        // push current time into stack
        if (top < 9) {
            top++;
            history[top] = current;
        } else {
            // If stack full → shift left & add at end
            for (int i = 0; i < 9; i++) {
                history[i] = history[i+1];
            }
            history[9] = current;
        }

        // set new time
        current = {hh, mm, ss};
        cout << "Updated to: " << hh << ":" << mm << ":" << ss << endl;
    }

    // Undo = pop from stack
    void undoUpdate() {
        if (top == -1) {
            cout << "No previous time to undo!" << endl;
            return;
        }

        current = history[top];
        top--;
        cout << "Undo done. Restored: "
             << current.h << ":" 
             << current.m << ":" 
             << current.s << endl;
    }
};

// Example
int main() {
    Clock c(10, 20, 30);

    c.print();
    c.pushUpdate(11, 0, 0);
    c.pushUpdate(12, 15, 45);
    c.pushUpdate(23, 59, 59);

    c.undoUpdate();  // goes back to 12:15:45
    c.print();

    return 0;
}
