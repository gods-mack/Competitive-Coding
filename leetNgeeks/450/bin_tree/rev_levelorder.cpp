
// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<vector<int>> ans;
    
    if(root==nullptr) {
        return ans;
    }
    
    queue<Node*> q;
    stack<int> st;
    q.push(root);
    
    while(!q.empty()) {
        
        int size = q.size();
    
        while(size--) {
            auto curr = q.front();
            q.pop();
            st.push(curr->data);
            if(curr->right!=nullptr) {
                q.push(curr->right);   
            }
            if(curr->left!=nullptr) {
                q.push(curr->left);
            }
        }
    }
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}