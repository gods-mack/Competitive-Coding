/*
remove loop from LinkedList

inputs in code :

First line of input contains number of testcases T. T testcases follow. For each testcase, 
first line of input contains length N of the linked list and next line contains N data of the linked list. 
The third line contains the position of the node(from head)
to which the last node will get connected. If it is 0 then there is no loop.

*/


#include<iostream>
using namespace std;

struct node{
        int data;
        node *next;
        node(int x){
                data = x;
                next = nullptr;
        }
};

node *head = nullptr; node* tail = nullptr;
class Solution{
        public:
        void push(int data){
                node *n = new node(data);
                if(head==nullptr){
                        head = n;
                        tail = n;
                }else{
                        tail->next = n;
                        tail = n;
                }
        }
        void makeLoop(node *head,int pos){
                if (pos == 0)
                        return;
                node* curr = head;
                node* last = head;
                int counter = 0;
                while (counter < pos){
                        curr = curr->next;
                        counter++;
                }
                while (last->next != NULL){
                        last = last->next;
                }
               // cout<<"curr "<<curr->next<<endl;
                last->next = curr;
        }
                
        int detectLoop(node *head){
                node *slow = head;
                node *fast = head;
                while(slow!=nullptr and fast!=nullptr and fast->next!=nullptr){
                        fast = fast->next->next;
                        slow = slow->next;
                        if(slow == fast){
                                cout<<"slow and fast "<<slow->data<<" "<<fast->data<<endl;
                                return 1;
                        }
                }
                return 0;
        }
        
        void remove(node* head,node* f){
                                
                node* s=head;
                while(s!=f)
                {
                        s=s->next;
                        f=f->next;
                }
                //cout<<"s f "<<s->data<<" "<<f->data<<endl;
                while(s->next!=f)
                        s=s->next;
                //cout<<"in last "<<s->data<<endl;        
    
                s->next=NULL;
    
        }

        void removeTheLoop(node *head)
        {
                node* s=head,*f=head;
             
                while(s&&f&&f->next){
             
                        f=f->next->next;
                        s=s->next;
                        if(s==f)
                        {
                                remove(head,f);
                                return;
                        }
                }
        }

        
        
        void printList(node *tmp){
                while(tmp!=nullptr){
                        cout<<tmp->data<<" ";
                        tmp = tmp->next;
                }
        }
        
};

int main(){
        Solution ob;
        int T; cin>>T;
        
        while(T--){  // testaCases Loop
        int n;
        cin>>n;
        while(n--){
                int x; cin>>x;
                ob.push(x);
        }
        int pos; cin>>pos;
        ob.makeLoop(head,pos);
        cout<<ob.detectLoop(head);
       // ob.sort(head);
        cout<<endl;
        ob.removeTheLoop(head);
        cout<<"after removel of loop "<<endl;
        ob.printList(head); }
}
                
                
                
                
                
                
                
                
                
                
                


