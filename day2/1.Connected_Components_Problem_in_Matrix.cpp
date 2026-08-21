
// que1 => Connected Components Problem in Matrix

#include<iostream>
using namespace std ;
int ConnectedComponents(int v , vector<vector<int>>edges ) {

    vector<int> adj[v] ;
    
    for(auto &it : edges){
        adj[it[0]] .push_back(it[1] ) ;
        adj[it[1]] .push_back(it[0] ) ;

    }

    int component = 0 ;

    vector<int>visited(v,0) ;

    for(int i = 0 ; i<v ; i++ ) {
        component++ ;

        queue<int>q ;

        q.push(i) ;
        visited[i] =1 ;

        while(!q.empty() ) {
            int node = q.front() ;
            q.pop() ;

            for(int a: adj[node]){
                if(!visited[a] ) {
                    visited[a] = 1 ;
                    q.push(a) ;
                }
            }
        }
    }
    return component ;
}
int main(){
       int vertices = 5 ;
       vector<vector<int>>edges = {{0,1},{1,2},{3,4}};

       cout << "ans is " << ConnectedComponents(vertices , edges) ;
       
    return 0 ;
}