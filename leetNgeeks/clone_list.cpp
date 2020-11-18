


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node *nhead = nullptr; // newhead
        
        Node *tmp = head;
        Node *tail;
        
        unordered_map<Node*,Node*> hs;
        
        while(tmp!=nullptr) {
            if(nhead == nullptr){
                Node *n = new Node(tmp->val);
                nhead = n;
                tail  = n;
                hs[tmp] = n;
            }
            else{
                Node *n = new Node(tmp->val);
                tail->next= n;
                tail = n;
                hs[tmp] = n;
            }
            tmp = tmp->next;
        }
        
        tmp = head;
        Node *curr = nhead;
        
        while(tmp!=nullptr) {
            
            Node *rn = hs[tmp->random];
            curr->random = rn;
            tmp = tmp->next;
            
            curr = curr->next;
            
        }
        
        return nhead;
        
        
    }
};