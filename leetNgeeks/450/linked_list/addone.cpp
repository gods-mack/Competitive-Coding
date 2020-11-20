
//  Add 1 to a number represented as linked list 

void add_(Node *tmp, int &carry) {

		if(tmp == NULL) {
			return;
		}

		add_(tmp->next, carry);

		if(tmp->next == NULL) {
			tmp->data += 1;
			carry = tmp->data / 10;
			tmp->data = tmp->data % 10;
		}
		else{
			tmp->data += carry;
			carry = tmp->data / 10;
			tmp->data = tmp->data % 10;
		}

}
void addone() {

		Node *last_node = head;
		while(last_node->next!=NULL) {
			last_node = last_node->next;
		}

		int carry = 0;
		if(last_node->data == 9) {
			add_(head, carry);
		 
			if(carry == 1) {
				//cout<<"we have carry\n";
				Node *new_node = new Node(1);
				new_node->next = head;
				head = new_node;
			}
		}
		else{
			last_node->data += 1;
		}
}



/*
#include <iostream> 
using namespace std; 

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
	Node(int data) 
	{ 
		this->data = data; 
		next = NULL; 
	} 
}; 

struct LinkedList { 
	Node* head; 
	Node *tail;
	LinkedList() 
	{ 
		head = NULL; 
	} 

	/* Function to reverse the linked list */

	void add_(Node *tmp, int &carry) {

		if(tmp == NULL) {
			return;
		}

		add_(tmp->next, carry);

		if(tmp->next == NULL) {
			tmp->data += 1;
			carry = tmp->data / 10;
			tmp->data = tmp->data % 10;
		}
		else{
			tmp->data += carry;
			carry = tmp->data / 10;
			tmp->data = tmp->data % 10;
		}

	}
	void addone() {

		Node *last_node = head;
		while(last_node->next!=NULL) {
			last_node = last_node->next;
		}

		int carry = 0;
		if(last_node->data == 9) {
			add_(head, carry);
		 
			if(carry == 1) {
				//cout<<"we have carry\n";
				Node *new_node = new Node(1);
				new_node->next = head;
				head = new_node;
			}
		}
		else{
			last_node->data += 1;
		}
	}

	/* Function to print linked list */
	void print() 
	{ 
		struct Node* temp = head; 
		while (temp != NULL) { 
			cout << temp->data << " "; 

			temp = temp->next; 
		} 
	} 

	void push(int data) 
	{ 
		Node* temp = new Node(data); 
		if(head==NULL){
			head = temp;
			tail = temp;
			return;
		}
		tail->next = temp;
		tail = temp;	
	} 
}; 

/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	LinkedList ll; 
	int n; cin>>n;
	while(n-- ){
		int x; cin>>x;
		ll.push(x);
	}
 	 

	cout << "Given linked list\n"; 
	ll.print(); 
	cout<<endl;

	ll.addone();


	return 0; 
} 

*/*/