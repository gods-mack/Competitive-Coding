
// Medium
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        ListNode *th = head;
        int count = 0;
        
        while(th!=nullptr){
            count++;
            th = th->next;
        }
        
        if(count-n == 0){
            return head->next;
        }
        th = head;
        int pass = 1;
        
        while(th!=nullptr){
        
            if(pass == (count-n)){
                ListNode *tbd = th->next;
                
                th->next = th->next->next;
            }
            th = th->next;
            pass++;
    
            
        }
        
        return head;
        
    }
};