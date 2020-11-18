

// trie DS
#include <bits/stdc++.h>
using namespace std;

struct tnode{
	char data;
	tnode *child[26];
	int wc;
	tnode() {
		wc = 0;
		for(int i=0;i<26;i++)
			child[i] = nullptr;
	}
	tnode(char x) {
		data = x;
		wc = 0;
		for(int i=0;i<26;i++)
			child[i] = nullptr;
	}

};

void insert(tnode *root,string s) {

	tnode *tmp = root;

	for(auto c:s) {

		int ind = c-'a';
		if(tmp->child[ind] == nullptr) {
			tmp->child[ind] = new tnode(c);
		}
		tmp = tmp->child[ind];

	}
	tmp->wc = 1;
	cout<<"inserted..\n";
}

bool search(tnode *root,string s) {


	tnode *tmp = root;

	for(auto c:s) {

		int ind = c-'a';
		tmp = tmp->child[ind];
		if(tmp==nullptr){
			return false;
		}
		if(tmp->data != c){
			return false;
		} 
	}
	return tmp!=nullptr and tmp->wc==1;
}





void phone_directory(tnode *root,string pat) {
	//pat : pattern

	string curr = "";
	tnode *tmp = root;
	for(int i = 0; i < pat.length(); i++){

		curr += pat[i];
		string buff = "";
		while(buff!=curr) {
			for(auto cr:curr){
				int ind = cr-'a';
				buff += cr;
				tmp = tmp->child[ind];
			}
		}
		
		for(int i = 0; i < 26; i++) {
			if(tmp->child[i] != nullptr) {
				cout<<tmp->child[i]->data<<endl;
			}
		}

		

	}
}
int main() {


	tnode *root = nullptr;
	root = new tnode();

	int n; cin>>n;
	for(int i = 0; i < n; i++) {
		string s; cin>>s;
		insert(root,s);
	}

	/*for(int i = 0; i < 3; i++) {
		string s; cin>>s;
		if(search(root,s)){
			cout<<"found  "<<s<<endl;
		}
		else{
			cout<<"not found "<<s<<endl;
		}
	}
	*/

	phone_directory(root,"geks");
}