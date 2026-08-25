#include<iostream>
#include "unordered_set"
#include "unordered_map"

using namespace std ;
class Solution {
private:
    void dfs(string word , string beginWord , unordered_map<string,int>&mp , vector<string>&vec , vector<vector<string>>&result ) {
        // base case 
        if(word == beginWord){

            vector<string>copy = vec ;
            reverse(copy.begin() , copy.end() ) ;
            result.push_back(copy) ;
            return ;

        }

        int level = mp[word] ;
        for(int i = 0 ; i<word.size() ; i++ ) {
            char original = word[i] ;
            for(char c = 'a' ; c<='z' ; c++ ) {
                word[i] = c ;
                if( mp.find(word) != mp.end() && mp[word] == level-1 ){
                    
                    vec.push_back(word) ;

                    dfs(word , beginWord , mp , vec , result ) ;

                    vec.pop_back() ;
                }
            }
            word[i] = original ;
        }

    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        // step 1 => 
        unordered_set<string>st(wordList.begin() , wordList.end()) ;
        unordered_map<string,int>mp ;
        vector<vector<string>>result ;

        if(st.count(endWord) == 0 ) {
            return result ;
        }

        queue<string>q ;
        q.push(beginWord) ;
        st.erase(beginWord) ;
        mp[beginWord] = 1 ;

        while( !q.empty() ) {
            string node = q.front() ;
            int level = mp[node] ;
            q.pop() ;
            

            if(node == endWord){
                break ;
            }

            for(int i = 0 ; i<node.size() ; i++ ) {
                char original = node[i] ;
                for(char c = 'a' ; c<='z' ; c++) {
                    node[i] = c ;
                    if(st.count(node) > 0 ) {
                        q.push(node) ;
                        st.erase(node) ;
                        mp[node] = level+1 ;
                    }
                }
                node[i] = original ;
            }
            
        }

        // step 2 => 
        vector<string>vec ;
        vec.push_back(endWord) ;

        dfs(endWord , beginWord , mp ,vec , result) ;

        return result ;
    }
};
int main(){
    
    return 0 ;
}