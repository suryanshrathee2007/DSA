#include<iostream>
using namespace std ;
class Solution {
    private:
    bool cyclecheck(int start , vector<vector<int>>&graph , vector<int>&vis ,vector<int>&check ) {
        
        vis[start] = 1 ;

        for(auto itr : graph[start] ) {
            if(vis[itr] == -1 ) {
                if(cyclecheck(itr , graph , vis ,check )  == true ) {
                    return true ;
                }
            }
            else if (vis[itr] == 1 ) {
                return true ;
            }
            
        }

        check[start] = 1 ;
        vis[start] = 0 ;
        return false ;

    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int>vis(n,-1) ;
        vector<int>check(n,0) ;
        vector<int>ans ;

        for(int i = 0 ; i< n ; i++ ) {
            if(vis[i] == -1 ) {
                 cyclecheck(i , graph , vis ,check)  ;
            }
        }

        for(int i = 0 ; i<n ; i++ ) {
            if(check[i] == 1 ) {
                ans.push_back(i) ;
            }
        }

        return ans ;
    }
};
int main(){
    
    return 0 ;
}