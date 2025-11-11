// heap is a complete binary tree 
// two type of heap present minheap and max heap 
// in max heap largest element present in tree as a root node 

///////////////////////////////////////////this is all for max heap///////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std ;
class heap{
  public :

  int arr[100] ;
  int size = 0 ;

  heap(){
    size = 0 ;
    arr[0] = -1 ;
  }


  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void insert(int val){// tc = o(log n)
    
    size = size + 1 ;
    int index = size ;
    arr[index] = val ;

    while(index > 1){
      int parent = index/2 ;

      if(arr[parent] < arr[index]){
        swap(arr[parent] , arr[index]) ;
        index = parent  ;
      }
      else{
        return ;
      }
    }

  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

  // delete function
  // 1 . swap first and last node  or a[1] = a[n]
  // 2 . remove last node 
  // 3 . propogate root node to its correct position

  void deletefromHeap(){           // we delete root node ! 
    if(size == 0){  // base condition 
      cout<< " NOTHING TO DELETE !" << endl ;
      return ;
    }

    arr[1] = arr[size] ; // step 1 
    size-- ;   // step 2 

    // take root node to its correct position 

    int i = 1 ;        // step 3 
    while(i <= size){
      int leftindex = 2*i ;
      int rightindex = 2*i + 1 ;

      if( leftindex < size && arr[i] < arr[leftindex] ){
        
        swap(arr[i] , arr[leftindex]) ;
        i = leftindex ;
      }
      if(rightindex < size && arr[i] < arr[rightindex]){

        swap(arr[i] , arr[rightindex]) ;
        i = rightindex ;
      }
      else{
        return ;
      }
      
    }
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void heapify(int arr[] , int n , int i){

    int largest = i ;
    int left = 2*i ;
    int right = 2*i + 1 ;

    if(left <= n && arr[largest] < arr[left]){
      largest = left ;
    }
    if(right <= n && arr[largest] < arr[right]){
      largest = right ;
    }

    if(largest != i){  
      swap(arr[i] ,arr[largest]) ;
      heapify(arr , n , largest) ;
    }

  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  void heapsort(int arr[] , int  n){

    int  size = n ;
    while(size > 1){
      swap(arr[size] , arr[1]) ;
      size-- ;
      heapify(arr, size, 1);
    }
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void print(){
    for(int i = 1 ; i <= size ; i++){

      cout<<arr[i]<<" " ;
    }
    cout<<endl ;
  }

} ;
int main(){
  heap h ;
  h.insert(30) ;
  h.insert(35) ;
  h.insert(60) ;
  h.insert(5) ;
  h.insert(40) ;
  h.print() ;

  h.deletefromHeap() ;
  h.print() ;

  // we put -1 at index 0 due to we consider 0th index is blank 

  int arr[6] = { -1 , 54 , 53 , 55 , 52 ,50 } ;  
  int n = 5 ;
 
  // heap creation
  for(int i = n/2 ; i >= 1 ; i--){
   
    h.heapify(arr , n , i) ;  // o(n)

  }

  cout<<" NOW WE PRINT THE ARRAY :"<<endl ;

  for(int i = 1 ; i <=n ; i++){
    cout<<arr[i]<<" " ;
  }
  cout<<endl ;
 

  // heapsort 

  h.heapsort(arr , n) ;
  
  cout<<" NOW WE PRINT THE SORTED ARRAY :"<<endl ;

  for(int i = 1 ; i <=n ; i++){
    cout<<arr[i]<<" " ;
  }
  cout<<endl ;
  return 0 ;
}