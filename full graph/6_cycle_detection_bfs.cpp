#include<iostream>
#include<vector>
#include<vector>
#include<queue>
using namespace std ;

// tc == o(N + 2E)
// 2E come from adjacency lsit 

// sc== o(N)


/* You reach a node
 That is already visited
 And it is NOT your parent node*/


class Solution{
  public:

  bool bfsCheck(int start , vector<int> adj[] , vector<int> &vis){
    queue<pair<int,int>> q ;
    vis[start] = 1 ;

    q.push({start , -1}) ;

    while(!q.empty()){
      int node = q.front().first ;
      int parent = q.front().second ;
      q.pop() ;

      for(int k = 0 ; k < adj[node].size() ; k++){
        int child = adj[node][k] ;

        if(!vis[child]){
          vis[child] = 1 ;
          q.push({child , node}) ;
        }

        // if visited and not parent ->cycle 

        else if(child != parent){
              return true ;
        }
      }
    }
  }

  bool isCycle(int v , vector<int> adj[]){
    vector<int> vis(v , 0) ;

    for(int i = 0 ; i < v ; i++){
      if(!vis[i]){
        if(bfsCheck(i , adj ,vis)){
          return true ;
        }
      }
    }
  }

} ;

int main(){
  int v , e ;
  cout<<" ENTER NUMBER OF NODES AND EDGES :" ;
  cin>>v>>e ;

  vector<int> adj[v] ;

  cout<<"enter edges :" ;
  for(int i = 0 ; i < e ; i++){
    int u , v ;
    cin>> u >> v ;
    adj[u].push_back(v) ;
    adj[v].push_back(u) ;// undirected graph 
  }
  Solution obj ;


  return 0 ;
}