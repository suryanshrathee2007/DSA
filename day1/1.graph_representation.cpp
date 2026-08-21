
// using adjancey matrix 

/*
#include<iostream>
using namespace std ;
int main(){
    int n , m ;
    cin>>n>>m ;

    int matrix[n+1][m+1] ;

    for(int i = 0 ; i< m ; i++ ) {
        int u ,v ;
        cin >> u >> v ;
        matrix[u][v] = 1 ;
        matrix[v][u] = 1 ;
    }

    for(int i = 0 ; i<n ; i++ ) {
        
        for(int j = 0 ; j< m ;j++ ) {
            if(matrix[i][j] == 1 ) {
                cout<< i << "is linked to  " << j << endl ;
            }
        }
    }

    return 0 ;
}
*/


// using adancey list 

#include<iostream>
using namespace std ;
int main(){
    int n , m ;
    cin>> n >> m ;

    vector<int> adj[n+1] ;

    for(int i = 0 ; i< m ; i++ ) {
        int u , v ; 
        cin >> u >> v ;

        adj[u].push_back(v) ;
        adj[v].push_back(u) ;

    }

   for(int i = 0 ; i<=n ; i++ ) {
        if(adj[i].empty()){
            continue ;
        }

        cout<< i <<" is connected to nodes  :-> " ;
        for(auto itr : adj[i] ){
            cout<< itr <<" " ;
        }

        cout<<endl ;
   }

    return 0 ;
}