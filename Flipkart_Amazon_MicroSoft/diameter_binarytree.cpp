/* write the function  to return diameter of a binary tree. */ 



int height(Node *tmp){
    if(!tmp){
        return 0;
    }
    int l = height(tmp->left);
    int r = height(tmp->right);
    if(l>r){
        return l+1;
    }
    else{
        return r+1;
    }
    
}

int diameter(Node* node)
{
   // Your code here
   
   if(node==nullptr){
       return 0;
   }
   int lheight = height(node->left);
   int rheight = height(node->right);
   
   int ldiameter = diameter(node->left);
   int rdiameter = diameter(node->right);
   
   int fd = std::max(lheight+rheight+1, max(ldiameter,rdiameter));
   
   return fd;
    
   
}
