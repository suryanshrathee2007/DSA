#include<iostream>
using namespace std ;
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bool visited[101] = {0} ;

        for(int x : nums) {
            visited[x] = 1 ;
        }

        int num = k ;
        while(num<=100){
            if(!visited[num]){
                break ;
            }
            num = num+k ;
        }
        return num ;
    }
};
int main(){
    
    return 0 ;
}