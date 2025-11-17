// insertion in front 
#include<iostream>
//#include<vector>
using namespace std ;

void insertionfront(int *a , int& n , int value){
  for(int i = n ; i>0 ; i--){
    a[i] = a[i-1];

  }
  a[0] = value ;
  n = n+1 ;
}
int main(){
  int arr[10] = {1,2,3,4,5};
  int n = 5 ; // current size
  //cout<<arr.size(); 
  
  int value ;
  cout<<"enter the value";
  cin>>value ;

  insertionfront(arr , n , value);

  for(int i = 0 ; i < n ; i++){
    cout<<arr[i]<<" ";
  }
  return 0 ;
}