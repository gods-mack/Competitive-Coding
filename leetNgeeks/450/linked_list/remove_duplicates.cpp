

//  Remove duplicates from an unsorted linked list 
// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

Node * removeDuplicates( Node *head) 
{
 // your code goes here
    unordered_set<int> st;
    Node *tmp = head;
    while(tmp != nullptr) {
        st.insert(tmp->data);
        tmp = tmp->next;
    }
    
    tmp = head;
    Node *prv = head;
    
    while(tmp!=nullptr) {
        
        if(st.find(tmp->data) != st.end()) {
            st.erase(tmp->data);
        }
        else{
            prv->next = tmp->next;
            free(tmp);
            tmp = prv->next;
            
            continue;
        }
        
        prv = tmp;
        tmp = tmp->next;
    }
    
    return head;
    
    
}