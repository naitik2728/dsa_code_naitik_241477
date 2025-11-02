// insertion at the end in array 
/*#include<iostream>
using namespace std ;

void insertionend(int*a , int &n , int value){
  a[n] = value ;
  n = n + 1 ;

  return ;
  
}
int main(){
  int arr[10] = {1,2,3,4,5};
  int n = sizeof(arr)/sizeof(arr[0]);

  int value ;
  cout<<"Enter the value :";
  cin>>value ;

  insertionend(arr , n , value);

  for(int i = 0 ; i < n ; i++){
    cout<<arr[i]<<" ";
  }
  return 0 ;
}*/
#include<iostream>
using namespace std;

void insertionend(int* a , int &n , int value){
    a[n] = value;   // put new value at next index
    n = n + 1;      // update size
}

int main(){
    int arr[10] = {1,2,3,4,5}; // capacity 10, but only 5 used
    int n = 5;  // current size

    int value;
    cout << "Enter the value: ";
    cin >> value;

    insertionend(arr , n , value);

  
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
