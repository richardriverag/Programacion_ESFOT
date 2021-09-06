#include <iostream> 
using namespace std; 
namespace primero { 
   int x = 5; 
   int y = 10; 
} 
namespace segundo { 
   double x = 3.1416; 
   double y = 2.7183; 
} 
/*
int main() { 
   cout << "Hola" <<endl;
   using primero::x; 
   using segundo::y; 
   cout << x << endl; // x es primero::x
   cout << y << endl; // y es segundo::y
   cout << primero::y << endl; // espacio explícito
   cout << segundo::x << endl; // espacio explícito
   return 0; 
}
*/


int main() { 
  using namespace primero;  // sólo tiene efecto en el bloque en que se encuentra
  cout << x << endl; // x es primero::x
  cout << y << endl; // y es primero::y
  cout << segundo::x << endl; // espacio explícito
  cout << segundo::y << endl; // espacio explícito
  return 0; 
}

