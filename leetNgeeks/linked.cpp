
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
	node(int x){
		data = x;
		next = nullptr;
	}
};

struct tnode {
	int data;
	tnode *left,*right;
	tnode(int x){
		data = x;
		left = nullptr;
		right = nullptr;
	}
	
};



class llist{

public:
 	node *head = nullptr;
	node *tail = nullptr;
	void push_l(int data);
	void print_l();
	void remove_l(int data);
	void remove_dup();
	int KthNode_last(node* tmp,int k);
	void last_KthNode(int k);
	void partition_list(int x);
	void make_number(node *h,int&);
	void sumList(node*,node*);
	void list_palindrom(node*);
	void removeLoop(node*);
	void detectLoop();

	node* reverse_list(node*);
	node* reverse_range(node*,int,int);

	node* rotate_Knode(node*,int);

	tnode* sorted2BST(node*);

	node* reorder(node*);

	void insertion_sort(node*);

};


void llist::push_l(int data){

	if(head==nullptr){
		node *n = new node(data);
		head = n;
		tail = n;
	}
	else {
		node *n = new node(data);
		tail->next = n;
		tail = n;
	}
}

int list_len(node *tmp){
	int count = 0;
	while(tmp!=nullptr) {
		count++;
		tmp = tmp->next;
	}
	return count;
}
int list_len_range(node *s,node *e) {
	int count = 0;
	while(s!=e){
		count++;
		s=s->next;
	}
	return count;
}


void llist::print_l(){
	node *tmp = head;
	while(tmp!=nullptr){
		cout<<tmp->data<<" ";
		tmp  = tmp->next;
	}
}

void llist::remove_l(int data){

	node *tmp = head;

	if(tmp!=nullptr and tmp->data==data){
		head = tmp->next;
		free(tmp);
		return ;
	}
	while(tmp!=nullptr){
		if(tmp->next->data==data){
			node *tt = tmp->next->next;
			free(tmp->next);
			tmp->next = tt;

			break;
		}
		tmp = tmp->next;
	}
}

void llist::remove_dup(){

	node *tmp = head;
	map<int,int> hs;
	while(tmp!=nullptr){
		hs[tmp->data]++;
		tmp = tmp->next;
	}

	tmp = head;
	node *prv = head;

	while(tmp!=nullptr){

		if(hs[tmp->data] > 1){
			hs[tmp->data] = -hs[tmp->data];
			//cout<<"dup "<<tmp->data<<" "<<hs[tmp->data]<<endl;
		}
		else if(hs[tmp->data] < 0){
			//cout<<"en "<<tmp->data<<" prv "<<prv->data<<endl;
			node *tt = tmp;
			prv->next = tmp->next;
			//prv = tmp->next;
			free(tmp);
			tmp = prv->next;
			continue;

		}
		prv = tmp;
		tmp = tmp->next;
	}


}

int llist::KthNode_last(node *head,int k){

	if(head==nullptr){
		return 0;
	}

	int index = KthNode_last(head->next,k) + 1;
	if(index == k) {
		cout<<"Last Kth Node: "<<head->data<<endl;
	}

}

void llist::last_KthNode(int k) {

	int res = KthNode_last(head,k);
}


/*
Write code to partition a linked list around a
 value x, such that all nodes less than x come
before all nodes greater than or equal to x. If 
x is contained within the list the values of x only
 need
to be after the elements less than x (see below). 
The partition element x can appear anywhere in the
"right partition"; it does not need to appear 
between the left and right partitions.
*/

void llist::partition_list(int x){

	node *i = nullptr;
	node* j = head;
	int pivot = x;

	while(j!=nullptr){

		if(j->data < pivot){
			if(i==nullptr){

				i = head;
				int tmp = i->data;
				i->data = j->data;
				j->data = tmp;
			}
			else{

				i = i->next;
				int tmp = i->data;
				i->data = j->data;
				j->data = tmp;
			
			}

		}
		j = j->next;
	}


}


void llist::make_number(node *head,int &num){

	if(head == nullptr){
		return;
	}
	make_number(head->next,num);
	num = num*10 + head->data;
}

void llist::sumList(node* list1,node *list2){

	int num1=0;
	make_number(list1,num1);
	cout<<"NUm1 "<<num1<<endl;

	int num2 = 0;
	make_number(list2,num2);
	cout<<"NUm2 "<<num2<<endl;

	cout<<"List sum: "<<num1+num2<<endl;
}

void llist::list_palindrom(node *h){

	node *tmp = h;
	int val1 = 0;
	while(tmp!=nullptr){
		val1 = val1*10 + tmp->data;
		tmp = tmp->next;
	}

	int val2 = 0;
	make_number(h,val2);

	if(val2==val1){
		cout<<"list is palindrom\n";
	}
	else{
		cout<<"Not palindrom"<<endl;
	}
}


void llist::removeLoop(node *p){

	node *p1 = p;
	node *p2 = p;
	int k = 1;
	while(1){
		k++;
		p1=p1->next;
		p2=p2->next;
		if(p1 == p2){
			break;
		}
	}

	p1 = head;
	p2 = head;
	for(int i = 0; i < k; i++) {
		p2 = p2->next;
	}
	while(1){
		p1 = p1->next;
		p2 = p2->next;
		if(p2->next=p1){
			cout<<"first node of loop\n";
			p2->next = NULL;// remove loop
			break;
		}
	}
}

void llist::detectLoop(){
	node *slow = head;
	node *fast = head;

	while(fast->next!=nullptr && fast!=nullptr){

		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast){
			cout<<"found loop\n";
			removeLoop(slow);
			break;
		}
	}
}


node* llist::reverse_list(node *list) {

	node *curr = list;
	node *prv  = nullptr;

	while(curr != nullptr) {

		node *fwd = curr->next;
		curr->next = prv;
		prv = curr;
		curr = fwd;

	}

	return prv;

}

 void rev(node *nhead,node *tmp,int limit) {
        
        if(limit<=0) {
            nhead->data = tmp->data;
            nhead = nhead->next;
            return;
        }
        rev(nhead,tmp->next,limit-1);
        
}

node* llist::reverse_range(node *list,int m,int n) {
  
        node *prv;
        node *tmp_m = list;
        
        for(int i=0;i<m-1;i++){
            prv = tmp_m;
            tmp_m = tmp_m->next;
        }

        node *nhead = tmp_m;
      
        rev(nhead,tmp_m,abs(m-n));

        
        /*
        //cout<<"now tmp_m "<<tmp_m->data<<endl;
        // reverse
        node *nhead = tmp_m;
        node *curr = tmp_m;
        node *pr = NULL;
        node *fwd ;
        for(int i = 0; i < abs(m-n)+1 and curr!=nullptr; i++) {
            
            fwd = curr->next;
            curr->next = pr;
            pr = curr;
            curr = fwd;
            
            
        }
        cout<<"pr "<<pr->data<<endl;
        prv->next = pr;
        nhead->next = fwd;
        */


        return list;
}



void reverse_Knode(node *list, int k) {

	int len = list_len(list);
	int times = len/k;


}




node* llist::rotate_Knode(node *list,int k) {
	 
        int len =list_len(head);
        
        node *tmp = list;
        while(1) {
            if(tmp->next == nullptr){
                tmp->next = list;
                break;
            }
            tmp = tmp->next;
        }
        
        tmp = list;
        int data = tmp->data;
        k = k*len;
        tmp = tmp->next;
       // print_l();

        while(k--) {
        	if(tmp == list) {
        		int curr = tmp->data;
        		tmp->data = data;
           		data = tmp->data;

           		tmp = tmp->next ;
           		continue;

           	}
           	else{
           
            
            

        	
            int curr = tmp->data;
        	tmp->data = data;
            data = curr;
           
            
            tmp = tmp->next;
        	}
        }
       // print_l();
        //print_l();

        tmp = list;
        
        for(int i = 0; i < len-1; i++) {
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        return head;
    
}


void inorder(tnode *tmp) {
	if(tmp==nullptr){
		return;
	}
	inorder(tmp->left);
	cout<<tmp->data<<" ";
	inorder(tmp->right);
}




tnode *sorted2BST_util(node *list,node *end) {

	//cout<<"mas\n";
	if(list==nullptr){
		return nullptr;
	}
	

	int len = list_len_range(list,end) + 1;
	cout<<"len "<<len<<endl;
	int mid = (len/2);
	//mid++;
	node *tmp = list;
	node *prv = tmp; // mid-1
	while(mid-- and tmp!=nullptr) {
		prv = tmp;
		tmp = tmp->next;
	}
	cout<<"tmp "<<tmp->data<<" "<<prv->data<<endl;
	tnode *root = new tnode(tmp->data);
	if(len == 1){
		return root;
	}
	if(len == 2) {
		root->left = new tnode(prv->data);
		return root;
	}

	root->left = sorted2BST_util(list,prv);
	root->right = sorted2BST_util(tmp->next,end);

	return root;



}
tnode* sorted2BST(node *list) {

	int len = list_len(list);
	node *end;
	node *tmp = list;
	while(tmp!=nullptr){
		end = tmp;
		tmp = tmp->next;
	}

	cout<<end->data<<endl;
	tnode *ans = sorted2BST_util(list,end);

	return ans;

}


// 1->2->3->4->5
// after reorder
// 1->5->2->4->3
node* llist::reorder(node *list) {

	unordered_map<int,node*> hs;
	int ind = 0;
	node *tmp = head;
	while(tmp!=nullptr) {
		hs[ind++] = tmp;
		tmp = tmp->next;
	}

	int len = ind;

	cout<<"len "<<ind<<endl;

	int l = 0;
	int r = ind-1;
	node *curr = nullptr;

	while( r>=l) {


		node *a = hs[l];
		node *b = hs[r];
		if(curr!=nullptr) {
			curr->next = a;
		}
		b->next = nullptr;
		curr = b;

		if(a!=b)
			a->next = b;

		l++;
		r--;

	}

	return list;

}


void llist::insertion_sort(node *list) {

	node *curr = list->next;

	while(curr!=nullptr) {

		int key = curr->data;

		node *tmp = list;


		// find exact place
		while(tmp->data < key && tmp != curr) {
			tmp = tmp->next;
		}
	

		int val = key;

		//shifting
		while(tmp!=curr) {
			int prv = tmp->data;
			tmp->data = val;
			val = prv;

			tmp = tmp->next;
		}
		tmp->data =  val;

		curr = curr->next;
	}

}



// Remove all elements from a linked list 
// of integers that have value val.
node* remove_elements(node *list,int val) {

	    node *nhead = nullptr;
        node *tmp = list;
        node *tail = nullptr;
        
        node *prv = nullptr;
        
        while(tmp!=nullptr) {
            
            if(tmp->data == val) {
                
                // first element is val
                if(prv)
                    prv->next = nullptr;
                
            }
            else{
                if(nhead == nullptr){
                    nhead = tmp;
                    tail = tmp;
                }
                else{
                    tail->next = tmp;
                    tail = tmp;
                }
            }
            prv = tmp;
            tmp = tmp->next;
        }
        
     
        return nhead;
}



/*
Given a singly linked list, group all odd 
nodes together followed by the even nodes. 
*/
node *oddEven_list(node *list) {


	node *odd = nullptr;
	node *even = nullptr;
	node *to; // odd tail
	node *te; // even tail

	node *tmp = list;

	while(tmp!= nullptr) {

		if(tmp->data%2 != 0) {
			if(odd == nullptr){
				odd = tmp;
				to = tmp;
			}
			else{
				to->next = tmp;
				to = tmp;
			}
		}
		else{
			if(even == nullptr){
				even = tmp;
				te = tmp;
			}
			else{
				te->next = tmp;
				te = tmp;
			}
		}
		tmp = tmp->next;	
	}

	te->next = nullptr;
	to->next = even;


	return odd;  // new_	head startss from odds
}









int main(){

	llist ob;
	int n; cin>>n;
	while(n--) {int x; cin>>x; ob.push_l(x);}

	/*llist ob1;
	int m; cin>>m;
	while(m--) {int x; cin>>x; ob1.push_l(x);}
	*/

	/*ob.push_l(12);
	ob.push_l(43);
	ob.push_l(87);

	ob.push_l(333);
	ob.push_l(98);
	ob.push_l(43);
	ob.push_l(12);
	ob.push_l(333);
	ob.push_l(87);
	ob.push_l(66);
		ob.push_l(66);
		ob.push_l(66);
		ob.push_l(66);*/

	//cout<<ob.head->data<<" ";
	//ob.remove_l(87);
	//ob.remove_dup();
	//ob.last_KthNode(7);	
	//ob.partition_list(5);
	//ob.sumList(ob.head,ob1.head);

	//ob.list_palindrom(ob.head);
	/*int l,r; cin>>l>>r;

	node *nh = ob.reverse_range(ob.head,l,r);
	ob.head = nh;*/

	//tnode *rt = sorted2BST(ob.head);
	//inorder(rt);

	//node *nh = ob.reorder(ob.head);

	//ob.insertion_sort(ob.head);

	//node *nh = remove_elements(ob.head,6);
	//ob.head = nh;

	//ob.list_palindrom(ob.head);

	node *nh = oddEven_list(ob.head);
	ob.head = nh;
	ob.print_l();

	//ob.print_l();

}