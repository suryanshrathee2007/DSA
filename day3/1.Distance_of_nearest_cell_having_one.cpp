#include<iostream>
using namespace std ;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() ;
        int m = mat[0].size() ;

        vector<vector<int>>ans(n , vector<int>(m)) ;
        vector<vector<int>>visited(n , vector<int>(m , 0 )) ; 
        queue<pair<pair<int,int>,int>>q ;

        for(int i = 0 ; i< n ; i++ ) {
            for(int j = 0 ; j<m ;j++ ) {
                if(mat[i][j] == 0 ) {
                    q.push({{i,j} , 0} ) ;
                    visited[i][j] = 1 ;
                }
            }
        }

        int row[4] = { -1 , 0 , 1 , 0 } ;
        int col[4] = { 0 , 1 , 0 , -1 } ;

        while(!q.empty() ) {
            int r = q.front().first.first ;
            int c = q.front().first.second ;
            int step = q.front().second ;
            q.pop() ;

            
                ans[r][c] = step ;
            

            for(int i = 0 ; i<4 ; i++ ){
                int newr = r+row[i] ;
                int newc = c+col[i] ;

                if(newr>=0 && newr<n && newc>=0 && newc < m && !visited[newr][newc]){
                    visited[newr][newc] = 1 ;
                    q.push({ {newr,newc} , step+1}) ;
                }
            }

        }
        return ans ;
        
    }
};
int main(){
    
    return 0 ;
}