#include<iostream>
using namespace std ;
class Solution {
private:
    void bfs(int r , int c ,vector<vector<char>>& grid , vector<vector<int>>&visited , int row[] , int col[] , int n , int m ) {
        queue<pair<int,int>>q ;
        q.push( {r,c} ) ;
        
        visited[r][c] = 1 ;
        while(!q.empty() ) {
            int nrow = q.front().first ;
            int ncol = q.front().second ;
            q.pop() ;
            

            for(int i = 0 ; i<4 ; i++ ) {
                int ro = nrow+row[i] ;
                int co = ncol + col[i] ;

                if(ro>=0 && ro<n && co>=0 && co<m && grid[ro][co] == '1' && !visited[ro][co] ) {
                    q.push( { ro , co } ) ;
                    visited[ro][co] = 1 ;
                }
            }
        }
        return ;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        vector<vector<int>>visited(n , vector<int>(m,0) ) ;
        int cnt = 0 ;

        int row[4] = {-1 , 0 , 1 , 0 } ;
        int col[4] = {0 , 1 , 0 , -1 } ;

        for(int i = 0 ;i<n ; i++ ) {
            for(int j = 0 ; j< m ; j++ ) {
                if(grid[i][j] == '1' && !visited[i][j] ) {
                    bfs(i , j , grid , visited , row , col , n , m ) ;
                    cnt++ ;
                }
            }
        }
        return cnt ;
    }
};
int main(){
    
    return 0 ;
}