// traverse of array using recursion
#include<iostream>
using namespace std;

void traverse(int*a , int n , int i){
  if(i == n){
    return ;
  }
  else{
    cout<<a[i]<<endl ;
    traverse(a , n , i+1);
  }
}
int main(){
  int arr[] = {1,2,3,4,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  traverse(arr , n , 0);
  return 0;
}