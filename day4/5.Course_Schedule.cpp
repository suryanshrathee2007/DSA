#include<iostream>
using namespace std ;
class Solution {
private:
    bool dfs(int node ,vector<vector<int>>&adj , vector<int>&visited ) {
        visited[node] = 1 ;

        for(auto itr : adj[node]) {
            if(visited[itr] == 0 ) {
                if(dfs(itr , adj , visited ) == true ) {
                    return true ;
                }

            }
            if(visited[itr] == 1 ) {
                return true ;
            }
        }
        visited[node] = 2 ; 
        return false ;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        vector<vector<int>>adj(numCourses) ;
        vector<int>visited(numCourses , 0 ) ;

        for(auto &itr : prerequisites ) {
            int u = itr[0] ;
            int v = itr[1] ;

            adj[v].push_back(u) ;

        }


        for(int i = 0 ; i<numCourses ; i++ ) {
            if(visited[i] == 0 ) {
                if(dfs(i , adj , visited ) == true ) {
                    return false ;
                }
            }
        }

        return true ;
    }
};
int main(){
    
    return 0 ;
}