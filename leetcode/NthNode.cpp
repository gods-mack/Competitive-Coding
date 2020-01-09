
// remove nth node from the End of a linked list

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node(int x){
		data = x;
		next = nullptr;
	}
};

Node *head = nullptr,*tail=nullptr;

void printList(Node *tmp){
	while(tmp!=nullptr){
		cout<<tmp->data << " ";
		tmp = tmp->next;
	}
}

void insertList(int data){

	if(head==nullptr){
		head = new Node(data);
		tail = head;
	}
	else{
		tail->next = new Node(data);
		tail = tail->next;
	}
}

Node* removeNthNode(Node *head,int n){

	if(head==nullptr or head->next==nullptr){
		return nullptr;
	}

	int size = 0;
	Node *tmp = head;
	while(tmp!=nullptr){
		size++;
		tmp = tmp->next;
	}

	if(size < n){  // out of bound
		return head;
	}
	if((size-n)+1 == 1){ // when head to be deleted
		head = head->next;
		return head;
	}

	tmp = head;

	Node *prv;
	for(int i = 1; i <=(size-n)+1; i++){
		if(i == (size-n)+1){
			prv->next = tmp->next;
		}
		prv = tmp;
		tmp = tmp->next;

	}

	return head;
}


int main(){
	int size;
	cin>>size;
	for(int i = 0; i < size; i++){
		int x; cin>>x;
		insertList(x);
	}
	int n; cin>>n;
	Node *newhead = removeNthNode(head,n);

	printList(newhead);

}
