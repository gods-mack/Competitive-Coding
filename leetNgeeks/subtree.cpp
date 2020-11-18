// { Driver Code Starts
#include <bits/stdc++.h>
#include<cstring>
#include<cstdlib>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}




void inO(Node *tmp,string &s) {

    if(tmp==NULL){
        return;
    }
    inO(tmp->left,s);
    //cout<<tmp->data<<" ";
    s += to_string(tmp->data);
    inO(tmp->right,s);
 // } Driver Code Ends
}


void preO(Node *tmp,string &s) {

    if(tmp==NULL){
        return;
    }
    s += to_string(tmp->data);
    inO(tmp->left,s);
    //cout<<tmp->data<<" ";
    inO(tmp->right,s);
 // } Driver Code Ends
}

bool isSubTree(Node* T, Node* S) {
    // Your code here
    // return 1 if S is subtree of T else 0

    string inT = "";
    string inS = "";

    inO(T,inT);
    inO(S,inS);

    char inT_c[inT.length()+1];
    char inS_c[inS.length()+1];

    for(int i = 0; i < inT.length(); i++){
        inT_c[i] = inT[i];
    }
    for(int i = 0; i < inS.length(); i++){
        inS_c[i] = inS[i];
    }
   
    inT_c[inT.length()] = '\0';
    inS_c[inS.length()] = '\0';


    cout<<inT<<" "<<inT_c<<endl;
    cout<<inS_c<<endl;

    if(strstr(inT_c,inS_c) == NULL){
        return false;
    }

   

    string preT = "";
    string preS = "";

    inO(T,preT);
    inO(S,preS);

    char preT_c[preT.length()+1];
    char preS_c[preS.length()+1];

    for(int i = 0; i < inT.length(); i++){
        preT_c[i] = preT[i];
    }
    for(int i = 0; i < inS.length(); i++){
        preS_c[i] = preS[i];
    }
    preT_c[preT.length()] = '\0';
    preS_c[preS.length()] = '\0';



    if(strstr(preT_c,preS_c) == NULL){
        return false;
    }




    return true;
}


bool isIdentical(Node *T,Node *S){

    if(T == NULL && S==NULL){
        return true;
    }
    if(T==NULL || S==NULL){
        return false;
    }

    if(T->data == S->data && 
        isIdentical(T->left,S->left) && 
        isIdentical(T->right,S->right)) {
        return true;
    }

    return false;
}  

bool isSubTree_brute(Node *T,Node *S){

    if(T==NULL){
        return false;
    }
    if(S==NULL){
        return;
    }

    if(isIdentical(T,S)){
        return true;
    }


    return isSubTree_brute(T->left,S)
    ||isSubTree_brute(T->right.S);
}

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Node *rootS = buildTree(strS);
        cout << isSubTree(rootT, rootS) << "\n";

    }


    return 0;
}  // } Driver Code Ends