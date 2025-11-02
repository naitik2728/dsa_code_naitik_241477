// deletion at front
#include<iostream>
using namespace std;

int deleteFront(int *a, int n) {
    for (int i = 0; i < n-1; i++) {
        a[i] = a[i+1];   // shift elements left
    }
    return n-1; // new size
}

int main() {
    int arr[10] = {1,2,3,4,5};  // capacity 10
    int n = 5;  // current size

    n = deleteFront(arr, n);

    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
