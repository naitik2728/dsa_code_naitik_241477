// traverse an array
#include<iostream>
using namespace std;

void traverse(int *a , int n){

  for(int i = 0 ; i < n ; i++){
    cout<<a[i]<<endl ;
  }
}
int main(){
  int arr[] = {1,2,3,4,5};
  int n ;
  n = sizeof(arr)/sizeof(arr[0]);
  traverse(arr,n);
  return 0 ;
}