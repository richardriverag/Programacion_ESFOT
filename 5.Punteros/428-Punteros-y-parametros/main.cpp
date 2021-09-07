#include <iostream>
using namespace std;

void incrementa(int *punt);



int main() {
   int entero = 5;
   cout << &entero << endl;
   incrementa(&entero);
   cout << &entero << endl;
   cout << entero << endl;

   return 0;
}

void incrementa(int *punt) {
   //(*punt)++;
   *punt = *punt +80;
}