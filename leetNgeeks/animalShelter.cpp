
#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

struct node{
	int count;
	char data;
	node *next;
	node *dog;
	node *cat;
	node(char x){
		data = x;
		next = nullptr;
		dog  = nullptr;
		cat  = nullptr;
	}

};


class animal{
public:
	//struct node *c,*d,tail,*head;
	node *c=nullptr;
	node *d=nullptr;
	node *tail=nullptr;
	node *head=nullptr;
	node *fc = nullptr;
	node *fd = nullptr;
	void enqueue(char x);
	void dequeue();
	void dequeueDog();
	void dequeueCat();
};

void animal::enqueue(char data){

	cnt++;
	node *n = new node(data);
	n->count = cnt;
	if(head==nullptr){
		head = n;
		tail = n;
		if(data = 'D'){fd = n;d=n;}
		else if(data = 'C') {fc = n;c=n;}
	}
	else {
		if(data == 'D'){
			if(fd==nullptr){ fd = n;d=n;}
			d->dog = n;
			d = n;
		}
		else{
			if(fc==nullptr) { fc = n; c=n;}
			c->cat = n;
			c = n;
		}
		tail->next = n;
		tail = n;
	}
}


// 'Z' represents that this node is deleted
void animal::dequeue(){

	while(head->data == 'Z'){
		head = head->next;
	}
	cout<<"dequeued "<<head->count<<" "<<head->data<<endl;
	node *tmp = head;
	head->data = 'Z';
	head = head->next;
	//free(tmp);
}

void animal::dequeueDog(){
	while(fd->data == 'Z'){
		fd = fd->dog;
	}
	cout<<"dequeued Dog "<<fd->count<<" "<<fd->data<<endl;
	fd->data = 'Z';
	fd = fd->dog;
}


void animal::dequeueCat(){
	while(fc->data == 'Z'){
		fc = fc->cat;
	}
	cout<<"dequeued Cat "<<fc->count<<" "<<fc->data<<endl;
	fc->data = 'Z';
	fc = fc->cat;
}



int main() {

	//int n; cin>>n;
	animal o;

	o.enqueue('D');
	o.enqueue('C');
	o.enqueue('D');
	o.enqueue('C');
	o.dequeueCat();
	o.dequeue();
	o.dequeue();
	o.enqueue('C');
	o.enqueue('C');
	o.enqueue('D');
	o.dequeueDog();
	o.dequeue();
	o.dequeue();
	o.dequeue();
	o.enqueue('D');
	o.enqueue('C');
	o.dequeueCat();

}