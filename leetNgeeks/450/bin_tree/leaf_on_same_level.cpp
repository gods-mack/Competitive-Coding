
// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1
//  Leaf at same level 


bool leaf_check(Node *root,int &first_depth,int level) {
    
    if(root==nullptr){
        return true;
    }
    
    if(root->left==nullptr and root->right==nullptr) {
       
       if(first_depth == 0) {
            first_depth = level;
       }
       
       return level == first_depth;
    }
    
   return  leaf_check(root->left,first_depth,level+1) &&
    leaf_check(root->right,first_depth, level+1);
    
   // return true;
}


bool check(Node *root)
{
    //Your code here
    
    int first_depth = 0;
    
    int level = 0;
    if(leaf_check(root,first_depth,level)) {
        return true;
    }
    return false;
    
}