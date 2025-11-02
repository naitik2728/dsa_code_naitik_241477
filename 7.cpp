// code for deletion in any point in array
#include<iostream>
using namespace std;
int  deletion(int *a , int n , int index){
    for(int i = index ; i < n ; i++){
     
      a[i] = a[i+1];
    }
    return n-1 ;
}
int main(){
  int arr[] = {1,2,3,4,5};
  int n = sizeof(arr)/sizeof(arr[1]);
  int index ;
  cout<<"Enter the index :";
  cin>>index ;
  int N = deletion(arr , n , index);
  for(int i = 0 ; i < N ; i++){
    cout<<arr[i]<<" ";
  }
  return 0 ; 
}