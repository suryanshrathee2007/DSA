#include<iostream>
using namespace std ;
class Solution {
private:
    void dfs(int r , int c  , vector<vector<char>>& board ,vector<vector<int>>&visited  , int row[] , int col[] ,int n , int m) {
        visited[r][c] = 1 ;

        for(int i = 0 ; i<4 ; i++ ) {
            int nrow = r+row[i] ;
            int ncol = c + col[i] ;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol ] == 'O') {
                dfs(nrow , ncol , board , visited , row , col , n , m) ;
            }
        }
        return ;
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size() ;
        int m = board[0].size() ;

        vector<vector<int>>visited(n,vector<int>(m,0)) ;
        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, 1, 0, -1};


        for(int i = 0 ; i<m ; i++ ){
            if( board[0][i] == 'O' && !visited[0][i] ) {
                dfs(0 , i , board , visited , row ,col , n ,m) ;
            }
        }
        for(int i = 0 ; i<n ; i++ ) {
            if(board[i][0]=='O' && !visited[i][0]) {
                dfs(i,0 , board , visited ,row ,col , n , m ) ;
            }
        }
        for(int i = 0 ; i<m ; i++ ) {
            if(board[n-1][i] == 'O' && !visited[n-1][i] ) {
                dfs( n-1 , i , board , visited ,row , col ,n, m) ;
            }
        }
        for(int i = 0 ;i<n ; i++ ) {
            if(board[i][m-1]=='O' && !visited[i][m-1] ) {
                dfs(i , m-1 , board , visited  ,row , col ,n,m) ;
            }
        }

        for(int i = 0 ; i<n ; i++ ) {
            for(int j = 0 ; j<m ; j++ ) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X' ;
                    visited[i][j] = 1 ;
                }
            }
        }
        return ;
    }
};
int main(){
    vector<vector<char>> mat{
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','X','O','O'}
    };

    Solution o ;

    vector<vector<char>>ans = mat ;
    o.solve(ans) ;

    for(int i = 0 ; i<mat.size() ;i++ ) {
        for(int j = 0 ; j<mat[0].size() ; j++ ) {
            cout<< ans[i][j] <<" " ;
        }
        cout<<endl ;
    }

    return 0 ;
}