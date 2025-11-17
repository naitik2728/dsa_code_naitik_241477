// insertion at middle in array

#include<iostream>
using namespace std ;

void insertion(int*a , int n , int index , int value){
  for(int i = n-1 ; i >= index ; i--){
    a[i+1] = a[i] ;
  }
  a[index] = value ;
  return ;
}
int main(){
  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(a[0]) ;
  int index ;
  int value ;

  cout<<"enter index :";
  cin>>index;

  cout<<"enter value :";
  cin>>value ;

  insertion(a , n , index , value);

  for(int i =0 ; i <= n ; i++){
    cout<<a[i]<<endl ;
  }

  return 0 ;
}