
/*
Given a matrix. Convert it into a linked list matrix 
such that each node 
is connected to its next right and down node.

*/


#include <bits/stdc++.h>
#define MAX 20
using namespace std;

struct Node
{
	int data;
	Node* right, *down;
	
	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};

void display(Node* head)
{
    Node* Rp;
	Node* Dp = head;
	while (Dp) {
		Rp = Dp;
		while (Rp) {
			cout << Rp->data << " ";
			Rp = Rp->right;
		}
		
		Dp = Dp->down;
	}
}

Node* constructLinkedMatrix(int mat[MAX][MAX], int n);

// driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mat[MAX][MAX];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        Node* head = constructLinkedMatrix(mat, n);
        if(!head)cout<<"-1";
	    else display(head);
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends

// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]
Node* constructLinkedMatrix(int mat[MAX][MAX], int size)
{
   	Node *head = nullptr;

   	Node *dp = nullptr;  // down pointer to go along with downside of 2d array


   	Node *n = new Node(mat[0][0]);
   	head = n;
   	dp = n;
   	int i = 0;

   	while(i < size){
   		Node *tail = dp;
   		for(int j = 1; j<size; j++){
   		   		Node *n = new Node(mat[i][j]);
   		   		tail->right = n;
   		   		tail = n;
   		}
   		i = i + 1;
   		if(i == size){
   			break;
   		}
   		else{
   			Node *nd = new Node(mat[i][0]);
   			dp->down = nd;
   			dp = nd;
   		}

   	}

   	return head;
}
