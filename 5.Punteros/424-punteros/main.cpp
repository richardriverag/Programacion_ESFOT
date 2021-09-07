#include <iostream>
using namespace std;

int main() {
   int i = 5;
   int j = 13;
   int *punt=NULL;
   cout << &i<<endl;
   punt = &i;
   cout << punt << endl; // Muestra la dirección de i
   cout << *punt << endl; // Muestra el valor de i
   i++;
   cout << i << endl; // Muestra el valor de i
   cout << punt << endl; // Muestra la dirección de i
   cout << *punt << endl; // Muestra el valor de i
   (*punt)++;
   cout << punt << endl; //Muestra la dirección de i
   cout << *punt << endl; // Muestra el valor de i


   punt = &j;
   cout << *punt << endl; // Ahora muestra el valor de j
   cout << punt << endl; // Muestra la dirección de i
   int *otro = &i;
   cout << i+j << endl; // i + j
   cout << *otro + *punt << endl; // i + j
   int k = *punt;
   cout << k << endl; // Mismo valor que j
   otro = punt;
   cout << otro << endl; // Muestra el valor de i


cout << "-----------1" << endl;

int *q; // q no tiene aún una dirección válida
//int *q=NULL;
//*q=5;
//cout <<*q<<endl;
q = &i;
*q= *q +5;
cout <<*q<<endl;
cout <<i<<endl;
cout << "-----------2" << endl;
*punt =15;
cout <<*q<<endl;
i = *q;
int *p = &i; // p toma una dirección válida
q = p; // ahora q ya tiene una dirección válida
cout << "-----------" << endl;
cout << "-----------" << endl;
cout << i << endl;
cout << *p << endl;
cout << *q << endl;
cout << "-----------" << endl;
*q = 60;
cout << i << endl;
cout << *p << endl;
cout << *q << endl;
double *punterodoble=NULL;
//q=NULL;
if (p == q){
  cout << "mismo dato" <<endl;
}
else{
  cout << "distinto dato" <<endl;
}
q = NULL; // otra dirección válida para q


}