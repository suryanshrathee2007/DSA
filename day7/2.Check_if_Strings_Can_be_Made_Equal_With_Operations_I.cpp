#include<iostream>
using namespace std ;
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string temp = s1 ;
        int i = 0 , j = 2 ;
        while(j<5){
            if(temp[i] != s2[i]){
                if(s2[i] == temp[j]) {
                    swap(temp[i] , temp[j]) ;
                }
            }
            i++ ;
            j++ ;
        }
        return temp==s2 ;
    }
};
int main(){
    
    return 0 ;
}