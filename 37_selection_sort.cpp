// selection sort
#include<iostream>
using namespace std ;

void selection_sort(int arr[] , int n){


  for(int i = 0 ; i <= n-2 ; i++){
    int min = i ;
    for(int j = i ; j < n ; j++){
      if(arr[j] < arr[min]){
        min = j ;
      }
    }
    swap(arr[min] , arr[i]) ;
  }
}
int main(){
  int n ;
  cout<<"PASS ARRAY DIMENTION :";
  cin>>n ;
  int arr[n] ;
  for(int i = 0 ; i < n ; i++){
    cin>>arr[i] ;
  }
  selection_sort(arr , n) ;

  cout<<"PRINT THE SORTED ARRAY THROW SELECTION SORT :" ;
  for(int i = 0 ; i < n ; i++){
    cout<<arr[i]<<" " ;
  }

  return 0 ;
}


// time complexity o(n2)
// space somplexity o(1)