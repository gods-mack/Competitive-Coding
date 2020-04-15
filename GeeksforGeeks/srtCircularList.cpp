

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next ;
	node(int x){
		data = x;
		next = nullptr;
	}
};
node *root = nullptr, *tail = nullptr;


void insertList(int data){

	node *n = new node(data);

	if(root == nullptr){
		root = n;
		tail = n;
	}
	else{
		tail->next = n;
		tail = n;
	}
}

void printList(node *root,int n){

	node *tmp = root;
	cout<<tmp->data<<" ";
	while(1){
		tmp = tmp->next;
		if(tmp == root){
			 break;
		}
		cout<<tmp->data<<" ";
	}

}

node *find_head(node *random){

	node *tmp = random;
	int miN = INT_MAX;
	node *ans  = nullptr;
	int flag  = 0;
	while(1){
		
		if(random->data < miN){
			
			miN = random->data;
			ans = random;
		}
		
		random = random->next;
		if(random == tmp){
			break;
		}
	}
	return ans;
}

void insertSorted(node *random, int num){

	node *head = find_head(random);
	cout<<"hed "<<head->data<<endl;
	node *tmp = head;


	int flag = 0;
	if(head->data >= num){

	}
	while(1){

		if(head->next->data >= num && num>tmp->data){
			//cout<<"on "<<head->data<<endl;
			node *n = new node(num);
			node *tmp = head->next;
			n->next = tmp;
			head->next = n;
			flag = 1;
			break;
		}
		else if(head->data > head->next->data){
			node *n = new node(num);
			node *tmp = head->next;
			n->next = tmp;
			head->next = n;
			break;
		}
		head = head->next;
		
	}

	
}

int main(){

	int n; cin>>n;
	while(n--){
		int x; cin>>x;
		insertList(x);
	}
	tail->next = root;

	printList(root,8);
	cout<<endl;


	 srand ( time(NULL) );
	int random = rand() % n;
	node *rnd = root;
	//cout<<"rndnm "<<random<<endl;
	//  make random
	for(int i = 0; i < 2; i++){
		rnd = rnd->next;
	}

	int num; cin>>num;
	insertSorted(rnd,num);


	printList(root,10);



}