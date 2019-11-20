#include <iostream>
#include <set>
#include <math.h>
using namespace std;

bool isPrime(int number){
  int s= ceil(sqrt(number));
  for(int i=2; i<s+1; i++){
    if(number % i == 0)
      return false;
  }
  return true;

}

set<int> createPrimeSet(int max){
  set<int> myPrimes;
  if (max>1)
    myPrimes.insert(2);
  for(int i=2; i<max+1; i++){
      if(isPrime(i))
        myPrimes.insert(i);
  }
  return myPrimes;
}


int main(){
  cout<<isPrime(2)<<endl;
  set<int> myPrimes= createPrimeSet(11);
  cout << "myPrimes contains:";
  for (set<int>::iterator it=myPrimes.begin(); it!=myPrimes.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

}
