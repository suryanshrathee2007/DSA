#include<iostream>
#include<set>
using namespace std ;
class Solution {
private:
    void dfs(int r , int c ,vector<vector<char>>& grid , vector<vector<int>>&visited,vector<pair<int,int>> &vec , int n , int m , int oR , int oc) {
        vec.push_back({r-oR,c-oc}) ;
        visited[r][c] = 1 ;
        
        int row[4] = {-1,0,1,0} ;
        int col[4] = {0,1,0,-1} ;
        
        for(int i = 0 ; i<4 ; i++ ) {
            int newr = r+row[i] ;
            int newc = c+col[i] ;
            
            if(newr>=0 && newr<n && newc>=0 && newc<m && !visited[newr][newc] && grid[newr][newc]=='L'){
                dfs(newr,newc , grid , visited , vec ,n , m , oR ,oc) ;
            }
        }
        return ;
    }
  public:
    int countDistinctIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<vector<int>>visited(n,vector<int>(m,0)) ;
        set<vector<pair<int,int>>>st ;
        
        for(int i = 0 ; i<n ; i++ ) {
            for(int j = 0 ; j<m ; j++ ) {
                if(!visited[i][j] && grid[i][j] == 'L') {
                    vector<pair<int,int>> vec; 
                    dfs( i , j , grid , visited , vec ,n ,m ,i ,j ) ;
                    st.insert(vec) ;
                }
            }
        }
        return st.size() ;
        
    }
};

int main(){
    
    return 0 ;
}