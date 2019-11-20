#include <iostream>
#include <set>
#include <math.h>
using namespace std;

bool subset(set<int> a, set<int> b){

  for (set<int>::iterator it=a.begin(); it!=a.end(); ++it){
    set<int>::iterator it2;
    if(b.find(*it) == b.end())
      return false;
  }
  return true;
}


int main(){
  int myints[]={12,75,10,32,20,25};
  set<int> a (myints,myints+5);
  set<int> b (myints,myints+6);
  //b.erase(75);
  cout<<subset(a,b);

}
