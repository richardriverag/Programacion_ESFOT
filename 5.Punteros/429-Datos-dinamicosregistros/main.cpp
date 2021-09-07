
#include <iostream>
using namespace std;
#include <iomanip>

typedef struct {
   int codigo;
   string nombre;
   double valor;
} tRegistro;


//Prototipos
// Lectura de los datos de un nuevo registro.
tRegistro nuevo();
// Muestra en una línea la información del registro proporcionado.
void mostrar(tRegistro registro);

int main() {
   tRegistro reg;
   reg = nuevo();
   tRegistro *punt = new tRegistro(reg);
   mostrar(*punt);
   cout <<punt->nombre <<endl;
   delete punt;

  //cout <<punt->nombre <<endl;
   return 0;
}

tRegistro nuevo() {
   tRegistro reg;
   cout << "Nuevo registro:" << endl;
   cout << "Código: "; 
   //cin.ignore();
   cin >> reg.codigo;
   cout << "Nombre: "; 
   cin.ignore();
   getline(cin, reg.nombre);
   cout << "Precio: "; 
   cin >> reg.valor;
   return reg;
}

void mostrar(tRegistro registro) {
   cout << setw(10) << registro.codigo << " - " << setw(25) << left
        << registro.nombre << " - " << setw(8) << fixed << right
        << setprecision(2) << registro.valor << " dolares" << endl;
}

/*
#include <iostream>
using namespace std;
#include "registro.h"

int main() {
   tRegistro reg;
   reg = nuevo();
   tRegistro *punt = new tRegistro(reg);
   mostrar(*punt);
   delete punt;
   
   return 0;
}
*/
