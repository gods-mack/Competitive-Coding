


#include<bits/stdc++.h>
using namespace std;


// iterative
node* rev_list(node *head) {

	node *curr = head;
	node *prv  = nullptr;
	node *fwd  = head;

	while(curr!=nullptr) {
		fwd = curr->next;
		curr->next = prv;
		prv = curr;
		curr = fwd;
	}

	return prv;
}

// recursive



int main() {
	
}