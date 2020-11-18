
// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#

//  Count pairs with given sum 
/*
Given an array of N integers, and an integer K, 
find the number of pairs of elements in the array 
whose sum is equal to K
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int count = 0;
        int n = prices.size();
    if(n == 0) {
        return 0;
    }
    
        int maxx = prices[n-1];
        prices[n-1] =0;
       
    
        for(int i = n-2; i>=0; i--) {
            if(prices[i] >= maxx) {
                maxx = prices[i];
                 prices[i] = 0;
            }
            else{
                prices[i] = maxx-prices[i];
            }
        }
        
     
        return *max_element(prices.begin(),prices.end());
        
        
        
    }
};