#include<iostream>
using namespace std ;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses) ;
        vector<int>indegree(numCourses , 0 ) ;

        for(auto &itr : prerequisites ) {
            int u = itr[0] ;
            int v = itr[1] ;

            adj[v].push_back(u) ;
            indegree[u]++ ;

        }

        queue<int>q ;
        for(int i = 0 ; i<numCourses ; i++ ) {
            if(indegree[i] == 0 ) {
                q.push(i) ;
            }
        }

        vector<int>ans ;

        while(!q.empty()) {
            int node = q.front() ;
            q.pop() ;
            ans.push_back(node) ;

            for(int itr : adj[node]) {
                indegree[itr]-- ;

                if(indegree[itr] == 0 ) {
                    q.push(itr) ;
                }
            }
        }

        if(ans.size() == numCourses ) {
            return ans ;
        }
        else{
            return {} ;
        }

    }
};

int main(){
    
    return 0 ;
}