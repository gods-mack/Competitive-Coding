
// Design a stack with operations on middle element

/*

approach :
1. make a mid pointer which will point to middle of stack
2 .while pushing a leemnt increase size++
3. if(size%2 == 0 ) mid++


in POP
1. if(size%2==0) mid--



*/


#include<bits/stdc++.h>

using namespace std;

// doubly linked list
struct node {
	int data;
	node *next;
	node *prv;
	node(int data_) {
		data = data_;
		next = nullptr;
		prv  = nullptr;
	}
};

node *head_list = nullptr;



class my_stack {
public:
	node *top;
	node *mid;
	int size = 0;

	
};

void pop(my_stack &st) {

	
	if(st.size%2 == 0) {
		st.mid = st.mid->prv;
	}
	st.size--;
	node *tmp = st.top;
	st.top = st.top->prv;

	delete  tmp;

}

void push(my_stack &st, int x) {
	node *new_node = new node(x);

	if(head_list == nullptr) {
		//cout<<"HEAD NULL\n";
		head_list = new_node;
		st.mid = new_node;
		st.top = new_node;
		st.size++;
		return;
	}
	new_node->prv = st.top;

	st.top->next = new_node;
	st.top = new_node;
	st.size++;
	


	if(st.size%2 == 0) {
		st.mid = st.mid->next;
	}
}

void find_middle(my_stack &st) {

	cout<<"middle "<<st.mid->data<<endl;

}
/*
void delete_middle() {

}
*/
int main() {

	my_stack st;

	push(st,1);
	cout<<"HEAD "<<head_list->data<<endl;
	push(st,2);
	cout<<"HEAD "<<head_list->next->data<<endl;
	push(st,3);

	pop(st);
	push(st,4);
	find_middle(st);
	push(st,5);
	push(st,6);
	push(st,7);
	pop(st);
	push(st,8);
	find_middle(st);
	pop(st);
	find_middle(st);	

}