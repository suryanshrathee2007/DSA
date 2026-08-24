#include<iostream>
using namespace std ;
class Solution {
private:
    vector<int> binrep(int x) {
        vector<int>sol ;
        while(x) {
            int num = x%2 ;
            sol.push_back(num) ;
            x = x/2 ;
        }
        if(sol.size() < 8 ) {
            int diff = 8 - sol.size() ;
            for(int i = 0 ; i<diff ; i++ ) {
                sol.push_back(0) ;
            }
        }
        reverse(sol.begin() , sol.end()) ;
        return sol ;
    }
public:
    bool isPalindromic(string s) {
        // how to make 8-bit binary representation
        // 01100110 = 2+4+32+64 = 38+64 
        // divide number continuesly with 2 
        // store the quotents ,then reverse the quotent order if the 
        // length is less then 8 then add 0 in front 

        vector<int>ans ;
        for(int i = 0 ; i<s.size() ; i++ ) {
            int x = s[i] ;
            vector<int>rep = binrep(x) ;
            for(int i = 0 ; i<8 ; i++ ) {
                ans.push_back(rep[i]) ;
            }
        }

        int i = 0 ;
        int j = ans.size()-1 ;

        while(i<j){
            if(ans[i]!=ans[j]) {
                return false ;
            }
            i++ ;
            j-- ;
        }

        return true ;
        
    }
};
int main(){
    
    return 0 ;
}