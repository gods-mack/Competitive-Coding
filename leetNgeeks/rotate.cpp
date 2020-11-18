

#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *next;

};

node *head = nullptr;
node *tail = nullptr;

void ins(int data) {
	if(head == nullptr ){
		node *n = new node;
		n->data = data;
		n->next = nullptr;
		head = n;
		tail  = n;
	}
	else{
		node *n = new node;
		n->data = data;
		n->next = nullptr;
		tail->next = n;
		tail = tail->next;
	}
}

void pList(node *tmp) {

	node *tmp1 = tmp;
	while(tmp1!=nullptr) {
		cout<<tmp1->data<<" ";
		tmp1 = tmp1->next;
	}
}

node *rotate(node *head, int k) {

	node *nhead = head;
	node *prv;

	k--;
	while(k--) {
		prv = nhead;
		nhead = nhead->next;
	}
	prv->next = nullptr;




	node *tmp = nhead;
	while(tmp->next!=nullptr) {
		tmp = tmp->next;
	}
	tmp->next = head;
	cout<<tmp->next->data<<endl;



	return nhead;

}


int main() {
	int n; cin>>n;
	while(n--) {
		int x; cin>>x;
		ins(x);

	}
	//pList(head);
	int k; cin>>k;
	node *ro = rotate(head,k);
	pList(ro);

}