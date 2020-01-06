
// merege k sorted list

// time complexity O( Nlog(k))  N = number of element in largest list and  k is number of lists

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

struct compare  
 {  
   bool operator()(const Node* h1, const Node* h2)  
   {  
       return h1->data > h2->data; 
   }  
 };




void tra(Node *tmp){
	while(tmp!= nullptr){
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
}

// merege k sorted LIst
Node* kmerge(vector<Node*> a,int N){

	priority_queue<Node* , vector<Node*> ,compare > pq; 

	Node *res = new Node(-1); // dummy head
	Node *curr = res;

	for(int i = 0; i < N;i++){  // inseert all front elemnt of every list
		pq.push(a[i]);
	}

	while(!pq.empty()){

		Node *tmp = pq.top();
		pq.pop();
		//cout<<"nikla "<<tmp->data<<endl;
		curr->next = new Node(tmp->data);	
		curr = curr->next;

		if(tmp->next!=nullptr){
			//cout<<"dala "<<tmp->next->data<<endl;
			pq.push(tmp->next);
		}

	}
	return res->next;
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
		Node *res = kmerge(a,N);
		tra(res);

	}
	
}