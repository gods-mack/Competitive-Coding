

// Recursive C++ program to reverse 
// a linked list 
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
	Node* reverse(Node* node) 
	{ 
		if (node == NULL) 
			return NULL; 
		if (node->next == NULL) { 
			head = node; 
			return node; 
		} 
		Node* node1 = reverse(node->next); 
		node1->next = node; 
		node->next = NULL; 
		return node; 
	} 

	Node *rev_range(Node *head,Node *tail) {

		Node *curr = head;
		Node *prv  = tail->next;
		Node *fwd  = head;
		Node *tmp  = tail->next;

		while(curr!=tmp) {
		

			fwd = curr->next;
			curr->next = prv;
			prv = curr;
			curr = fwd;
		}
	

		return prv;
	}

	void rev_grp(int k) {

		int n = 0; // count
		Node *Head = head;

		Node *tmp = head;
		while(tmp!=NULL ) {
			n++;
			tmp = tmp->next;
		}

		int times = n/k;
		if(n%k != 0 ) { times++;}

		while(times--) {

			Node *prv = nullptr;
			Node *curr = Head;
			Node *fwd = ;

			int i = 0;
			while( i < k and curr!=NULL) {
				fwd = curr->next;
				curr->next = prv;
				prv = curr;
				curr = fwd;
			}
			Head = fwd;	
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

	//ll.reverse(ll.head); 
	int k; cin>>k;
	ll.rev_grp(k);
	cout << "\nReversed Linked list \n"; 
	ll.print(); 

	return 0; 
} 
