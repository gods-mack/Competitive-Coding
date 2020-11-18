// https://leetcode.com/problems/odd-even-linked-list/


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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;
        
        if(head->next == nullptr) return head;
        
	

	ListNode *odd = nullptr;
	ListNode *even = nullptr;
	ListNode *to; // odd tail
    ListNode *te; // even tail

	ListNode *tmp = head;

        int count = 1;
	while(tmp!= nullptr) {

		if(count%2 != 0) {
			if(odd == nullptr){
				odd = tmp;
				to = tmp;
			}
			else{
				to->next = tmp;
				to = tmp;
			}
		}
		else{
			if(even == nullptr){
				even = tmp;
				te = tmp;
			}
			else{
				te->next = tmp;
				te = tmp;
			}
		}
		tmp = tmp->next;
        count++;
	}

	te->next = nullptr;
	to->next = even;

	return odd;
    }
};