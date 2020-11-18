
#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
	node(int data_){
		data = data_;
		left = nullptr;
		right = nullptr;
	}
		
};


class  tree{
public:
	node *root = nullptr;
	void insert_t(node *,int data);
	void inorder(node*);
	int height(node*);
	node *lca(int,int,node*);
	void depth_list(node*);
	bool isBalanced(node*);

	void ino_successor(node*,int,node* &);
	bool find_path(node*,int,vector<int> &a);
	void nodes_distance(node*,int,int);
	void maxDiff(node*,int &a);

	void dimater(node *);

	void modify(node *, int&);
};

void tree::insert_t(node *tmp, int data) {

	if(root == nullptr){
		node *n = new node(data);
		root = n;
		cout<<"ROOT is "<<root->data<<endl;
	}
	else if(tmp->data > data){
		if(tmp->left!=nullptr){
			insert_t(tmp->left,data);
		}
		else{
			node *n = new node(data);
			tmp->left = n;
		}
	}
	else if(tmp->data < data){
		if(tmp->right!=nullptr){
			insert_t(tmp->right,data);
		}
		else{
			node *n = new node(data);
			tmp->right = n;
		}
	}
	else{
		cout<<"already exist.!!\n";
		return;
	}
}

void tree::inorder(node *tmp){
	if(tmp==nullptr){
		return;
	}
	inorder(tmp->left);
	cout<<tmp->data<<" ";
	inorder(tmp->right);
}


int tree::height(node *tmp){
	if(tmp == nullptr){
		return 0;
	}
	int l = height(tmp->left);
	int r = height(tmp->right);
	if(l > r){
		return l + 1;
	}
	return r + 1;
}

node* tree::lca(int a,int b,node *tmp){

	if(tmp==nullptr){
		return nullptr;
	}
	else if(tmp->data > a && tmp->data > b){
		return lca(a,b,tmp->left);
	}
	else if(tmp->data < a && tmp->data < b){
		return lca(a,b,tmp->right);
	}
	else{
		return tmp; // answer
	}

}

void tree::depth_list(node *rt){

	if(rt==nullptr)
		return;

	queue<node*> q;
	q.push(rt);
	while(!q.empty()){

		int q_size = q.size();
		list<node*> l_list;

		while(q_size--){
			node *tmp =  q.front();
			q.pop();
			l_list.push_back(tmp);
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);

		}
		cout<<"List: ";
		for(auto it=l_list.begin();it!=l_list.end();++it){
			cout<<(*it)->data<<" ";
		}
		cout<<endl;
	}
}

bool tree::isBalanced(node *rt){


	if(rt==nullptr){
		return true;
	}
	int l = height(rt->left);
	int r = height(rt->right);

	if(abs(l-r) > 1){
		//cout<<"this is not balanced tree\n";
		return false;
	}
	
	return isBalanced(rt->left) && isBalanced(rt->right);

}

void tree::ino_successor(node *rt,int target,node* &pt){

	if(rt==nullptr){
		return ;
	}

	ino_successor(rt->right,target,pt);

	if(rt->data == target){

		if(pt == nullptr){
			cout<<"inS! "<<rt->data<<endl;
			return;
		}
		cout<<"inS "<<pt->data<<endl;
	}
	pt = rt;


	ino_successor(rt->left,target, pt);
}

bool checkBST(node *rt,int minn,int maxx) {
	if(rt == nullptr){
		return true;
	}

	if(minn!=0 && minn>=rt->data || maxx!=0 && maxx <= rt->data){
		return false;
	}

	return checkBST(rt->left,minn,rt->data)&&checkBST(rt->right,rt->data,maxx);
}


// path as a binary tree
bool tree::find_path(node *rt, int x,vector<int>&path) {

	if(rt==nullptr){
		return false;
	}
	path.push_back(rt->data);
	if(rt->data == x ){
		return true;
	}

	if(find_path(rt->left,x,path) || find_path(rt->right,x,path)){
		return true;
	}
	path.pop_back();
	return false;


}

void tree::nodes_distance(node *rt,int a,int b) {

	vector<int> patha;
	vector<int> pathb;

	find_path(rt,a,patha);
	find_path(rt,b,pathb);

	int i = 0;
	while(i < patha.size() and i < pathb.size()){
		if(pathb[i]!=patha[i] ){
			break;
		}
		i++;
	}
	//cout<<"i "<<i<<endl;
	int dis = 0;
	dis += patha.size()-i;
	dis += pathb.size()-i;

	cout<<"distance "<<dis<<endl;
}


void tree::maxDiff(node *rt,int &ans) {
	if(rt == nullptr){
		return ;
	}

	
	int left = INT_MIN;
	if(rt->left!=nullptr){
		left = rt->data - rt->left->data;
	}
	int right  = INT_MIN;
	if(rt->right != nullptr){
		right = rt->data - rt->right->data;
	}

	ans = max(ans,max(left,right) );

	maxDiff(rt->left,ans);
	maxDiff(rt->right,ans);


}


// add all greater values to every node in a BST
void tree::modify(node *rt, int &tmp) {

	if(rt==nullptr){
		return;
	}

	modify(rt->right,tmp);
	rt->data += tmp;
	tmp = rt->data;
	modify(rt->left,tmp);

}

int minDiff(node *rt,int k) {

	if(rt==nullptr){
		return INT_MAX;
	}

	if(rt->data <= k) {
		return min(abs(rt->data-k),minDiff(rt->right,k));
	}
	else{
		return min(abs(rt->data-k),minDiff(rt->left,k));
	
	}

}


void tree::dimater(node *root) {
	if(root == nullptr){
		return ;
	}
	int lh = height(root->left);
	int rh = height(root->right);

	ans = max(ans,1+lh+rh);
	diameter(root->left);
	diameter(root->right);

}


map<int,vector<int> > hmap;

void hdis(node *rt, int hd) {
    if(rt==nullptr){
        return ;
    }
    
    hmap[hd].push_back(rt->data);
    hdis(rt->left,hd-1);
    hdis(rt->right,hd+1);
}

int main() {
		
	tree o;
	node *tmp = o.root;
	/*o.insert_t(o.root,10);
	o.insert_t(o.root,6);
	o.insert_t(o.root,15);
	o.insert_t(o.root,7);
	o.insert_t(o.root,14);
	o.insert_t(o.root,12);
	o.insert_t(o.root,26);
	o.insert_t(o.root,21);
	o.insert_t(o.root,34);
	o.insert_t(o.root,544);
	o.insert_t(o.root,3);
	o.insert_t(o.root,1);
	*/
	o.insert_t(o.root,50);
	o.insert_t(o.root,30);
	o.insert_t(o.root,70);
	o.insert_t(o.root,60);
	o.insert_t(o.root,80);
	o.insert_t(o.root,20);
	o.insert_t(o.root,40);


	//o.root->left->data = 233;

	/*
	o.inorder(o.root);
	cout<<"\nHEIGHT "<<o.height(o.root)<<endl;
	cout<<"LCA "<<o.lca(12,16,o.root)->data<<endl;
	o.depth_list(o.root);
	if(o.isBalanced(o.root)){
		cout<<"balanced\n";
	}
	else{
		cout<<"Not balanced\n";
	}	
	
	node *next;
	next = nullptr;
	o.ino_successor(o.root,10,next);

	cout<<endl;
	cout<<checkBST(o.root,0,0)<<endl;

	/*vector<int> path;
	o.find_path(o.root,12,path);
	for(int i = 0; i < path.size(); i++) {
		cout<<path[i]<<" ";
	}
	*//*

	o.nodes_distance(o.root,1,7);

	int ans = INT_MIN;
	o.maxDiff(o.root,ans);
	cout<<"ans maxDiff "<<ans<<endl;
	
	*/

	int ttt = 0;
	//o.modify(o.root,ttt);

	o.inorder(o.root);
	cout<<endl;
	cout<<minDiff(o.root,60)<<endl;


	hdis(o.root,0);



	for(auto it=hmap.begin(); it!=hmap.end(); it++) {
        auto ve = it->second;
        cout<<"#"<<it->first<<" ";
        int sum = 0;
        for(int j = 0; j < ve.size(); j++){
           // sum += ve[j];
        	cout<<ve[j]<<" ";
        }
        cout<<endl;
        
    }





}
