#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <list>
using namespace std;
int main(){

  queue<string> Personas;
  Personas.push("Pedro");
  Personas.push("Santiago, el anciano");
  Personas.push("Juan");
  Personas.push("Andres");
  Personas.push("Bartolome");
  Personas.push("Santiago, el menor");
  Personas.push("Judas Iscariote");
  Personas.push("Judas Tadeo");
  Personas.push("Mateo");
  Personas.push("Felipe");
  Personas.push("Simon");
  Personas.push("Tomas");

  int m;
  cout <<"Inserte el numero de puestos que se mueve la espada: ";
  cin >> m;
  while(Personas.size()>1){
      for(int k=0; k<m; k++){
        string var=Personas.front();
        Personas.pop();
        Personas.push(var);
      }
      cout<<"Murió "<<Personas.front()<<endl;
      Personas.pop();
  }
  cout<<"Sobrevivió: "<<Personas.front()<<endl;
}
