#include<iostream>
using namespace std ;
class Solution {
private :
        void dfs(int r , int c , vector<vector<int>>& grid , vector<vector<int>>&visited , int row[] , int col[] , int n , int m ) {
            visited[r][c] = 1 ;

            for(int i = 0 ;i<4 ; i++ ) {
                int nrow = r + row[i] ;
                int ncol = c + col[i] ;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && !visited[nrow][ncol] ) {
                    dfs(nrow , ncol , grid, visited , row , col , n , m ) ;
                }
            }
            return ;

        }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0] .size() ;

        int row[4] = {-1 , 0 , 1 , 0} ;
        int col[4] = {0 , 1 ,0 , -1} ;

        vector<vector<int>>visited(n,vector<int>(m,0)) ;

        for(int i = 0 ; i<n ; i++ ) {
            if(grid[i][0] == 1 && !visited[i][0]) {
                dfs(i , 0 , grid , visited , row , col ,n ,m) ;
            }
            
            if( grid[i][m-1] == 1 && !visited[i][m-1] ) {
                dfs(i , m-1 , grid , visited , row , col ,n , m) ;
            }
        }

        for(int i = 0 ; i<m ; i++ ) {
            if( grid[0][i] == 1 && !visited[0][i] ) {
                dfs(0 , i , grid , visited , row ,col , n ,m ) ;
            }

            if( grid[n-1][i] == 1 && !visited[n-1][i] ) {
                dfs( n-1 , i , grid , visited ,row , col , n , m ) ;
            }
        }

        int ans = 0 ;
        for(int i = 0 ; i< n ; i++ ) {
            for(int j = 0 ; j<m ;j ++ ) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    ans++ ;
                    visited[1][j] = 1 ;
                }
            }
        }
        return ans ;
    }
};
int main(){
        vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    Solution s  ;
     cout<<"ans is " << s.numEnclaves(grid ) << endl ;

    return 0 ;
}