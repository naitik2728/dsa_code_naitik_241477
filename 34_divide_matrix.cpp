// divide matrix 
// multipication of 2 matrixs
#include<iostream>
using namespace std;

int main(){
  int m,n;
  int a ; 
  cout<<"ENTER DIMENTIONS :";
  cin>>m>>n;

  cout<<"ENTER NUMBER : ";
  cin>>a;
  
  int arr3[m][n];

  for(int i =0 ; i<m ; i++){
    for(int j =0 ; j<n ; j++){
      cin>>arr3[i][j];
    }
  }

  

  for(int i1 = 0; i1<m; i1++){
    for(int j1 =0 ; j1<n ; j1++ ){
      arr3[i1][j1] =  arr3[i1][j1]/a ; 
    }
  }

  for(int i2 = 0 ; i2<m; i2++){
    for(int j2 = 0 ; j2<n ; j2++){
      cout<<arr3[i2][j2]<<" ";
    }
  }


  return 0;
}