#include <iostream>
using namespace std;

   typedef struct {
      int codigo;
      string nombre;
      double sueldo;
   } tRegistro;

int main() {
   tRegistro registro;
   tRegistro *puntero = &registro;
   registro.codigo = 252525;
   registro.nombre = "Javier";
   registro.sueldo = 95000;
   cout << puntero->codigo << "   " << puntero->nombre 
        << "   " << puntero->sueldo << endl;
   cout << (*puntero).codigo << "   " << (*puntero).nombre 
        << "   " << (*puntero).sueldo << endl;
   cout << registro.codigo << "   " << registro.nombre 
        << "   " << registro.sueldo << endl;
   
   registro.nombre = "Paul";
    cout << registro.codigo << "   " << registro.nombre 
        << "   " << registro.sueldo << endl;
        
   return 0;
}



/*
int main() {
   tRegistro registro;
   typedef tRegistro *tRegistroPtr;
   tRegistroPtr puntero = &registro;
   registro.codigo = 12345;
   registro.nombre = "Javier";
   registro.sueldo = 95000;
   cout << puntero->codigo << "   " << puntero->nombre 
        << "   " << puntero->sueldo << endl;

   return 0;
}
*/