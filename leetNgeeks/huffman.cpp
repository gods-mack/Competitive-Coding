

#include<bits/stdc++.h>
using namespace std;

map<char, int > FF; // frequency
map<char,string > encr;

struct node{
	int freq;
	char data;
	node *left,*right;
	node(){

	}
	node(char dta, int fq){
		data = dta;
		freq = fq;
		left = nullptr;
		right = nullptr;
	}
	~node(){
		delete left;
		delete right;
	}
};

node *Root = nullptr;

struct cmp{
    bool operator()(node* l, node* r){
    	return (l->freq > r->freq);
     }
 };



class huffman{
public:

	void Encode(string s){
		priority_queue<node*, vector<node*> , cmp > minHeap;
	

		for(int i = 0; i < (int)s.length(); i++){
			minHeap.push(new node(s[i], FF[s[i]]) );
		}

		while(minHeap.size() != 1){
			node *l = minHeap.top();
			minHeap.pop();
			node *r  = minHeap.top();
			minHeap.pop();
			node *N = new node('$' , l->freq + r->freq);
			N->left =  l;
			N->right = r;
			minHeap.push(N);
		}
		Root = minHeap.top();
		printCode(minHeap.top(), "");

	}

	void printCode(node *root, string str){
		if(root == nullptr){
			return;
		}
		if(root->data != '$'){
			cout<<root->data<<" : "<<str<<endl;
			encr[root->data] = str;
		}
		printCode(root->left,str + "0");
		printCode(root->right, str + "1");
	}

	

	string decode(node *root, string coded ){

		node *curr = root;
		string ans = "";
		for(int i = 0; i < (int)coded.size(); i++){
			if(coded[i] == '0'){
				curr = curr->left;
			}
			else{
				curr  = curr->right;
			}
			if(curr->left == nullptr and curr->right == nullptr){
				ans += curr->data;
				curr  = root;
			}
		}
		return ans;
	}


};

int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		for(int i = 0; i < (int)s.length(); i++){
			FF[s[i]]++;
		}
		string str ; // all unique
		for(auto it = FF.begin(); it!=FF.end(); ++it){
			str += it->first;
		}
		//cout<<"imd str "<<str<<endl;
		huffman ob;
		ob.Encode(str);
		string coded= "";
		for(int i = 0 ; i< (int)s.length(); i++){
			cout<<encr[s[i]];
			coded += encr[s[i]];
		}
		cout<<endl;
		cout<<ob.decode(Root,coded);
    cout<<endl;

	}
}