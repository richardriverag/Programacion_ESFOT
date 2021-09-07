/*
#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include "registro.h"

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
*/