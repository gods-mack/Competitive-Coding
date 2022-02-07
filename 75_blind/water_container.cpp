
// Mesdium
// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& a) {
        
        int res = 0;
        
        int l = 0;
        int r = a.size() - 1;
        
        while(r > l) {
            
            int br = r - l;
            
            res = max(res, min(a[l],a[r])*br);
            
            if(a[r] > a[l]) {
                l++;
            }
            else{
                r--;
            }
        }
        return res;
        
    }
};