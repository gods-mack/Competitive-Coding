
// Medium
// https://leetcode.com/problems/reorder-list/

class Solution {
public:
    void reorderList(ListNode* head) {
        
        vector<ListNode*> ind;
        
        ListNode *th = head;
        
        while(th!=nullptr){
            ind.push_back(th);
            th = th->next;
        }
        
        th = head;
        
        int N = ind.size();
        if(N%2 != 0){
            N++;
        }
       
        for(int i=0; i < N/2; i++){
            cout<<ind[i]->val<<endl;
            if(i > 0){
                ind[i-1]->next->next = ind[i];
            }
            ind[i]->next = ind[ind.size()-(i+1)];
            ind[i]->next->next = nullptr;
        }
       // return head;
    }
};