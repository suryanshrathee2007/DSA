#include<iostream>
#include<unordered_set>
using namespace std ;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin() , wordList.end() ) ; 

        int n = beginWord.size() ;
        int m = wordList.size() ;

        if(st.find(endWord) == st.end()) {
            return 0 ;
        }

        queue<pair<string,int>>q ;
        q.push({ beginWord , 1 }) ;

        while(!q.empty()) {
            string word = q.front().first ;
            int d = q.front().second ;
            st.erase(word) ;
            q.pop() ;

            if(word == endWord) {
                return d ;
            }

            for(int i = 0 ; i<n ; i++) {
                char original = word[i] ;
                for(int j = 0 ; j<26 ; j++ ) {
                    word[i] = j+'a' ;
                    if(st.find(word) !=st.end()) {
                        q.push({word , d+1}) ;
                        st.erase(word) ;
                    }
                }
                word[i] = original ;
            }
        }

        return 0 ;

    }
};
int main(){
    
    return 0 ;
}