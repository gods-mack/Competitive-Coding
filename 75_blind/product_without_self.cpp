
// Medium
// https://leetcode.com/problems/product-of-array-except-self/



vector<int> productExceptSelf(vector<int>& nums) {
        
        int N = nums.size();
        int lr[N];   // left prefix product
        int rl[N];   // right postfix product
        vector<int> ans(N);
        
        
        for(int i = 0; i < N; i++) {
            if(i==0){
                lr[i] = nums[0];
            }
            else{
                lr[i] = lr[i-1]*nums[i];
            }
        }
        for(int i = N-1; i >=0 ; i--) {
            if(i==N-1){
                rl[i] = nums[i];
            }
            else{
                rl[i] = rl[i+1]*nums[i];
            }
        }
        
        
        for(int i = 0; i < N; i++) {
            if(i == 0){
                ans[i] = rl[i+1];
            }
            else if(i == N-1) {
                ans[i] = lr[i-1];
            }
            else{
                ans[i] = lr[i-1]*rl[i+1];
            }
        }
        return ans;
        
        
    }