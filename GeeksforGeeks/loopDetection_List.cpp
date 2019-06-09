
// print/detect or  Find first node of loop in a linked list

#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
	
};

node* insertData(int data){

	node *n = new node;
	n->data = data;
	n->next = nullptr;

	return n;
}

void printList(node* tmp){

	while(tmp!=nullptr){
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
}

void detectLoop(node *head){

	node *tmp = head;

	while(1){
        tmp->data = tmp->data*(-1);
        tmp = tmp->next;

        if(tmp->data<0){
        	cout<<tmp->data*-1<<" detected node (Loop node) ";
        	break;

        }

	}

}




int main(){

	node *head = nullptr;

	head = insertData(1);
	head->next = insertData(2);
	head->next->next = insertData(3);
	head->next->next->next = insertData(4);
	head->next->next->next->next = insertData(5);
	head->next->next->next->next->next= head->next->next;

	//printList(head);

	detectLoop(head);


}