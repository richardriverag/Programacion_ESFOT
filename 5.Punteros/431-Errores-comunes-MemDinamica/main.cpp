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
/*
int main() {
   tRegistro reg;
   reg = nuevo();
   tRegistro *punt = new tRegistro(reg);
   mostrar(*punt);
   cout << reg.nombre <<" "<<punt->nombre<<endl;
   reg.nombre = "Laptop";
   cout << reg.nombre <<" "<<punt->nombre<<endl;
   delete punt;
   
   return 0;
}

//Olvido de destrucción de un dato dinámico
int main() {
   tRegistro *p;
   p = new tRegistro;
   *p = nuevo();
   mostrar(*p);

   return 0;
}


//Intento de destrucción de un dato inexistente
int main() {
   tRegistro *p1 = new tRegistro;
   *p1 = nuevo();
   mostrar(*p1);
   tRegistro *p2;
   p2 = p1;
   mostrar(*p2);
   delete p1;
   delete p2;
   mostrar(*p1);
   return 0;
}



//Pérdida de un dato dinámico
int main() {
   tRegistro *p1, *p2;
   p1 = new tRegistro(nuevo());
   p2 = new tRegistro(nuevo());
  
   //mostrar(*p1);
   p1 = p2;
   mostrar(*p1);
   mostrar(*p2);

   delete p1;
   delete p2;

   return 0;
}

*/
// Intento de acceso a un dato tras su eliminación
int main() {
   tRegistro *p;
   p = new tRegistro(nuevo());
  
   mostrar(*p);
   delete p;
   mostrar(*p);
  
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