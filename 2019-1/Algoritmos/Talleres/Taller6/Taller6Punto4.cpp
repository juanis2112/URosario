#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
  stack <int> Agendas;
  stack <int> Cuadernos;
  stack <int> Libros;
  stack <int> Paquetes;
  int AgendasN=0;
  int CuadernosN=0;
  int LibrosN=0;
  int PaquetesN=0;
  int CajasN=0;
  // 1 agenda
  // 2 cuaderno
  // 3 libro
  int n;
  int j=0;
  while (j<16 ){
    cout <<"Ingrese el codigo del elemento que entra: ";
    cin >> n;
    switch (n) {
      case (1):
        Agendas.push(n);
        AgendasN++;
        break;
      case (2):
        Cuadernos.push(n);
        CuadernosN++;
        break;
      case (3):
        Libros.push(n);
        LibrosN++;
        break;
      }
      if (Agendas.size()==5 && Cuadernos.size()==5 && Libros.size()==5){
        PaquetesN++;
        Paquetes.push(111222333);
        for(int i=0; i<3; i++){
          Agendas.pop();
          Cuadernos.pop();
          Libros.pop();
        }
      }
      if (Paquetes.size()==12){
        CajasN++;
        while(!Paquetes.empty())
          Paquetes.pop();
      }
      j++;
    }
    cout <<"El numero de agendas ingresadas fue: "<<AgendasN <<endl;
    cout <<"El numero de cuadernos ingresadas fue: "<<CuadernosN <<endl;
    cout <<"El numero de libros ingresadas fue: "<<LibrosN <<endl;
    cout <<"El numero de paquetes despachados fue: "<<PaquetesN <<endl;
    cout <<"El numero de cajas despachadas fue: "<<CajasN <<endl;

}
