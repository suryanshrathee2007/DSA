#include<iostream>
using namespace std ;
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>result ;

        sort(nums.begin() , nums.end()) ;
        

        for(int i = 0 ; i< nums.size() ; i++ ) {

            if(lower < nums[i]) {
                result.push_back({lower , min(nums[i]-1 , upper )}) ;
            }

            lower = max(lower , nums[i]+1) ;


            if(lower>upper){
                return result ;
            }
        }

        if(lower<=upper){
            result.push_back({lower , upper}) ;
        }
        return result ;
    }
};
int main(){
    
    return 0 ;
}