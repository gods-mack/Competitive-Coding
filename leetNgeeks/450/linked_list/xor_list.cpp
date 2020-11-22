

// XOR linked list

/*
https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/
*/

#include<bits/stdc++.h>
using namespace std;


struct node {
	int data;
	node *npx; // npx = next previous xor
	node (int data_) {
		data = data_;
		npx = nullptr;
	}
};

class d_list {
	node *head = nullptr;

public:
	struct node* XOR(struct node *a, struct node *b) {

    	return (struct node*) ((size_t) (a) ^ (size_t) (b));

	}

	void insert(int data) {
		node *new_node = new node(data);

		new_node->npx = head;

		if(head != nullptr) {

			head->npx = XOR(new_node, head->npx);
		}
		head = new_node;

	}

	void print_list() {

		node *curr = head;
		node *prv = nullptr;

		while(curr!=nullptr) {

		

			cout<<curr->data<<" ";

			node *fwd = XOR(curr->npx, prv);

			prv = curr;
			curr = fwd;
		}

		cout<<"\nreverse order \n";

		curr = prv;
		node *tmp_fwd = nullptr;
		while(curr!=nullptr ){
			cout<<curr->data<<" ";

			node *prev = XOR(curr->npx,tmp_fwd);

			tmp_fwd = curr;
			curr = prev;
		} 
	}
};

int main() {

	int n; cin>>n;
	d_list ll;
	for(int i = 0; i < n; i++) {
		int x; cin>>x;
		ll.insert(x);
	}

	ll.print_list();
}