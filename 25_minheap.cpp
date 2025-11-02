#include<iostream>
using namespace std ;

class heap{
  public :
    
  void heapify(int arr[] , int n , int i ){
    
    int smallest = i ;
    int left = 2*i + 1 ;
    int right = 2*i + 2 ;

    if(left < n && arr[smallest] > arr[left]){

      smallest = left ;
    }
    if(right < n && arr[smallest] > arr[right]){
     
      smallest = right ;
    }
    if(smallest != i){
      swap(arr[smallest] , arr[i]) ;
      heapify(arr , n , smallest) ;
    }
  }

  void print(int arr[] , int  n){
    for(int i = 0 ; i < n ; i++){
      cout<<arr[i]<<" " ;

    }
    cout<<endl ;
  }
} ;
int main(){
  heap h ;
  int arr[] = {2,3,5,6,1} ;
  int n = 5 ;
  for(int i = n/2 -1 ; i >= 0 ; i--){
    h.heapify(arr , n , i) ; 
  }
   h.print(arr , n ) ;
  return 0 ;
}