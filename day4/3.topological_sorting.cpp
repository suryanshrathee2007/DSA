#include<iostream>
using namespace std ;
class Solution {
    private :
    void dfs(int node , vector<vector<int>>&adj , vector<int>&visited , stack<int>&st ) {
        visited[node] = 1 ;
        
        for(auto itr : adj[node] ) {
            if(!visited[itr] ) {
                dfs(itr , adj , visited , st ) ;
            }
        }
        st.push(node) ;
        return ;
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V) ;
        for(int i = 0 ; i<edges.size() ; i++ ) {
            int u= edges[i][0] ;
            int v = edges[i][1] ;
            
            adj[u].push_back(v) ;
        }
        
        vector<int>visited(V,0) ;
        stack<int>st ;
        
        for(int i = 0 ; i<V ; i++ ) {
            if(!visited[i]) {
                dfs(i , adj , visited , st ) ;
            }
        }
        
        vector<int>ans ;
        while(!st.empty()) {
            int a = st.top() ;
            st.pop() ;
            ans.push_back(a) ;
        }
        
        return ans ;
        
    }
};
int main(){
    
    return 0 ;
}