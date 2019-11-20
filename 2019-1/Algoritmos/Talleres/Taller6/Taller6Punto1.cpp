#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){

vector<string>histograma;
ifstream file;
file.open("/Users/juanis/Documents/Urosario/Algoritmos/Taller6/Readme.txt");
char data;
int num_a=0;
int num_e=0;
int num_i=0;
int num_o=0;
int num_u=0;
while (!file.eof()){
  file >> data;
  //file.get(data);
  switch (data) {
    case ('a'):
    case ('A'):
      num_a++;
      break;
    case ('e'):
    case ('E'):
      num_e++;
      break;
    case ('i'):
    case ('I'):
      num_i++;
      break;
    case ('o'):
    case ('O'):
      num_o++;
      break;
    case ('u'):
    case ('U'):
      num_u++;
      break;
  }
//}
string a = to_string(num_a);
string e = to_string(num_e);
string i = to_string(num_i);
string o = to_string(num_o);
string u = to_string(num_u);
file.close();
histograma.push_back("a:"+a);
histograma.push_back("e:"+e);
histograma.push_back("i:"+i);
histograma.push_back("o:"+o);
histograma.push_back("u:"+u);


for(int i=0; i<histograma.size(); i++){
  cout<< histograma[i]<<endl;
}
}
