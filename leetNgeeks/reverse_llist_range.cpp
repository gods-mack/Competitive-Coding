// https://leetcode.com/problems/reverse-linked-list-ii/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   
   
    ListNode* reverseBetween(ListNode* list, int m, int n) {
        
        if(list->next == nullptr){
            return list;
        }
        if(m == n){
            return list;
        }

        ListNode *prv;
        ListNode *tmp_m = list;
        
        stack<int> s;
        for(int i=0;i<m-1;i++){
            prv = tmp_m;
            tmp_m = tmp_m->next;
        }
       ListNode* nhead = tmp_m;
        for(int i = 0; i < abs(m-n)+1; i++){
            s.push(nhead->val);
            nhead = nhead->next;
        }
        
        for(int i = 0; i < abs(m-n)+1; i++){
            tmp_m->val = s.top();
            s.pop();
            tmp_m = tmp_m->next;
        }
        //nhead->val = tmp_m->val;
        

        return list;
        
    }
};