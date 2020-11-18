
// 121. Best Time to Buy and Sell Stock

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


// O(N) and O(N) sol
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int count = 0;
        int n = prices.size();
    if(n == 0) {
        return 0;
    }
        vector<int> tmp(n);
        int maxx = prices[n-1];
        for(int i = n-1; i>=0; i--) {
            maxx = max(maxx,prices[i]);
            tmp[i] = maxx;
        }
        
        for(auto x:tmp) {
            cout<<x<<" ";
        }
        for(int i = 0; i < n; i++) {
            
            if(prices[i] != tmp[i]) {
                count = max(count,tmp[i]-prices[i]);
            }
        }
        
        return count;
        
    }
};


// O(N) and O(1) solution

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