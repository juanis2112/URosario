#include "queue.hpp"
#include <iostream>

using namespace std;
int main(){
    Queue<int> q;
    for(int i=0; i<30; i++) q.enqueue(i);
    cout<<q.size() <<endl;
    cout<<q.back() <<endl;
    cout<<q.front()<<endl;
    
    Queue<int> p(q);
    cout<<p.size() <<endl;
    cout<<p.back() <<endl;
    cout<<p.front()<<endl;
 
    Queue<int> w;
    w=p;
    cout<< w.size();
    return 0;
}
