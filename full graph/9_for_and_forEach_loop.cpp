#include<iostream>
#include<vector>
using namespace std ;

/*

#  Normal for loop → use index
#  For-each loop → direct value

*/

/*
for-each needs something like:

vector

array

string

set, map, etc.
*/

int main(){
  for(int i = 0 ; i < 5 ; i++){
    cout<<i<<" ";
  }

  cout<<endl ;

  // for each loop 

vector<int> nums = {0,1,2,3,4};

for(int x : nums){
    cout << x << " ";
}
  return 0 ;
}