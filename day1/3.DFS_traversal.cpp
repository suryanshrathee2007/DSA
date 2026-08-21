#include<iostream>
#include <vector>
using namespace std ;
void dfs(int n ,vector<int>arr[n+1] ,int start , vector<int>&ans ,vector<bool>&visited){
    visited[start]= 1 ;
    ans.push_back(start) ;

    for(auto it : arr[start]){
        if(!visited[it]){
            dfs(n,arr,it , ans,visited ) ;
            }
        }
        
    return ;
}
int main(){
    int n , m ;
    cin>>n>>m ;

    vector<int>arr[n+1] ;


    for(int i = 0 ; i<m ;i++ ) {
        int u , v ;
        cin>>u >> v ;

        arr[u].push_back(v) ;
        arr[v].push_back(u) ;

    }

    vector<int>ans ;
    vector<bool>visited(n+1) ;
    dfs(n,arr,1,ans,visited) ;

    for(auto it : ans){
        cout<<it<<" " ;
    }
    return 0 ;
}