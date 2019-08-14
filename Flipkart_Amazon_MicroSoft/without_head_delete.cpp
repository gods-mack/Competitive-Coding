
/*
You are given a pointer/ reference to the node which is to be deleted from the
linked list of N nodes. The task is to delete the node. Pointer/ reference to head node is not given. 

Note: No head reference is given to you.

*/


#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node(int x){
		data = x;
		next = nullptr;
	}

};

Node *head = nullptr; // global header
Node *tail  = nullptr;

Node* findNode(Node *head, int search){
	Node *tmp  = head;
	while(tmp != nullptr){
		if(tmp->data == search){
			break;
		}
		tmp = tmp->next;
	}
	return tmp;
}

void insert(int data){

	Node *n  = new Node(data);
	if(head == nullptr){
		head = n;
		tail = n;
	}
	else{
		tail->next = n;
		tail = n;
	}


}



void printList(Node *head){
	Node *tmp = head;
	while(tmp != nullptr){
		cout<<tmp->data<< " ";
		tmp = tmp->next;
	}
}

// main operation function
void deleteNode(Node *tmp){
	//Node *tmp = ptr;

	while(1){
		int nextData  = tmp->next->data;
		tmp->data = nextData;

		if(tmp->next->next == nullptr){
			tmp->next = nullptr;
			break;
		}

		tmp  = tmp->next;


	}
}

int main(){
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		for(int i = 0; i <  n ; i++){
			int x; cin>>x;
			insert(x);
		}
		int todel ; cin>>todel;

		Node *todelete = findNode(head,todel);
		printList(head);
		cout<<endl;
		cout<<"after "<<endl;
		deleteNode(todelete);
		printList(head);

	}
}
