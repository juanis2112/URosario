#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
int main(){

vector<string>vector;
ifstream file ("/Users/juanis/Documents/URosario/Algoritmos/Taller6A/starwars.txt");
cout << "This are separated by endl" << endl;
String testString;
while (!file.eof()) {
        getline(file,testString);
        vector.push_back(testString)<< testString;
}
file.close();
for(int i=0; i<vector.size(); i++){
  cout<< vector[i]<<endl;
}
}
