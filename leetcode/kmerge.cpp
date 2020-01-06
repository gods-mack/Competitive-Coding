
// merege k sorted list
#include<bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	Node *next;
	Node(int x){
		data = x;
		next = nullptr;	
	}
};
Node *curr,*head=nullptr;



void printList(vector<Node*> a){

	int n = a.size();

	for(int i = 0; i < n;i++){
		Node *tmp = a[i];
		while(tmp!=nullptr){
			cout<<tmp->data<<"->";

			tmp = tmp->next;
		}
		cout<<endl;
	}
}

Node* kmerge(vector<Node*> a,int N){
	Node *res = nullptr;
	for(int k = 0; k <N;k++){

		int n1 = (int)a[k].size();
		int n2 = (int)a[k+1].size();
		Node *head1 = a[k];
		Node *head2 = a[k+1];
		k++;
		int l = 0;
		int r = 0;
		node *curr;

		while(l < n1 and r<n2){

			if(head1.data === head2.data){
				if(res==nullptr){
					curr = new Node(a[l]);
					curr->next = Node(a[l]);
					res = curr;
					curr = curr->next;
				}
				else{
					 Node *tmp = new Node(a[l]);
					 curr->next = tmp;
					 curr = tmp;
					 curr->next = new Node(a[r]);
					 curr = curr->next;
				}
				l++;
				r++;
			}
			else if(head1.data > head2.data){
				
				r++;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	
	while(t--){

		int N; // no of lists
		cin>>N;
		vector<Node*> a(N);
		for(int i = 0; i < N; i++){
			int n;cin>>n;
			int x; cin>>x;
			if(head == nullptr){
				a[i] = new Node(x);
				curr = a[i];
				head = curr;
			}
			else{
				a[i] = new Node(x);
				curr = a[i];

			}
			n--;
			for(int i = 0; i < n; i++){
				int x; cin>>x;
				Node *tmp = new Node(x);
				curr->next = tmp;
				curr = tmp;
			}


		}
		printList(a);
	}
	
}