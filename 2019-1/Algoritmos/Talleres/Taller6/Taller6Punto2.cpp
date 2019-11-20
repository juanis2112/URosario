#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void leerLinea(vector<string> &reg, string linea){
    getline(linea, reg, ',')
    reg.push_back(reg)
}

int main(){
  ifstream file ("/Users/juanis/Documents/Urosario/Algoritmos/Taller6/Peliculas.txt");
  int line=0;
  vector<vector<string> >regs;
  while (!file.eof()){
    string testString;
    vector<string>reg;
    getline(file, line, '\n');
    vector<string>movieReg;
    leerLinea(movieReg,line)
    regs.push_back(Moviereg);
  }
  for(int i=0; i<6; i++)
    cout<< regs[i][0]<<endl;
  file.close();
}
