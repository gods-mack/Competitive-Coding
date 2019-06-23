/*
Given a singly linked list of size N. The task is to swap elements pairwise

Input:
First line of input contains number of testcases T. For each testcase, 
first line of input contains length of linked list and next line contains linked list data.

Output : 
 print List after swappped

Example:
1 2 2 4 5 6 7 8

Output:
2 1 4 2 6 5 8 7


*/


#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:

    void swapPairs(ListNode *head){
		
		ListNode *tmp  = head;
		

		while(tmp!=nullptr and tmp->next!=nullptr){
			
			swapPointer(&tmp->val, &tmp->next->val);
			
			tmp = (tmp->next)->next;
			
			
		}
		
		
	}
    
    void swapPointer(int *a,int *b){
        
       int tmp = *a;
       *a = *b;
       *b = tmp;
        
    }
    
    
    
    
    
};  // end of class


void printList(ListNode *head){
	
	while(head!=nullptr){
		cout<<head->val<<" ";
		head = head->next;
	}
}

	
	
int main(){
	
	Solution ob;
	
	ListNode *head = new ListNode(2);
	ListNode *h2 = new ListNode(4);
	head->next = h2;
	ListNode *h3 = new ListNode(6);
	h2->next = h3;
	ListNode *h4 = new ListNode(7);
	h3->next = h4;
	ListNode *h5 = new ListNode(9);
	h4->next = h5;
	
	printList(head);
	cout<<"\n";
	ob.swapPairs(head);
	printList(head);
	
	
}
	
	
	
	
	
	
	

  
