
// Add two numbers represented by linked lists 
/*
Example: 

Input:
  First List: 5->6->3  // represents number 563
  Second List: 8->4->2 //  represents number 842
Output
  Resultant list: 1->4->0->5  // represents number 1405

  */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct node{
	int data;
	node *next;
};


void push2List(node **head,int data){

   node *n = new node;
   n->data = data;
   n->next = *head;
   *head = n;
	

}

void swapPointer(node** head1,node** head2){

	node *tmp = *head1;
	*head1 = *head2;
	*head2 = tmp;

}

int getSize(node *tmp){
	int count=0;
	while(tmp!=NULL){
		tmp = tmp->next;
		count++;
	}
	return count;
}

void printList(node *tmp){

	while(tmp!=NULL){
		cout<<tmp->data<<" ";
		tmp  = tmp->next;
		
	}
}

// This function is called after the smaller list is added to the bigger 
// lists's sublist of same size.  Once the right sublist is added, the carry 
// must be added toe left side of larger list to get the final result. 
void addRemain(node *head,node *curr,node** res,int *carry ){
    
    int sum = 0;

	if(head!=curr){

		addRemain(head->next,curr,res,carry);

		sum = head->data + *carry;
		*carry = sum/10;
		sum  = sum%10;

		push2List(res,sum);



	}

}

node* addSameSize(node *head1,node *head2,int *carry){

    if(head1==NULL){
    	return NULL;
    }
	int sum=0;
    node *result = new node;
    // Recursively add remaining nodes and get the carry
	result->next = addSameSize(head1->next,head2->next,carry);

	sum  = head1->data + head2->data + *carry;
	*carry = sum/10;
	sum = sum%10; 
	result->data = sum;

	return result;



}

void addList(node *head1,node *head2,node **res){

	int size1 = getSize(head1);
	int size2 = getSize(head2);
    int carry = 0;
    
	if(size1==size2){  // if both list have same number of digits

		*res = addSameSize(head1,head2,&carry);

	}
	else{
       
        if(size1<size2){
        	swapPointer(&head1,&head2);
        }
		int diff = abs(size1-size2);
        node *curr = head1;
		for(int i=0;i<diff;i++){
			curr = curr->next;

		}

		*res = addSameSize(curr,head2,&carry);
		addRemain(head1,curr,res,&carry);

	}
    
    // add carry in last moment
	if(carry){
		push2List(res,carry);
	}

	


}


int main(){

	vector<int> first = {3,3,4,3,2};
	vector<int> second = {8,3,6,2,6,8,9};

	node *head1=NULL,*head2=NULL,*result=NULL;

	for(int i=first.size()-1;i>=0;i--){
		push2List(&head1,first[i]);
	}
	for(int i=second.size()-1;i>=0;i--){
		push2List(&head2,second[i]);
	}

	//	printList(head1);
	
    addList(head1,head2,&result);

    printList(result);
	

	//addList(head1,head2,&result)
}