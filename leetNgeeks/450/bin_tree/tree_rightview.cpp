vector<int> rightView(Node *root)
{
   // Your Code here
   vector<int> ans;
   if(root == nullptr) {
       return ans;
   }
   queue<Node*> q;
   q.push(root);
    
   while(!q.empty()) {
       
       int size = q.size();
       for(int i =0 ; i < size; i++) {
           
           auto curr = q.front();
           q.pop();
           if(i == size-1) {
               ans.push_back(curr->data);
           }
           
           if(curr->left!=nullptr) {
               q.push(curr->left);
           }
           if(curr->right!=nullptr) {
               q.push(curr->right);
           }
       }
   }
   return ans;
   
}