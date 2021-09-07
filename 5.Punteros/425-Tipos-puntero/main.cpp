/*
#include <iostream>
using namespace std;

const int N = 10;
const int M = 100000;

int main() {
   int *p = new int[N];
   for (int i = 0; i < N; i++) {
      p[i] = i;
   }
   for (int i = 0; i < N; i++) {
      cout << p[i] << endl;
   }
   delete [] p;
   
   int *q = new int[M];
      for (int i = M; i > 0; i--) {
      p[i] = i;
   }
  cout <<"--------"<<endl;
      for (int i = 0; i < N; i++) {
      cout << p[i] << endl;
   }
   return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main() {
   typedef int *tIntPtr;
   typedef char *tCharPtr;
   typedef double *tDoublePtr;

   int entero = 5;
   tIntPtr puntI = &entero;
   char caracter = 'C';
   tCharPtr puntC = &caracter;
   double real = 5.23;
   tDoublePtr puntD = &real;
   cout << *puntI << "   " << *puntC << "   " << *puntD << endl;

   return 0;
}
*/
#include <iostream>
using namespace std;
int main() {
   int entero = 5;
   int *puntI = &entero;
   char caracter = 'C';
   char *puntC = &caracter;
   double real = 5.23;
   double *puntD = &real;
   cout << *puntI << "   " << *puntC << "   " << *puntD << endl;
   return 0;
}
