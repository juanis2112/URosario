#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){

vector<char>histograma;
ifstream file ("/Users/juanis/Documents/Readme.txt");
char data;
while (!file.eof()){
  file>>data;
  histograma.push_back(data);

}
file.close();
for(int i=0; i<histograma.size(); i++)
  cout<<histograma[i];
}
