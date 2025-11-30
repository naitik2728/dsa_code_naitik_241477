#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

vector<vector<int>> adj ; //
vector<int> visited ; // create visited array 


void bfs(int start){
  queue<int> q ;
  q.push(start) ;
  visited[start] = 1 ;

  cout<<" BFS ORDER :" ;

  while(!q.empty()){
    int node =  q.front() ;
    q.pop() ;
    cout<<node <<" " ;

    for(int child : adj[node]){
      if(!visited[child]){
        visited[child] = 1 ;
        q.push(child) ; 
      }
    }
   }
   cout<<endl ;
}

void takeInput(int n , int m){
  adj.assign(n+1 , vector<int>()) ; //////////////////////////////////////////////////////
  visited.assign(n+1 , 0) ;  ////////////////////////////////////////////////////////////

  for(int i = 0 ; i < m ; i++){
    int u , v ;
    cin>>u>>v ;
    adj[u].push_back(v) ;
    adj[v].push_back(u) ; // we remove it if it is directed graph 
  }
}
 int main(){

  int n , m ;
  cin>> n >> m ;

  takeInput(n , m) ;

  cout<<"provide starting node :" ;
  int start ;
  cin>> start ;
  bfs(start) ;
  
  return 0 ;
 }