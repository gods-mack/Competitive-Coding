
//Esay

// https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        
        while(list1 != nullptr and list2!=nullptr){
            
            int el;
            if(list1->val > list2->val){
                el = list2->val;
                list2 = list2->next;
            }
            else{
                el = list1->val;
                list1 = list1->next;
            }
            
            if(head == nullptr){
                head = new ListNode(el);
                tail = head;
            }
            else{
                ListNode *n = new ListNode(el);
                tail->next = n;
                tail = n;
            }
        }
        
        while(list1!=nullptr){
            int el = list1->val;
            if(head == nullptr){
                head = new ListNode(el);
                tail = head;
            }
            else{
                ListNode *n = new ListNode(el);
                tail->next = n;
                tail = n;
            }
            list1 = list1->next;
        }
        while(list2!=nullptr){
            int el = list2->val;
            if(head == nullptr){
                head = new ListNode(el);
                tail = head;
            }
            else{
                ListNode *n = new ListNode(el);
                tail->next = n;
                tail = n;
            }
            list2 = list2->next;
        }
        
        
        return head;
    }
};