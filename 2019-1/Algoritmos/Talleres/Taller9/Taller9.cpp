#include<iostream>
using namespace std;

int * createIndexArray(int k){
    int *array = new int[10];

    for (int i = 1; i < k;i++) {
      array[i-1] = i;

      cout << array[i-1] << "..........." << &array[i-1] << endl;

    }

  int *tmp = array;

    return tmp;
    //tmp = &array[0]

}

// int * createIndexArray(k){
//
//
//
// }

int main(){
  int *p = createIndexArray(10);

  cout << *p << endl;

  return 0;

}
