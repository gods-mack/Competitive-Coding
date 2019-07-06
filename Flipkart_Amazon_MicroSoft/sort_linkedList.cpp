/*
Given a linked list of N nodes where nodes can contain values 0s, 1s and 2s only.
The task is to segregate 0s, 1s and 2s linked list such that all zeros segregate to headside,
2s at the end of the linked list and 1s in the mid of 0s and 2s.
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
        
        void sort(node *head){
                node *tmpout = head;
                node *tmpin = head;
                while(tmpout!=nullptr){
                        tmpin = head;
                        while(tmpin->next!=nullptr){
                                if(tmpin->data > tmpin->next->data){
                                        int tempo = tmpin->data;
                                        tmpin->data = tmpin->next->data;
                                        tmpin->next->data = tempo;
                                }
                                tmpin = tmpin->next;
                        }
                        
                        tmpout = tmpout->next;
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
        int n;
        cin>>n;
        while(n--){
                int x; cin>>x;
                ob.push(x);
        }
        ob.printList(head);
        ob.sort(head);
        cout<<endl;
        ob.printList(head);
}
                
                
                
                
                
                
                
                
                
                
                

