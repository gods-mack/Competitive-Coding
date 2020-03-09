// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int in[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        Node* root = buildTree(in, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}


Node* sol(int in[],int start,int end){

    if(start > end){
        return NULL;
    }
    int mid = (start + end) / 2;

    Node *newnode = new Node(in[mid]);
    if(start == end){
        return newnode;
    }

    newnode->left = sol(in,start,mid-1);
    newnode->right = sol(in,mid+1,end);

    return newnode;
}

Node* buildTree(int in[], int n){

    return sol(in,0,n-1);
}

