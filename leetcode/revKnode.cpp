/* 
  ---- leetcode Reverse Nodes in k-Group  pronlem ----

Given a linked list, reverse the nodes of a 
linked list k at a time and return its modified list.


k is a positive integer and is less than or 
equal to the length of the linked list. If the number of 
nodes is not a multiple of k then left-out nodes in the 
end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*/


#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node(int x){
		data = x;
	}
};

Node *head = nullptr,*tail = nullptr;
Node *newHead = nullptr;
Node *npart;

void insertNode(int data){
	Node *n = new Node(data);
	if(head == nullptr){
		head = n;
		tail = n;
	}
	else{
		tail->next = n;
		tail = tail->next;
	}
}

void printList(Node *tmp){

	if(tmp == nullptr){
		return;
	}
	cout<<tmp->data<<" ";
	printList(tmp->next);

}

Node* revse(Node *h,int n){


	Node *curr= h;
	Node *nx = h->next;
	curr->next = nullptr;

	for(int i = 0; i < n-1 and nx!=nullptr; i++){
		Node *tmp = nx->next;
		nx->next = curr;
		npart = tmp;
		curr = nx;
		nx = tmp;
	}
	if(newHead == nullptr){
		newHead = curr; 
	}

	return curr;

}

Node* revKnode(Node *h,int k,int n){

	if(k == 1 or k >n){ // if k==1 or k > n
		return h;
	}

	Node *curr = h;
	Node *prv;
	Node *tmp;
	for(int i = 0; i < (int)n/k; i++){ // (n / k) parts of full linked list

		tmp = revse(curr,k); // reverse k size list in parts
		if(i != 0){
			prv->next = tmp;
		}
		prv = curr;
		
		//cout<<"prv "<<prv->data<<endl;
		
		curr = npart;
	}
	if(npart!=nullptr){
		prv->next = npart;
	}
	
	return newHead;
}


int main(){
	int n; cin>>n;
	int k; cin>>k;
	for(int i = 0; i < n;i++){
		int x; cin>>x;
		insertNode(x);
	}
	//revse(head,5);
	Node *newH = revKnode(head,k,n);
	printList(newH);
}	