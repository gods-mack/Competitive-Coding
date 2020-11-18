
// check mirror in N-array Tree

#include<bits/stdc++.h>
using namespace std;

struct node {
	//int data ;
	int left;
	int right;
};

int main() {

	int N; cin>>N;
	int e; cin>>e;

	node tree[N];
	map<int,node*> tree1,tree2;

	for(int i = 0; i < e; i++) {
		int rt; cin>>rt;
		int side; cin>>side;

		if(tree1.find(rt) == tree1.end()) {
			node *n = new node();
			n->left = side;
			n->right = -1; // right not fulled nyet
			tree1[rt] = n;
		}
		else{
			node *n = tree1[rt];
			n->right = side;
		}
	}
	// tree2
	for(int i = 0; i < e; i++) {
		int rt; cin>>rt;
		int side; cin>>side;

		if(tree2.find(rt) == tree2.end()) {
			node *n = new node();
			n->left = side;
			n->right = -1; // right not filled yet
			tree2[rt] = n;
		}
		else{
			node *n = tree2[rt];
			n->right = side;
		}
	}

	auto it2 = tree2.begin();
	int flag = 1;
	for(auto it = tree1.begin(); it!=tree1.end();++it,++it2){

		int left1 = it->second->left;
		int right1 = it->second->right;
		int left2 = it2->second->left;
		int right2 = it2->second->right;
		cout<<left1<<" "<<right1<<endl;
		cout<<left2<<" "<<right2<<endl;
		
		if(left1==-1 or right1==-1){
			if(left1!=left2 or right2!=right1){
				flag = 0;
				break;
			}
		}
		else if(left1!=right2 or right1!=left2){
			//cout<<"not mirror\n";
			flag = 0;
			break;
		}
	}

	if(flag) {
		cout<<1<<endl;
	}
	else{
		cout<<0<<endl;
	}

	
}