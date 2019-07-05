/*
 rearrange LinkedList
  Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. Rearrange 
  the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …

You are required to do this in-place without altering the nodes’ value


Input:  1 -> 2 -> 3 -> 4
Output: 1 -> 4 -> 2 -> 3

Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3 
 */


#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

node *head=nullptr,*tail=nullptr;

class Solution{
	public:
	
	void push(int data){
		node *n = new node;
		n->data = data;
		if(head==nullptr){
			head = n;
			tail = n;
		}
		else{
			tail->next = n;
			tail = n;
		}
	}
	
	node* reverseList(node **head){ // func. to reverse linkedList
		
		node *prv = nullptr, *curr = *head, *nxt;
		
		while(curr){
			nxt = curr->next;
			curr->next = prv;
			prv = curr;
			curr = nxt;
		}
		//return  curr;
		*head = prv;
		return *head;
	}
	
	void rearrange(node **head){
		
		node *tmp = *head;
		while(tmp){
			 cout<<tmp->data<< " ";         // in first, traverse first element from list than,
			tmp = reverseList(&tmp->next);  // reverse list from next element (second element_) utill all list not rearranged
			//tmp = tmp->next;
		}
		
	}  // end of operational function
	
	void printList(node *tmp){
		cout<<"List element: \n";
		while(tmp!=nullptr){
			cout<<tmp->data<< " ";
			tmp = tmp->next;
		}
	}
	
};  // end of class

int main(){
	Solution ob;
	int n; cin>>n;
	
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		ob.push(x);
	}
	ob.rearrange(&head);   // call main operation function
	
	//node *res = ob.reverseList(&head);
	ob.printList(head);  // print List
}
			
		
			
			
