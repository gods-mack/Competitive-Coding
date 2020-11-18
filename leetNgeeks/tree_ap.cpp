

#include <iostream> 
#include <queue> 
using namespace std; 
  
// A Binary Tree Node 
struct Node { 
    int data; 
    struct Node *left, *right; 
}; 
  
struct arr_with_size {
	int size;
	int *arr;
} ;
// Utility function to create a new tree node 
Node* newNode(int data) 
{ 
    Node* temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

void printArr(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << endl; 
} 

int getHeight(struct Node* root) 
{ 
    if (root->left == NULL && root->right == NULL) 
        return 0; 
  
    int left = 0; 
    if (root->left != NULL) 
        left = getHeight(root->left); 
  
    int right = 0; 
    if (root->right != NULL) 
        right = getHeight(root->right); 
  
    return (max(left, right) + 1); 
} 

void calculateLevelSum(struct Node* node, int level, int sum[]) 
{ 
    if (node == NULL) 
        return; 
  
    // Add current node data to the sum 
    // of the current node's level 
    sum[level] += node->data; 
  
    // Recursive call for left and right sub-tree 
    calculateLevelSum(node->left, level + 1, sum); 
    calculateLevelSum(node->right, level + 1, sum); 
} 


struct ArrWithSize level_wise_swap(struct Node *root) {

	struct arr_with_size ob;
	int levels = getHeight(root) + 1; 

	int sum[levels] = { 0 }; 
    calculateLevelSum(root, 0, sum); 

    int len = sizeof(sum)/sizeof(sum[0]);
    ob.size = len;

    ob.arr = new int[len];

 

    int ap[len];
    int diff = sum[1] - sum[0];
  ;
    int ans[len];
    ans[0] = sum[0];
    for(int i = 1; i < len; i++) {
    	ans[i] = ans[i-1] + diff;
    }

    ap[0] = 0;
    ap[1] = 0;
    for(int i = 2; i < len; i++) {
    	ob.arr[i] = ans[i]- sum[i];
    }

    /*for(int i = 0; i < len; i++) {
    	cout<<ob.arr[i]<<" ";
    }*/
   // cout<<endl;
    printArr(sum, levels); 



    return ob;

} 

int main() 
{ 
    // Create the binary tree 
    Node* root = newNode(17); 
    /*root->left = newNode(4); 
    root->right = newNode(8); 
    root->left->left = newNode(3); 
    root->left->right = newNode(5); 
    root->right->left = newNode(7); 
    root->right->right = newNode(9); 
  */
    root->left = newNode(11);
    root->right = newNode(5); 
    //root->left->left = newNode(2);
    //root->left->left->right = newNode(50);
    root->right->right = newNode(12);


    // Count of levels in the 
    // given binary tree 
   /* int levels = getHeight(root) + 1; 
  
    // To store the sum at every level 
   // struct arr_with_size ob;

    int sum[levels] = { 0 }; 
    calculateLevelSum(root, 0, sum); */

    opra(root);
  
    // Print the required sums 
  //  printArr(sum, levels); 
  
    return 0; 
} 