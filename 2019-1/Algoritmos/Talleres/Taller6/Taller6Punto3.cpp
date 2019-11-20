#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
  stack <char> myStack;
  string myString;
  cout << "Please enter an string of parentheses: ";
  cin >> myString;
  //string myString ("(())[]");
  //for(int i=0; i<myString.length(); i++){
  int i=0;
  bool t=true;
  while (i<myString.length()){
    while(myString[i]=='('||myString[i]=='['||myString[i]=='{'){
        myStack.push(myString[i]);
        i++;
    }
    if (myStack.empty()&&(myString[i]==')'||myString[i]==']'||myString[i]=='}')){
      t=false;
      i=myString.length();
      }
    while(!myStack.empty()){
      if(myStack.top()=='('&& myString[i]!= ')'){
        t=false;
        i=myString.length();
        break;
      }
      if(myStack.top()=='{'&& myString[i]!= '}'){
        t=false;
        i=myString.length();
        break;
      }
      if(myStack.top()=='['&& myString[i]!= ']'){
        t=false;
        i=myString.length();
        break;
      }
      else
        myStack.pop();
        i++;
    }
  }
  if (t==true)
    cout << "true"<<endl;
  else
    cout << "false"<<endl;

}
