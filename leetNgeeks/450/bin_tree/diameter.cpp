int height(Node *root ) {
    if(root == nullptr){
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    if(l > r) {
        return 1 + l;
    }
    else{
        return 1 + r;
    }
}

void helper(Node *root, int &ans) {
    if(root == nullptr){
        return ;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    
    ans = max(ans, 1+lh+rh);
    helper(root->left,ans);
    helper(root->right,ans);
}

int diameter(Node* node) {
    // Your code here
    int ans =0 ;
    helper(node, ans);
    return ans;
    
}