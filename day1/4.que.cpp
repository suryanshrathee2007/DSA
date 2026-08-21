

// que=> 547. Number of Provinces

#include<iostream>
using namespace std ;
class Solution {
    private:
    void dfs(int node ,vector<int>adj[] ,vector<bool>&visited) {
        visited[node] = 1 ;

        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it , adj , visited ) ;
            }
            
        }
        return ;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;

        vector<int> adj[n] ;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j) ;
                    adj[j].push_back(i) ;
                }
            }
        }

        int ans = 0 ;
        vector<bool>visited(n) ;

        for(int i = 0 ;i<n ; i++){
            if(!visited[i]){
                ans++ ;
                dfs(i , adj , visited ) ;
            }
        }
        return ans ;
    }
};
int main(){
    
    return 0 ;
}
