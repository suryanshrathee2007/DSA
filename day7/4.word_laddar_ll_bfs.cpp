#include<iostream>
#include <unordered_set>
using namespace std ;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result ;
        unordered_set<string>st(wordList.begin() , wordList.end()) ;

        if(st.count(endWord) == 0){
            return result ;
        }

        queue<vector<string>>q ;
        q.push({beginWord}) ;
        vector<string>onlevel ;
        onlevel.push_back(beginWord) ;
        int level = 1 ;

        while(!q.empty()) {
            vector<string>node = q.front() ;
            q.pop() ;

            if(node.size() > level ) {
                level++ ;
                for(auto x : onlevel){
                    st.erase(x) ;
                    
                }
                onlevel.clear() ;
            }

            string word = node.back() ;

            if(word == endWord) {
                if(result.size() == 0 ) {
                    result.push_back(node) ;
                }
                else if(node.size() == result[0].size()) {
                    result.push_back(node) ;
                }
                continue ;
            }

            for(int i = 0 ; i<word.size() ; i++){
                char original = word[i] ;
                for(char c = 'a' ; c<='z' ; c++) {
                    word[i] = c ;
                    if(st.count(word) > 0) {
                        node.push_back(word) ;
                        q.push(node) ;
                        node.pop_back() ;
                        onlevel.push_back(word) ;
                    }
                }
                word[i] = original ;
            }
            
        }
        return result ;

    }
};
int main(){
    
    return 0 ;
}