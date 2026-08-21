// que=> Detect a Cycle in an Undirected Graph

// using bfs

/*
#include<iostream>
using namespace std ;
bool detectcycle(int start , vector<int> adj[] ,vector<bool>&vis){
    vis[start] = 1 ;
    queue<pair<int,int>>q ;
    q.push({start,-1}) ;

    while(!q.empty()) {
        int node = q.front().first ;
        int parent = q.front().second ;

        q.pop() ;

        for(auto adjnodes : adj[node]){
            if(!vis[adjnodes]){
                vis[adjnodes] = 1 ;
                q.push({adjnodes , node}) ;
            }
            else if(adjnodes!=parent){
                return true ;
            }
        }
        
    }
    return false ;
    
}
int main(){
        vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
        vector<bool>vis(4,0);

        bool ans = detectcycle(0,adj,vis) ;
        cout << boolalpha << ans <<endl;
    return 0 ;
}*/


// using dfs

#include<iostream>
using namespace std ;
bool detectcycle(int start , int parent ,vector<int>adj[] , vector<bool>&vis) {
    vis[start] = 1 ;

    for(auto adjnode : adj[start]) {
        if(!vis[adjnode]) {
            if(detectcycle(adjnode , start , adj ,vis) == true ) {
                return true ;
            }
        }
        else if(adjnode!=parent) {
            return true ;
        }
    }
    return false ;
}
int main(){
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    vector<bool>vis(4,0);

    bool ans = detectcycle(0,-1,adj,vis) ;
    cout << boolalpha << ans <<endl;
    return 0 ;
}