
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        
        unordered_map<int,int> hs;
        ListNode *tmp = head;
        
        while(tmp!=nullptr) {
            hs[tmp->val]++;
            tmp = tmp->next;
        }
        
        ListNode *nhead = nullptr;
        ListNode *tail = nullptr;
        
        tmp = head;
        while(tmp != nullptr) {
            
            if(hs[tmp->val] <= 1) {
                if(nhead == nullptr) {
                    nhead = tmp;
                    tail = tmp;
                }
                else{
                    tail->next = tmp;
                    tail = tmp;
                   // tail->next = nullptr;
                }
                tmp = tmp->next;
            }
            else{
                tmp = tmp->next;
            }
        }
        
        //for case [1,2,2]
        // [1,1]
        if(tail!=nullptr and tail->next!=nullptr){
            if(hs[tail->next->val] > 1) {
                tail->next = nullptr;
            }
        }
     
       
        return nhead;
        
    }
};