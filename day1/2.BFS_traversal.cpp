#include<iostream>
#include <queue>
using namespace std ;
int main(){
    int n , m ;
    cin>>n>>m ;

    vector<int>arr[n+1] ;


    for(int i = 0 ; i<=n ;i++ ) {
        int u , v ;
        cin>>u >> v ;

        arr[u].push_back(v) ;
        arr[v].push_back(u) ;

    }

    // bfs traversal 
    vector<int>ans ;
    vector<bool>visited(n+1) ;
    visited[1] = 1 ;
    queue<int>q ;
    q.push(1) ;

    while(!q.empty()) {
        int node = q.front() ;
        q.pop() ;
        ans.push_back(node) ;

        for(auto it :arr[node]) {
            if(!visited[it]) {
                q.push(it) ;
                visited[it] = 1 ;
            }
            
        }
    }

    for(auto it : ans){
        cout<<it<<" " ;
    }

    return 0 ;
}