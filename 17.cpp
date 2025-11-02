// 30/09/2025
// code for insertion  sort

#include<iostream>
using namespace std;


void insertion(int * arr , int n){

  int j ;
  for(int i = 1 ; i < n ; i++){
    int key = arr[i] ;
    j = i-1 ;

    while(j >= 0 && arr[j] > key){
      arr[j+1] = arr[j] ;
      j-- ;
    }
    arr[j+1] = key ;
  }
  return ;
}

void display(int * arr , int n ){
  for(int i = 0 ; i < n ; i++){
    cout<<arr[i]<<" ";
  }
  return ;
}
int main(){
  int arr[] = {4,5,3,2,6};

  int n = sizeof(arr)/sizeof(arr[0]) ;

  insertion(arr ,n);

  display(arr,n);
  return 0 ;
}