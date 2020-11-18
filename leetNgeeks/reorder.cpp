 
// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        
        
	unordered_map<int,ListNode*> hs;
	int ind = 0;
	ListNode *tmp = head;
	while(tmp!=nullptr) {
		hs[ind++] = tmp;
		tmp = tmp->next;
	}

	int len = ind;

	

	int l = 0;
	int r = ind-1;
	ListNode *curr = nullptr;

	while( r>=l) {


		ListNode *a = hs[l];
		ListNode *b = hs[r];
		if(curr!=nullptr) {
			curr->next = a;
		}
		b->next = nullptr;
		curr = b;

		if(a!=b)
			a->next = b;

		l++;
		r--;

	}

	
    }
};