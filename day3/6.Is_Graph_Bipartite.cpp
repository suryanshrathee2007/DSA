#include<iostream>
using namespace std ;
/*
class Solution {
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
      
        vector<int>color(n,-1) ;

        for(int i = 0 ; i<n ; i++ ) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto it : graph[node]) {
                        if (color[it] == -1) {
                            color[it] = !color[node];
                            q.push(it);
                        }
                        else if (color[it] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        
        
        return true ;
    }
}; */

class Solution {
    bool dfs(int start , vector<vector<int>>& graph  , vector<int>&color  ) {
        
        for(auto itr : graph[start] ) {
            if(color[itr] == -1 ) {
                color[itr] = !color[start] ;
                if( dfs(itr,graph,color) == false ){
                    return false ;
                }
            }
            else if(color[itr] == color[start] ) {
                return false ;
            }
        }
        return true ;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;

        vector<int>color(n,-1) ;
        bool ans ; 

        for(int i = 0 ; i<n ; i++ ) {
            if(color[i] == -1 ) {
                color[i] = 0 ;
                ans = dfs( i , graph , color ) ; 
                if(ans == false) {
                    return ans ;
                    
                }
            }
        }
        return ans ;
    }
};

int main(){
    
    return 0 ;
}
