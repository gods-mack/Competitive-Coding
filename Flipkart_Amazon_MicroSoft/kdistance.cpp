

/*
Given a root of a tree, and an integer k. Print all
 the nodes which are at k distance from root. 

 */

	// function should print the nodes at k distance from root
void printKdistance(struct Node *root, int k)
{
  // Your code here
  
  if(root == nullptr) {
      return;
  }
  if(k == 0){
      cout<<root->data<<" ";
      return ;
  }
  else{
      printKdistance(root->left, k-1);
      printKdistance(root->right, k-1);
  }
    
  
}
