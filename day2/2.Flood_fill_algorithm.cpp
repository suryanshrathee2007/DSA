#include<iostream>
using namespace std ;

class Solution {
private:
    void dfs(vector<vector<int>>&ans , vector<vector<int>>&image , int sr , int sc ,int originalc , int color ) {
        int r = image.size() ;
        int c = image[0].size() ;

        int row[4] = {-1,1,0,0} ;
        int col[4] = {0,0,-1,1} ;

        
            ans[sr][sc] = color ;
        
        
        for(int i=0 ; i<4 ;i++ ) {
            int nrow = sr+row[i] ;
            int ncol = sc+col[i] ;

            if(nrow>=0 && nrow<r && ncol>=0 && ncol<c && image[nrow][ncol]==originalc && ans[nrow][ncol]!=color) {
                dfs(ans , image,nrow , ncol ,originalc ,color ) ;
            }
        }
        return ;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalc = image[sr][sc] ;
       

        vector<vector<int>> ans = image ;

        if(image[sr][sc]!=color){
            dfs(ans , image ,sr , sc ,originalc ,color ) ;
        }
        

        return ans ;
    }
};

int main(){
    
    return 0 ;
}