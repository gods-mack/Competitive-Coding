
// https://practice.geeksforgeeks.org/problems/expression-tree/1

#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}

int evalTree(node*);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
     		node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }

        cout<<evalTree(root)<<endl;
    }
}


/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

/*You are required to complete below method */


/*void post(node *root) {

	if(root==NULL){
		return;
	}

	post(root->right);
	post(root->left);

}*/


int evalTree(node* root) {
    // Your code here

    if(isExpression(root->data) ){
    	int a = evalTree(root->left);
    	int b = evalTree(root->right);
    	
    		if(root->data =="+")
    			return a+b;
    		else if(root->data == "-")
    			return a-b;
    		else if(root->data == "*")
    			return a*b;
    		else if(root->data == "/")
    			return a/b;			
    	
    }

    return stoi(root->data);






}
