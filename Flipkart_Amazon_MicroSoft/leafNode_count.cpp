/* Number of Leaf Node in Binary tree */


int countLeaves(Node* root)
{
    if(!root){
        return 0;
    }
    if(root->left==NULL and root->right==NULL){
        return 1;
    }
    int l = countLeaves(root->left);
    int r = countLeaves(root->right)
    ;
    return l+r;
}
