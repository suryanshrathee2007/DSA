#include<iostream>
using namespace std ;
class Solution {
private:
    void prime(int num , unordered_map<int,int>&primo ) {
        for(int i = 2 ; i*i<=num ; i++){
            if(num%i == 0 ) {
                primo[i]++ ;

                while(num%i == 0){
                    num/=i ;
                } 
            }
        } ;
        if(num>1){
            primo[num]++ ;
        }
        
        return ;
    }
    void removepri(int num , unordered_map<int,int>&primo) {
         for(int i = 2 ; i*i<=num ; i++){
            if(num%i == 0 ) {
                primo[i]-- ;
                if(primo[i] == 0){
                    primo.erase(i) ;
                }

                while(num%i == 0){
                    num/=i ;
                }
            }
        }

        if(num>1){
            primo[num]-- ;
            if(primo[num] == 0) {
                primo.erase(num) ;
            }
        }
        return ;
    }
public:
    int longestSubarray(vector<int>& nums, int k) {
        
        int i = 0; 
        int j = 0; 
        int n = nums.size() ;
        unordered_map<int,int>primo ;
        int maxi = 0 ;
        while( j<n ) {
            prime(nums[j] , primo) ;

            while(primo.size() > k ) {
                removepri(nums[i] , primo) ;
                i++ ;
            }
            
            if(primo.size() <= k) {
                int size = j-i+1 ;
                maxi = max(maxi , size) ;
            }
            j++ ;
            
        }
        return maxi ;
    }
};
int main(){
    
    return 0 ;
}