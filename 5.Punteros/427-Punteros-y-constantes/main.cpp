#include <iostream>
using namespace std;

int main() {
   
   int entero1 = 5; 
   int entero2 = 13;
   const int *punt_a_cte = &entero1; // Puntero a dato constante
   int *const punt_cte = &entero1; // Puntero constante
   cout << *punt_a_cte << "   " << *punt_cte << endl;
   entero1 = entero1 +1;
   cout << *punt_a_cte << "   " << *punt_cte << endl;
   //(*punt_a_cte)++; // ERROR: ¡Dato constante no modificable!
   cout << *punt_a_cte << "   " << *punt_cte << endl;
   punt_a_cte = &entero2; // Sin problema: el puntero no es cte.
   cout << *punt_a_cte << "   " << *punt_cte << endl;
   entero1= 20;
   cout << *punt_a_cte << "   " << *punt_cte << endl;
   (*punt_cte)++; // Sin problema: el puntero no apunta a cte.
   //punt_cte = &entero2; // ERROR: ¡Puntero constante!
   cout << *punt_a_cte << "   " << *punt_cte << endl;

   return 0;
}

