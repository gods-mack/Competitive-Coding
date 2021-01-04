

// https://leetcode.com/problems/partition-equal-subset-sum/
// 416. Partition Equal Subset Sum

class Solution {
public:
    
    bool demo(vector<int> nums,int m,int sum) {
        
        bool dp[m+1][sum+1];
        for(int i = 0; i < m+1; i++) {
            for(int j = 0; j < sum+1; j++) {
                dp[i][j] = false;
            }
        }
        for(int i  = 0; i < m+1; i++) {
            dp[i][0] = true;
        }
        
        for(int i = 1; i < m+1; i++) {
            
            for(int j = 1; j < sum+1; j++) {
                
                if(nums[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        
        return dp[m][sum];
        
    }
    
    bool canPartition(vector<int>& nums) {
        
        
        int total = 0;
        for(auto x:nums) {
            total += x;
        }
        if(total%2 != 0) {
            return false;
        }
        
        if(demo(nums,nums.size(),total/2)) {
            return true;
        }
        
        return false;
    }
};