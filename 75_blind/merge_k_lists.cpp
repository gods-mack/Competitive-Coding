
// Hard
// https://leetcode.com/problems/merge-k-sorted-lists/

struct compare  
 {  
   bool operator()(const ListNode* h1, const ListNode* h2)  
   {  
       return h1->val > h2->val; 
   }  
 };


class Solution {
public:
 ListNode* mergeKLists(vector<ListNode*>& a) {
        
            
    int N = (int)a.size();

    priority_queue<ListNode* , vector<ListNode*> ,compare > pq; 

    if(N==0){return nullptr;}
 

    for(int i = 0; i < N;i++){
        if(a[i] != nullptr)
            pq.push(a[i]);
        
    }

    ListNode *head = nullptr;
        ListNode *tail = nullptr;

    while(!pq.empty()){

    ListNode *top_el = pq.top();
            pq.pop();
            
            if(head == nullptr){
                head = top_el;
                tail = head;
            }
            else{
                tail->next = top_el;
                tail = top_el;
                
            }
        
        
        if(top_el->next!=nullptr){
            pq.push(top_el->next);
        }
        

    }
    return head;
 }
    
    
};