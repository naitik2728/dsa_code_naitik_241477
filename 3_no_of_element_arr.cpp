// code for find the number of element in array 
#include<iostream>
using namespace std;
int countelement(int *a , int n){
  int count = 0 ;
   for(int i = 0 ; i < n ; i++){
    if(a[i] == 0){
      break ;
    }
    else{
      count++;
    }
   }
   return count ;
}
int main(){
  int arr[] = {1,2,3,4,5,0};
  int n =sizeof(arr)/sizeof(arr[0]);
  cout<<n<<endl ;
  int count = countelement(arr , n);
  cout<<count<<endl ;
  return 0 ;
}