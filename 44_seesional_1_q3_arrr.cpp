#include <iostream>
using namespace std;

class ReverseArray {
    int arr[20];
    int n;     // current size
    int start; // next position to insert (from right side)

public:
    ReverseArray(int size) {
        n = size;
        start = n - 1; // insert from last index
    }

    void insertion(int value) {
        if (start < 0) {
            cout << "Array full!\n";
            return;
        }
        arr[start] = value;
        start--;
    }

    void deletion() {
        if (start == n - 1) {
            cout << "Array empty!\n";
            return;
        }

        // element inserted first = at index (start+1)
        cout << "Deleted: " << arr[start + 1] << endl;

        // shift remaining elements left
        for (int i = start + 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--; // reduce size
    }

    void display() {
        cout << "Array: ";
        for (int i = start + 1; i < start + 1 + n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    ReverseArray obj(5);

    obj.insertion(10);
    obj.insertion(20);
    obj.insertion(30);

    obj.display();

    obj.deletion();
    obj.display();

    return 0;
}
