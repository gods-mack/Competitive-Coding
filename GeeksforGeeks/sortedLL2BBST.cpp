
// sorted linked list to balanced BST

#include<bits/stdc++.h>

using namespace std;

struct llnode {
	int data;
	llnode *next;
	
};

struct tnode {
	int data;
	tnode *left,*right;

};

void insertLL(llnode** head,int data){

	llnode *n = new llnode();
	n->data = data;
	n->next = *head;

	*head = n;

}
void printList(llnode *node)  
{  
    while(node!=NULL)  
    {  
        cout << node->data << " ";  
        node = node->next;  
    }  
}

int countNode(llnode *tmp) {

	llnode *tt = nullptr;
	int count = 0;
	while(tmp!=tt){
		tmp = tmp->next;
		count++;
	}
	return count;
}  


tnode *ll2bbstUtil(llnode **head,int l,int r) {

	if(l > r) {
		return nullptr;
	}
	if(l <= r){
		int mid = (l+r)/2;

		int i = 0;
		llnode *tmp = *head;
		while(i < mid && tmp->next!=nullptr){
			tmp = tmp->next;
			i++;
		}
		tnode *n = new tnode();
		n->data = tmp->data;
		n->left = nullptr;
		n->right = nullptr;
		tnode *root = n;
		root->left = ll2bbstUtil(head,l,mid-1);
		root->right = ll2bbstUtil(head,mid+1,r);

		return root;
	}
}

tnode *ll2bbst(llnode *head) {

	int n = countNode(head);

	return ll2bbstUtil(&head,0,n-1);
}

/*
tnode *insertTree(tnode *root, int data){

	if(root == nullptr) {
		tnode *n = new tnode();
		n->data = data;
		n->left = nullptr;
		n->right = nullptr;
		return n;
	}
	else{
		if(root->data > data){
			root->left = insertTree(root->left,data);
		}
		else if(root->data < data){	
			root->right = insertTree(root->right,data);
		}
	}

	return root;
}
*/

void preorder(tnode *tmp) {
	if(tmp == nullptr){
		return;
	}
	cout<<tmp->data<<" ";
	preorder(tmp->left);
	preorder(tmp->right);
}

int main() {

	llnode *head = nullptr;
	insertLL(&head, 7);  
    insertLL(&head, 6);  
    insertLL(&head, 5);  
    insertLL(&head, 4);  
    insertLL(&head, 3);  
    insertLL(&head, 2);  
    insertLL(&head, 1);  

    printList(head);
    cout<<endl;

    tnode *root = ll2bbst(head);

   /* for(int i = 0; i < 7; i++) {
    	int x; cin>>x;
    	root = insertTree(root,x);
    };*/

   // cout<<"root "<<root->data<<endl;

    preorder(root);




}