#include<iostream>
using namespace std ;
class Solution {
private:
    vector<int>toposort(vector<vector<int>>&adj , vector<bool>&present){
        vector<int>indegree(26,0) ;
        
        for(int i = 0 ; i<26 ; i++ ) {

                for(auto itr : adj[i]){
                    indegree[itr]++ ;
                }
            
        }
        
        queue<int>q ;
        int unique_element = 0 ;
        
        for(int i= 0 ; i<26 ; i++) {
            if(present[i]) {
                unique_element++ ;
                
                if(indegree[i] == 0 ) {
                    q.push(i) ;
                }
            }
        }
        
        vector<int>ans ;
        while(!q.empty() ) {
            int node = q.front() ;
            q.pop() ;
            ans.push_back(node) ;
            
            for(auto it : adj[node]){
                indegree[it]--;
                
                if(indegree[it] == 0 ) {
                    q.push(it) ;
                }
            }
        }
        
        if(ans.size()!=unique_element){
            return {} ;
        }
        return ans ;
    }
  public:
    string findOrder(vector<string> &words) {
        // firstly i will try to make a graph 
        vector<vector<int>>adj(26) ;
        
        int n = words.size() ;
        
        vector<bool>present(26,false) ;
        for(auto &s : words ) {
            for(auto c : s) {
                present[c-'a'] = true ;
            }
        }
        
        
        for(int i = 0 ; i<n-1 ; i++ ) {
            string s1 = words[i] , s2 = words[i+1] ;
            
            int len1 = s1.size() ;
            int len2 = s2.size() ;
            
            int len = min(len1 , len2 ) ;
            bool check = false ;
            
            for(int ptr = 0 ; ptr<len ; ptr++ ) {
                if(s1[ptr]!=s2[ptr]) {
                    adj[ s1[ptr] - 'a' ] .push_back(s2[ptr] - 'a' ) ;
                    check = true ;
                    break ;
                }
            }
            if(check == false) {
                if(len1>len2){
                    return "" ;
                }
            }
        }
        
        vector<int>topo = toposort(adj , present) ;
        
        string result = "" ;
        for(int i = 0 ; i<topo.size() ; i++){
            result.push_back(topo[i]+'a') ;
        }
        return result ;

        
    }
};
int main(){
    
    return 0 ;
}