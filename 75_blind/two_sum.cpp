
// Easy 
// https://leetcode.com/problems/two-sum/

vector<int> twoSum(vector<int>& nums, int target) {
        
       
        vector<int> ans;
        unordered_map<int,int> hs;
       
        for(int i =0; i<nums.size(); i++) {
            
            int need = (target-nums[i]);
            if(hs.find(need) != hs.end()){
                ans.push_back(i);
                ans.push_back(hs[need]);
                return ans;
            }
            hs[nums[i]] = i;
            
        }
        
        return ans;
        
    
  }