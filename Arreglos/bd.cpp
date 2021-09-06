#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>

const int MAX = 100;

typedef struct {
	string nombre;
	string apellidos;
	int edad;
	string cedula;
	double nota;
} tEstudiante;

typedef struct {
	tEstudiante elementos[MAX];
	int contador;
}tLista;

//Prototipos
int menu(); //menú del programa - devuelve la opción elegida
void cargar(tLista& lista, bool& ok);
void guardar(const tLista lista);
void leerEstudiante(tEstudiante& estudiante);
void insertarEstudiante(tLista& lista, tEstudiante estudiante, bool& ok);
void eliminarEstudiante(tLista& lista, int pos, bool& ok);
void calificar(tLista& lista);
string nombreCompleto(tEstudiante estudiante);
int mayorNota(const tLista lista);
double mediaClase(const tLista lista);
void listado(const tLista lista, double media, int mayor);


int main() {
	tLista lista;
	tEstudiante estudiante;
	bool exito;
	int op, pos;

	cargar(lista, exito);
	if (!exito) {
		cout << "No se ha podido cargar la lista!" << endl;
	}
	else {
		do {
			op = menu();
			switch (op) {
			case 1:
			{
				leerEstudiante(estudiante);
				insertarEstudiante(lista, estudiante, exito);
				if (!exito) {
					cout << "Lista llena: imposible insertar" << endl;
				}

			}
			break;
			case 2:
			{
				cout << "Posición: ";
				cin >> pos;
				eliminarEstudiante(lista, pos - 1, exito);
				if (!exito) {
					cout << "Elemento inexistente!" << endl;
				}
			}
			break;
			case 3:
			{
				calificar(lista);
			}
			case 4:
			{
				listado(lista, mediaClase(lista), mayorNota(lista));
			}
			}

		} while (op != 0);
		//guardar(lista);
	}
	return 0;
}

int menu() {
	int op;
	do {
		cout << "1 - Añadir un nuevo estudiante" << endl;
		cout << "2 - Eliminar un estudiante" << endl;
		cout << "3 - Calificar a los estudiantes" << endl;
		cout << "4 - Listado de estudiantes" << endl;
		cout << "0 - Salir" << endl;
		cout << "Opción: ";
		cin >> op;
	} while ((op < 0) || (op > 4));
	return op;
}

void cargar(tLista& lista, bool& ok) {
	tEstudiante estudiante;
	ifstream archivo;

	lista.contador = 0;
	archivo.open("clase.txt");
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		ok = true;
		getline(archivo, estudiante.nombre);
		while ((estudiante.nombre != "XXX") && (lista.contador < MAX)) {
			getline(archivo, estudiante.apellidos);
			archivo >> estudiante.edad;
			archivo >> estudiante.cedula;
			archivo >> estudiante.nota;
			//aux
			lista.elementos[lista.contador] = estudiante;
			lista.contador++;
			getline(archivo, estudiante.nombre); //siguiente nombre
		} //SI hay más de MAX estudiantes, se ignorar
	}

}

void guardar(const tLista lista) {
	ofstream archivo;
	archivo.open("clase.txt");
	for (int i = 0; i < lista.contador; i++) {
		archivo << lista.elementos[i].nombre << endl;
		archivo << lista.elementos[i].apellidos << endl;
		archivo << lista.elementos[i].edad << endl;
		archivo << lista.elementos[i].cedula << endl;
		archivo << lista.elementos[i].nota << endl;
	}
	archivo << "XXX" << endl; //centinela
	archivo.close();
}

void leerEstudiante(tEstudiante& estudiante) {
	cin.sync();
	cout << "Nombre: ";
	getline(cin, estudiante.nombre);
	cout << "Apellidos: ";
	getline(cin, estudiante.apellidos);
	cout << "Edad: ";
	cin >> estudiante.edad;
	cout << "NIF: ";
	cin >> estudiante.cedula;
	estudiante.nota = -1; // Sin calificar de momento
	cin.sync(); // Descartamos cualquier entrada pendiente
}
void insertarEstudiante(tLista& lista, tEstudiante estudiante, bool& ok) {
	ok = true;
	if (lista.contador == MAX) {
		ok = false;
	}
	else {
		lista.elementos[lista.contador] = estudiante;
		//insertamos al final
		lista.contador++;
	}
}

void eliminarEstudiante(tLista& lista, int pos, bool& ok) {
	// Espera el índice del elemento en pos

	if ((pos < 0) || (pos > lista.contador - 1)) {
		ok = false; // Elemento inexistente
	}
	else {
		ok = true;
		for (int i = pos; i < lista.contador - 1; i++) {
			lista.elementos[i] = lista.elementos[i + 1];
		}
		lista.contador--;
	}
}

string nombreCompleto(tEstudiante estudiante) {
	return estudiante.nombre + " " + estudiante.apellidos;
}

void calificar(tLista& lista) {
	for (int i = 0; i < lista.contador; i++) {
		cout << "Notal del estudiante " << nombreCompleto(lista.elementos[i]) << ": ";
		cin >> lista.elementos[i].nota;
	}
}

int mayorNota(const tLista lista) {
	double max = 0;
	int pos = 0;
	for (int i = 0; i < lista.contador; i++) {
		if (lista.elementos[i].nota > max) {
			max = lista.elementos[i].nota;
			pos = i;
		}
	}
	return pos;
}

double mediaClase(const tLista lista) {
	double total = 0.0;
	for (int i = 0; i < lista.contador; i++) {
		total = total + lista.elementos[i].nota;
	}
	return total / lista.contador;
}

void listado(const tLista lista, double media, int mayor) {
	for (int i = 0; i < lista.contador; i++) {
		cout << setw(3) << right << i + 1 << ": ";
		cout << setw(38) << left << nombreCompleto(lista.elementos[i]);
		cout << lista.elementos[i].cedula << " ";
		cout << setw(2) << right << lista.elementos[i].edad << " años ";
		cout << fixed << setprecision(1) << lista.elementos[i].nota;
		if (i == mayor) {
			cout << " Mayor nota!";
		}
		cout << endl;
	}
	cout << "Media de la  clase: " << fixed << setprecision(1) << media << endl << endl;
}