// merge sort 
// 07 - 10 - 2025 
#include<iostream>
#include<vector>
using namespace std ;

void merge(vector<int> &arr , int st , int mid , int end){
  vector<int> temp ;
  int i = st ;
  int j = mid+1 ;

  while(i <= mid && j <= end){
    if(arr[i] < arr[j]){
      temp.push_back(arr[i]) ;
      i++ ;
    }
    else{
      temp.push_back(arr[j]);
      j++ ;
    }
  }

  while(i <= mid){
    temp.push_back(arr[i]) ;
      i++ ;
  }
  while(j <= end){
    temp.push_back(arr[j]);
    j++ ;
  }

  for(int id = 0 ; id < temp.size() ; id++){

    arr[id + st] = temp[id] ;
  }

 
}

void mergesort(vector<int> &arr , int st , int end){
  if(end > st){
    int mid = st + (end - st)/2 ;

    mergesort(arr , st , mid); // left 
    mergesort(arr , mid+1 , end); // right 

    merge(arr , st , mid , end) ;
  }
}
int main(){
  vector<int> arr = {10,40,50,20,30};

  mergesort(arr , 0 , arr.size() - 1);


  for(int val : arr){
    cout<< val << " ";

  }

  /*for(int i = 0 ; i < arr.size() ; i++){
    cout<<arr[i]<<" " ;
  }
  cout<<endl ;*/

  return 0 ;
}