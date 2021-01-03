

//  Top View of Binary Tree 	

void topView(struct Node *root)
{
    //Your code here
    map<int,Node* > umap;
    unordered_map<Node*,int> u_hd;
    if(root == nullptr) {
        return;
    }
  
	queue<Node*> q;
	u_hd[root] = 0;
	q.push(root);
	while(!q.empty()) {
		
		auto curr = q.front();
		q.pop();
		int curr_hd = u_hd[curr];
		
		if(umap.count(curr_hd) == 0){
			umap[curr_hd] = curr;
		}
		if(curr->left != nullptr){
			u_hd[curr->left] = curr_hd-1;
			q.push(curr->left);
		}
		if(curr->right != nullptr) {
			u_hd[curr->right] = curr_hd+1;
			q.push(curr->right);
		}
	}
	
    
    for(auto it=umap.begin(); it!=umap.end(); ++it) {
        
        auto v = it->second;
        cout<<v->data<<" ";
    }
    
    
}