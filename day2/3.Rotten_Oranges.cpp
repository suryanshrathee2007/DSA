#include<iostream>
using namespace std ;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        queue<pair<pair<int,int>,int>> q ;

        vector<vector<int>>visited(n,vector<int>(m,0)) ;
        int cntfresh=0 ;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j} , 0}) ;
                    visited[i][j] = 1 ;
                }

                if(grid[i][j] == 1)cntfresh++ ;
            }
        }

        int row[4] = {-1,0,1,0} ;
        int col[4] = {0 ,1,0,-1} ;
        int t = 0 ;

        int cnt = 0 ;
        while( !q.empty() ) {
            int r = q.front().first.first ;
            int c = q.front().first.second ;
            int tm = q.front().second ;
            q.pop() ;
            t = max(tm,t) ;

            for(int i = 0 ; i<4 ; i++){
                int nrow = r+row[i] ;
                int ncol = c+col[i] ;

                if(nrow>=0 &&nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1 ){
                    q.push({{nrow,ncol} ,t+1 } ) ;
                    visited[nrow][ncol] = 1 ;
                    cnt++ ;
                }
            }
            
        }
        if(cnt!=cntfresh){
            return -1 ;
        }
        return t ;

    }
};
int main(){
    
    return 0 ;
}