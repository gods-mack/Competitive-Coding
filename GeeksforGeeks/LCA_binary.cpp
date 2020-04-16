
// print the boundry element  of binary tree in anticlockwise


#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void path_(int n, Node *root,vector<int>&tmp,vector<int> &path){

	if(root == NULL){
		return;
	}
	tmp.push_back(root->data);
	if(root->data == n){
		for(auto x: tmp){
			//cout<<x<<" ";
			path.push_back(x);
		}
		return;
	}else{
		path_(n,root->left,tmp,path);
		path_(n,root->right,tmp,path);

		tmp.pop_back();
	}
}


void LCA(int a, int b, Node *root){

	vector<int> path1;
	vector<int> path2;
	vector<int> tmp;

	path_(a,root,tmp,path1);
	tmp.clear();
	path_(b,root,tmp,path2);
	if(path1.size() < path2.size()){
		swap(path1,path2);
	}

	for(int i = 0; i < path1.size()-1; i++){
		if(path1[i+1] != path2[i+1]){
			cout<<"LCA "<< path1[i];
			break;
		}
	}

}



/* Driver program to test above functions*/
int main(){
	int t;
  	scanf("%d", &t);
  	while (t--){
    	map<int, Node*> m;
    	int n;
    	scanf("%d",&n);
     	Node *root = NULL;
     	while (n--){
        	Node *parent;
        	char lr;
        	int n1, n2;
        	scanf("%d %d %c", &n1, &n2, &lr);
      	//  cout << n1 << " " << n2 << " " << (char)lr << endl;
        	if (m.find(n1) == m.end()){
           		parent = new Node(n1);
           		m[n1] = parent;
           		if (root == NULL)
             		root = parent;
        	}
        	else
           		parent = m[n1];
        	Node *child = new Node(n2);
        	if (lr == 'L')
          		parent->left = child;
        	else
          		parent->right = child;
        	m[n2]  = child;
    	}

    	int q; cin>>q;
    	while(q--){
    		int a,b;
    		cin>>a>>b;
  			LCA(a,b,root);
   			cout<<endl;
   		}
  	}
    return 0;
}



