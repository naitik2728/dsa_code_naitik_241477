#include<iostream>
#include<vector>
using namespace std ;

vector<vector<int>> adj ; // adjacency list 
vector<int> visited ; // visited array

// now we create dfs function

void dfs(int node){
  visited[node] = 1 ;
  cout<< node << " " ;

  for(int child : adj[node]){
   
    if(!visited[child]){
      dfs(child) ;
    }
  }

  /* for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if (!visited[child]) {
            dfs(child);
        }
    }*/
}

// function for take graph input 
void takeInput(int n , int m){
  adj.assign(n+1 , vector<int>()) ;
  visited.assign(n+1 , 0) ;

  for(int i = 0 ; i < m ; i++){
    int u , v ;
    cin>>u>>v ;
    adj[u].push_back(v) ;
    adj[v].push_back(u) ; // remob=ve if it is directed graph
  }
}
 int main(){

  cout<<"ENTER THE NODE AND EDGE :" ;
  int n ,m ;
  cin>>n>>m ;
  takeInput(n , m) ;
  
  cout<<"ENTER THE STARTING NODE : " ;
  int start ;
  cin>> start ;
  cout<<"dfs order :" ;

  dfs(start) ;
  
  return  0 ;
 }