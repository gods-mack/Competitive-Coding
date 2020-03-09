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

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

Node* sol(int in[],int post[],int &pindex,int start,int end,map<int,int>mp){
 
    if(start > end){
        return NULL;
    }   
    int curr = post[pindex--];
    Node *newnode = new Node(curr);

    if(start == end){
        return  newnode;
    }

    int index = mp[curr];
    newnode->right = sol(in,post,pindex,index+1,end,mp);
    newnode->left = sol(in,post,pindex,start,index-1,mp);

    return newnode;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    map<int,int> mp;
    for(int i = 0; i <n; i++){
        mp[in[i]] = i;
    }
    int pindex = n-1;
    return sol(in,post,pindex,0,n-1,mp);
    
}
