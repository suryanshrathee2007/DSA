#include<iostream>
using namespace std ;
class Solution {
private:
    int distance ( int x1 , int y1 , int x2 , int y2 ) {
        return abs(x1-x2) + abs(y1-y2) ;
    }
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mini = INT_MAX ;
        int diff = INT_MAX ;
        int x2 = target[0] ;
        int y2 = target[1] ;

        for(int i = 0 ; i<drones.size() ; i++ ) {
            int x1 = drones[i][0] ;
            int y1 = drones[i][1] ;
            int range = drones[i][2] ;

            int manhattan = distance(x1 , y1 , x2 , y2) ;

            if(manhattan <= range) {
               if(manhattan < diff) {
                   mini = i ;
                   diff = manhattan ;
               }
                else if(manhattan == diff){
                    mini = min(mini , i) ;
                }
            }  
        }
        if(mini == INT_MAX){
            mini = -1 ;
        }
        return mini ;
    }
};
int main(){
    
    return 0 ;
}