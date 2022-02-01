
// Easy
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int N = prices.size();
        int helper[N];
        
        int tmp_max = INT_MIN;
        for(int i = N-1; i>=0; i--) {
            helper[i] = max(prices[i], tmp_max);
            tmp_max = helper[i];
        }
        
        for(int i = 0; i < N; i++){
            profit = max(profit, (helper[i]-prices[i]));
        }
        
        return profit;
    }