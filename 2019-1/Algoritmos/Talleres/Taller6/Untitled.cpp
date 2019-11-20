#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

void vaciarVector(vector<int> &myvec){
  myvec.clear();
}
int main(){
  vector<int> vec2;
  int i;
  for(i=0;i<3;i++)
    vec2.insert(vec2.begin()+i, pow(10,i+1));
  vaciarVector(vec2);
  cout << "The final contents of vec2" <<endl;
  for (int i=0; i<vec2.size(); i++)
    cout << vec2[i] << endl;

}
