//  bubble sort 

#include<iostream>
using namespace std ;

void bubble_sort(int arr[] , int n){
  for(int i = n-1 ; i >= 0 ; i--){

    int didswap = 0 ;
    for(int j = 0 ; j <= i-1 ; j++){
      if(arr[j] > arr[j+1]){
        int temp = arr[j] ;  // swaping 
        arr[j] = arr[j+1] ;
        arr[j+1] = temp ;
        didswap = 1 ;
      }
    }

    if(didswap == 0){   // this case for less the timecomplexity , best tc == o(n)
      break ;
    }
  }
  return ;
}
int main(){
  int n ;
  cout<<"ENTER THE ARRAY DIMENTION :" ;
  cin>>n ;
  int arr[n] ;

  for(int i = 0 ; i < n ; i++){
    cin>>arr[i] ;
  }

  bubble_sort(arr , n) ;

  cout<<"THE SORTED ARRAY IS THROW BUBBLE SORT IS :"<<endl ;

  for(int i = 0 ; i < n ; i++){
    cout<<arr[i]<<" " ;
  }

  return 0 ;
}


// tc worst o(n2)
// sc o(1)