/*
efficient way to implement a queue using two stack.
here we have push function in O(1)

problem URL: https://www.hackerrank.com/challenges/ctci-queue-using-
two-stacks/problem?filter=cpp&filter_on=language&h_l=interview&page=1&playlist_slugs%5B%5D=
interview-preparation-kit&playlist_slugs%5B%5D=stacks-queues

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<long long int> s1, s2;   
        void push(long long int x) {

            s1.push(x);
                   
        }

        void pop() {
            
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            
            
                s2.pop();
            
            
        }

        long long int front() {
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            return s2.top();
        
        }
};

int main() {
    MyQueue q1;
    int q, type;
    long long int x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

