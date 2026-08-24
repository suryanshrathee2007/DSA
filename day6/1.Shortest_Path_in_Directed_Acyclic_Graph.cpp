#include<iostream>
using namespace std ;
class Solution {
private:
    void toposort(int node , vector<vector<pair<int,int>>>&adj , vector<int>&visited , stack<int>&st) {
        visited[node] = 1 ;
        
        for(auto &itr : adj[node]){
            int v = itr.first ;
            if(!visited[v]) {
                toposort(v , adj , visited , st ) ;
            }
            
        }
        
        st.push(node) ;
    }
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(V) ;
        for(int i = 0 ; i<edges.size() ; i++) {
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            int wt = edges[i][2] ;
            
            adj[u].push_back({v,wt}) ;
        }
        // our adjancy list is created 
        
        vector<int>visited(V,0) ;
        stack<int>st ;
        
        for(int i = 0 ; i<V ; i++){
            if(!visited[i]) {
                toposort(i , adj , visited , st) ;
            }
        }
        
        vector<int>dist(V , 1e9) ;
        dist[0] = 0 ;
        
        while(!st.empty()) {
            int node = st.top() ;
            st.pop() ;
            
            
            
            for(auto it : adj[node]) {
                int v = it.first ;
                int wt = it.second ;
                
                if(dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt ;
                }
            }
        }
        
        for(int i = 0 ; i<V ;i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1 ;
            }
        }
        return dist ;
    }
};

int main(){
    
    return 0 ;
}