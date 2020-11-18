

#include<bits/stdc++.h>
using namespace std;




class max_heap{
public:
	int capacity;
	int *arr;
	int size ;

	max_heap(int cap);
	void insert_heap(int el);
	void getmax();
	void extract_max();



};

max_heap::max_heap(int cap){
	capacity = cap;
	size = 0;
	arr = new int[capacity];
}

void max_heap::insert_heap(int el){

	if(size==capacity){
		cout<<"Overflow\n";
		return;
	}
	size++;
	if(size == 0){
		arr[size-1] = el;
	}
	else{
		arr[size-1] = el;
		int i = size - 1;

		while(i>=0 and arr[(i-1)/2] < arr[i]){

			int parent = (i-1)/2;
			swap(arr[i],arr[parent]);
			i = parent; 	
		}

	}


}

void max_heap::getmax(){
	cout<<arr[0]<<" ";
}

vois 


void max_heap::extract_max(){

	getmax();


}



int main() {


	int cap;cin>>cap;
	max_heap hp(11);
	//hp.max_heap(11);
	hp.insert_heap(12);
	hp.insert_heap(211	);
	hp.insert_heap(34);
	hp.insert_heap(45);
	hp.getmax();
	hp.insert_heap(233);
	hp.getmax();
	hp.extract_max();






}