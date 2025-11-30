#include<iostream>
using namespace std ;
int main(){
  int n , m ;
  cin>>n>>m ;
  int adj[n+1][n+1] ; // we assume it is one indexing graph  // and whoel graph store here 
  // size of graph only depends on number of nofr and edges 

  /*int adj[n+1][n+1] = {0}; // you directly write that 
*/

  // initialize all to zero 
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
          adj[i][j] = 0;
      }
  }

  for(int i = 0; i < m ; i++){ // tc == o(n)
    // reun m times due to number of edges is m 
    int u , v ;
    cin>>u>>v ;
    adj[u][v] = 1 ;
    adj[v][u] = 1 ; // skip if it is undirected 
  }

  cout << "Adjacency Matrix:"<< endl ;

for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
        cout << adj[i][j] << " ";
    }
    cout << endl;  
}
  return 0 ; 
}


/*

tc == o(1)
sc == o(n^2)

// why tc == o(1)

Because arrays are stored in continuous memory (contiguous).

The machine calculates the location of adj[u][v] like this:

base_address + (u * total_columns + v) * sizeof(int)


This calculation takes the same constant time always.

It does NOT depend on:

size of graph

number of edges

number of nodes*/