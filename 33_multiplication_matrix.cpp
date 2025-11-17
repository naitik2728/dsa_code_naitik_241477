// multipication of 2 matrixs
#include<iostream>
using namespace std;
int main(){
  int n;
  cout<<"ENTER DIMENTIONS :";
  cin>>n;
  int arr1[n][n];
  int arr2[n][n];
  int arr3[n][n];

  for(int i =0 ; i<n ; i++){
    for(int j =0 ; j<n ; j++){
      cin>>arr1[i][j];
    }
  }

  
  for(int i =0 ; i<n ; i++){
    for(int j =0 ; j<n ; j++){
      cin>>arr2[i][j];
      }
  }

  for(int i1 = 0; i1<n; i1++){
    for(int j1 =0 ; j1<n ; j1++ ){
      arr3[i1][j1] = 0;
      for(int k =0 ; k<n ; k++){
        arr3[i1][j1] = arr3[i1][j1] + arr1[i1][k]*arr2[k][j1];
      }
    }
  }

  for(int i2 = 0 ; i2<n; i2++){
    for(int j2 = 0 ; j2<n ; j2++){
      cout<<arr3[i2][j2]<<" ";
    }
  }


  return 0;
}