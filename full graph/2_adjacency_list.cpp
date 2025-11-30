/*
✔ Creates an array of vectors.
✔ adj[i] represents the list of neighbors of node i.

Why n+1?

Because graph uses 1-based indexing (nodes 1…n)*/

/*

Think of it like this:

adj[1] = { all neighbors of 1 }
adj[2] = { all neighbors of 2 }
adj[3] = { all neighbors of 3 }
...


Each index stores a dynamic list.

*/
#include<iostream>
#include<vector>
using namespace std ;
int main(){
  int n , m ;
  cin>>n>>m ;
  vector<int> adj[n+1] ; // due to 0 to 5
  // sc = o(2e) in case of directed graph o(e)
  // e is edge and memory take by adjacency list is 2*edge '
  // repeated m times → O(m) tc hee 

  for(int i = 0 ; i < m ; i++){ // tc == o(m)
    int u , v ;
    cin>>u>>v ;
    // we written two line due to this is undirected graph 
    adj[u].push_back(v) ;
    adj[v].push_back(u) ;
  }

  // print the list 

  cout<<endl ;
  cout<<" our list is :"<< endl ;

  for(int i = 1; i <= n; i++){
    cout << i << " -> ";
    for(int j = 0; j < adj[i].size(); j++){
        cout << adj[i][j] << " ";
    }
    cout << endl;
}

  return 0 ;
}