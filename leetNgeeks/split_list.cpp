// https://leetcode.com/problems/split-linked-list-in-parts/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* list, int k) {
     
    
        
        vector<ListNode*> ans(k,nullptr);
        if(list == nullptr) {
            return ans;
        }
        
        
        ListNode *tmp = list;
        int len = 0;
        while(tmp!=nullptr) {
            len++;
            tmp = tmp->next;
        }
        
        tmp = list;
        int ind = 0;
       
            
         int times;
        while(len > 0) { //run  k times
            times = len/k;
            if(len%k != 0)
                times += 1;
            k--;
            len = len - times;
            ans[ind++] = tmp;
            for(int i = 0; i < times-1; i++) {
                if(tmp!=nullptr)
                    tmp = tmp->next;
                 
            }
            ListNode *local = tmp;
            tmp = tmp->next;
            local->next = nullptr;
        }            
            
        
        
        return ans;
    }
};