#include<iostream>
using namespace std ;

class Solution {
    private :
        bool dfs(int start , vector<vector<int>>&adj , vector<int>&vis , vector<int>&pathvis ) {
            vis[start] = 1 ;
            pathvis[start] = 1 ;
            
            for(auto itr : adj[start]) {
                if(!vis[itr] ) {
                    if(dfs(itr,adj , vis ,pathvis ) == true ) {
                        return true ;
                    }
                }
                else if (pathvis[itr] == 1 ) {
                    return true ;
                }
            }
            pathvis[start] = 0 ;
            return false ;
        }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
    
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            
        }
        
        vector<int>vis(V,0) ;
        vector<int>pathvis(V,0) ;
        
        for(int i = 0 ; i<V ; i++ ) {
            if(!vis[i] ) {
                if(dfs(i , adj  , vis, pathvis ) == true ) {
                    return true ;
                } 
            }
        }
        return false ;
         
    }
};
int main(){
    
    return 0 ;
}