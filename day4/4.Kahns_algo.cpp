#include<iostream>
using namespace std ;
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int>indegree(V,0) ;
        
        vector<vector<int>>adj(V) ;
        
        for(int i = 0 ; i<edges.size() ; i++ ) {
            int u = edges[i][0] , v = edges[i][1] ;
            adj[u].push_back(v) ;
            
            
            indegree[v]++ ;
        }
        
        queue<int>q ;
        for(int i = 0 ; i<V ; i++)  {
            if(indegree[i] == 0 ) {
                q.push(i) ;
            }
        }
        
        vector<int>ans ;
        while( !q.empty() ) {
            int node = q.front() ;
            q.pop() ;
            ans.push_back(node) ;
            
            for(auto itr : adj[node]) {
                indegree[itr]-- ;
                
                if(indegree[itr] == 0 ) {
                    q.push(itr) ;
                }
            }
        }
        return ans ;
        
        
    }
};

int main(){
    
    return 0 ;
}