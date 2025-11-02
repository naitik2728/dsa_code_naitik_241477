// deletion at end in array

#include<iostream>
using namespace std;

int deleteEnd(int *a, int n) {
   
    return n - 1; 
}

int main() {
    int arr[10] = {1,2,3,4,5};  
    int n = 5;  // current size

    n = deleteEnd(arr, n);

    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
