#include <iostream>
#include <map>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;



int main(){
  ifstream file ("/Users/juanis/Documents/Urosario/Algoritmos/Taller6/errors.txt");
  int line=0;
  map<string,string> errors;
  while (!file.eof()){
    string testString1;
    getline(file, testString1, '\t');
    string testString2;
    getline(file, testString2, '\n');
    errors[testString1]=testString2;
  }
  map<string,string>::iterator it;
  for (it=errors.begin(); it!=errors.end(); ++it)
    cout << it->first << " => " << it->second << '\n';



}
