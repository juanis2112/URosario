#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <list>
using namespace std;

// PUNTO 2d)
void print(vector<int> A){
  cout << "The final contents of vec2" <<endl;
  for (int i=0; i<A.size(); i++)
    cout << A[i] << endl;
}

int main(){

// // PUNTO 1
// vector<int> vec1={1,2,3,4};
// cout << "The contents of vec1 are:" <<endl;
// for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
//   cout << ' ' << *it <<endl;
// // a) Size
// cout << "The size of vec1 is:";
// cout << vec1.size() <<endl;
// // b) Empty
// if(vec1.empty())
//   cout << "The vector is empty"<<endl;
// else
//   cout << "The vector is not empty"<<endl;
// // c) Posicion i
// int i=3;
// cout << "The value at position "<< i << " is ";
// cout << vec1.at(i) <<endl;
//
// // d) Last and first
// cout << "The first value of the vector is ";
// cout << vec1.front() <<endl;
//
// cout << "The last value of the vector is ";
// cout << vec1.back() <<endl;
//
// // e) Delete elements
// vec1.erase(vec1.begin()+2);
// cout << "The contents of vec1 after removing " <<endl;
// for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
//   cout << ' ' << *it <<endl;
//
// // f) Insert elements
// vec1.insert(vec1.begin()+2, 5);
// cout << "The contents of vec1 after inserting " <<endl;
// for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
//   cout << ' ' << *it <<endl;
//
// // g) Insert and delete at the end
//
// vec1.push_back(8);
// cout << "The contents of vec1 after inserting " <<endl;
// for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
// cout << ' ' << *it <<endl;
//
// vec1.pop_back();
// cout << "The contents of vec1 after deleting " <<endl;
// for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
// cout << ' ' << *it <<endl;
//
// // h) Operator[]
// cout << "The value at position "<< i << " is ";
// cout << vec1[i] <<endl;
//
// //PUNTO 2
//
// // a) Create object vector
// vector<int> vec2;
//
// // b) Fill with powers of 10
// for(i=0;i<3;i++){
//   vec2.insert(vec2.begin()+i, pow(10,i+1));
// }
// cout << "The contents of vec2 after inserting " <<endl;
// for (vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
// cout << ' ' << *it <<endl;
//
// // c) Delete elements smaller than 100
// for(int i=0; i<vec2.size(); i++){
//   if(vec2[i]<100){
//     vec2.erase(vec2.begin()+i);
//   }
// }
// // d) print elements in a function
//
// print(vec2);
//
// // PUNTO 3
// vector<int> vec3={1,2,3,4};
// stack<int, vector<int> > myStack(vec3);
// stack<int> s;
// s.push(10);
// s.push(30);
// s.push(20);
// s.push(5);
// s.push(1);
//
// cout << "The contents of s are:" <<endl;
//   while (!s.empty()) {
//       cout<<s.top()<<endl;
//       s.pop();
//   }
// // a) Size
// cout << "The size of MyStack is:";
// cout << myStack.size() <<endl;
// // b) Empty
// if(myStack.empty())
//   cout << "The Stack is empty"<<endl;
// else
//   cout << "The Stack is not empty"<<endl;
//
// // c) Top element
// cout << "The top value of the Stack is ";
// cout << myStack.top() <<endl;
//
// // d) Delete elements
// myStack.pop();
// cout << "The size of MyStack now is:";
// cout << myStack.size() <<endl;
//
// // e) Insert elements
// myStack.push(5);
// cout << "The size of MyStack now is:";
// cout << myStack.size() <<endl;
//
// //PUNTO 4
//
// // a) Create object stack
// stack<int> stack2;
//
// // b) Fill with powers of 10
// for(i=0;i<3;i++){
//   stack2.push(pow(10,i+1));
// }
// cout << "The size of stack2 now is: ";
// cout <<stack2.size() <<endl;
//
// // c) Print Top element
// cout << "The top value of stack2 is ";
// cout << stack2.top() <<endl;
//
// // d) Print all the elements
// cout << "The contents of stack2 are:" <<endl;
//   while (!stack2.empty()) {
//       cout<<stack2.top()<<endl;
//       stack2.pop();
//     }
//
// // PUNTO 5
// list<int> vec4={1,2,3,4};
// queue<int, list<int> > myQueue(vec4);
// stack<int> q;
// q.push(10);
// q.push(30);
// q.push(20);
// q.push(5);
// q.push(1);
//
// //for (size_t i = 1; i < 5; i++) {
//   //myQueue.push(i);
// //}
//
//
// // a) Size
// cout << "The size of myQueue is:";
// cout << myQueue.size() <<endl;
// // b) Empty
// if(myQueue.empty())
//   cout << "The Queue is empty"<<endl;
// else
//   cout << "The Queue is not empty"<<endl;
//
// // c) Top element
// cout << "The next value of the Queue is ";
// cout << myQueue.front() <<endl;
//
// // d) Delete elements
// myQueue.pop();
//
// cout << "The size of myQueue now is:";
// cout << myQueue.size() <<endl;
//
// // e) Insert elements
// myQueue.push(5);
//
// cout << "The size of myQueue now is:";
// cout << myQueue.size() <<endl;
//
//
// // PUNTO 6
//
// // a) Create object queue
// queue<int> queue2;
//
// // b) Fill with powers of 10
// for(i=0;i<3;i++){
//   queue2.push(pow(10,i+1));
// }
// cout << "The size of Queue2 now is: ";
// cout <<queue2.size() <<endl;
//
// // c) Print Top element
// cout << "The top value of queue2 is ";
// cout << queue2.front() <<endl;
//
// // d) Print all the elements
// cout << "The contents of Queue2 are:" <<endl;
//   while (!queue2.empty()) {
//       cout<<queue2.front()<<endl;
//       queue2.pop();
//     }

//PUTO 7

map<char,int> first;

first['a']=10;
first['b']=30;
first['c']=50;
first['d']=70;

first.erase('c');
map<char,int>::iterator it;

for (it=first.begin(); it!=first.end(); ++it)
  std::cout << it->first << " => " << it->second << '\n';

 cout<<first.at('b');
 cout<<first['b'];


// PUNTO 9

// // a) Add
//   set<int> myset;
//   myset.insert (100);
//   myset.insert (200);
//   myset.insert (300);
//   myset.insert (400);
//   myset.insert (500);
//   myset.insert (600);
//
//   cout << "myset contains:";
//   for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
//     cout << ' ' << *it;
//   cout << '\n';
//
//  // b) delete
//  set<int>::iterator it;
//  it = myset.begin();
//   myset.erase (it);
//   myset.erase (10);
// //  myset.erase (40);
//
//   cout << "after deleting myset contains:";
//   for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
//     cout << ' ' << *it;
//   cout << '\n';
//
//   // c) Empty
//   if(myset.empty())
//     cout<<"myset is empty"<<endl;
//   else
//     cout<< "my set is not empty"<<endl;
//
//   // d) find
//
//   set<int>::iterator it2;
//   it2= myset.find(550);
//   cout << *it2<<endl;

  // // Punto 10
  // set<string> myDavid;
  // myDavid.insert("Juan");
  // myDavid.insert("David");
  // myDavid.insert("Bravo");
  // myDavid.insert("Herrera");
  // myDavid.insert("Cardozo");
  //
  // cout << "myset contains:";
  // for (set<string>::iterator it3=myDavid.begin(); it3!=myDavid.end(); ++it3)
  //   cout << ' ' << *it3;
  // cout << '\n';
  //
  // myDavid.erase("David");
  // myDavid.find("Juanita");
  // cout<< "The size of myDavid is "<<myDavid.size() <<endl;
  //
  // cout << "myset contains:";
  // for (set<string>::iterator it4=myDavid.begin(); it4!=myDavid.end(); ++it4)
  //   cout << ' ' << *it4;
  // cout << '\n';
  //
  // set<string>::iterator it5 =myDavid.begin();
  // cout<< *it5<<endl;
  //
  // set<string>::iterator it6 =myDavid.end();
  // --it6;
  // cout<< *it6<<endl;
}
