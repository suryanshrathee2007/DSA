// solving the question through kahn algo 

#include<iostream>
using namespace std ;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int>adjrev[n] ;
        vector<int>indegree(n,0) ; 

        for(int i = 0 ; i<n ; i++ ) {

            for(auto itr : graph[i] ) {
                adjrev[itr].push_back(i) ;
                indegree[i]++ ;
            }
        }

        queue<int>q ;
        for(int i = 0 ; i<n ; i++ ) {
            if(indegree[i] == 0 ) {
                q.push(i) ;
            }
        }

        vector<int>ans ;
        while(!q.empty() ) {
            int node = q.front() ;
            q.pop() ;
            ans.push_back(node) ;

            for(auto itr : adjrev[node] ) {
                indegree[itr]-- ;

                if(indegree[itr] == 0 ) {
                    q.push(itr) ;
                }
            }
        }

        sort(ans.begin() , ans.end() ) ;

        return ans ;
    }
};
int main(){
    
    return 0 ;
}