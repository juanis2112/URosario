#include <iostream>
#include <map>
#include <math.h>
using namespace std;

bool isPrime(int number){
  if (number==1)
    return false;
  else if (number==2)
    return true;
  int s= ceil(sqrt(number));
  for(int i=2; i<s+1; i++){
    if(number % i == 0)
      return false;
  }
  return true;

}

map<int,string> PrimeMap(int max){
  map<int,string> PrimeMap;
  for(int i=1; i<max+1; i++){
      if(isPrime(i))
        PrimeMap[i]="Prime";
      else
        PrimeMap[i]="NotPrime";
  }
  return PrimeMap;
}
int main(){
  map<int,string>::iterator it;
  map<int,string> a= PrimeMap(10);
  for (it=a.begin(); it!=a.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  cout<< "Prime numbers less than or equal to 10:"<<endl;
  for (it=a.begin(); it!=a.end(); ++it)
    if (it->second=="Prime")
      cout<<it->first <<endl;
  cout<< "Non-prime numbers less than or equal to 10:"<<endl;
  for (it=a.begin(); it!=a.end(); ++it)
    if (it->second=="NotPrime")
      cout<<it->first <<endl;


}
