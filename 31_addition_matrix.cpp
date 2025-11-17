// addition of two matrixs
#include<iostream>
using namespace std;
int main(){
  int m , n;
  cout<<"ENTER DIMENTIONS :";
  cin>>m>>n;
  int arr1[m][n];
  int arr2[m][n];
  int arr3[m][n];

  for(int i =0 ; i<m ; i++){
    for(int j =0 ; j<n ; j++){
      cin>>arr1[i][j];
    }
  }

  
  for(int i =0 ; i<m ; i++){
    for(int j =0 ; j<n ; j++){
      cin>>arr2[i][j];
      }
  }

  for(int i1 = 0; i1<m ; i1++){
    for(int j1 =0 ; j1<n ; j1++ ){
      arr3[i1][j1] = arr1[i1][j1] + arr2[i1][j1] ;
    }
  }

  for(int i2 = 0 ; i2<m ; i2++){
    for(int j2 = 0 ; j2<n ; j2++){
      cout<<arr3[i2][j2]<<" ";
    }
  }


  return 0;
}