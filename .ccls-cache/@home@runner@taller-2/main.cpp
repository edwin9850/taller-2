/*
15/02/2023
tema: arrays, clase vectores, aleatoridad, funciones

problema:
-crear una forma para general un conjunto de numeros aleatorios, tal que se
pueda contar la frecuencia y poder graficar tipo histograma -se recomienda usar
funciones, arrays y clase de vectores de STL. -para general el conjunto de
aleatorios se deberia preguntar la cantidad de elementos al usuario se
recomienda tambien hacer un menu

*/

#include <iostream>
#include <stdlib.h> //estas dos bibliotecarioas son para los numeros aleatorios
#include <time.h>
using namespace std;

// llamado del parametro de la funcion
void numeros_aleatorios();
void histograma();

struct datos {
  int tamaño;
  int max_valor;
  int arreglo[100];
};
datos x;

int main() {
  int opcion;

  do { // se crea un bucle, hasta que escoga la opcion 3 para salir
    cout << "escoga una opcion" << endl;
    cout << "1. numeros aleatorios y llenar el vector" << endl;
    cout << "2. histograma" << endl;
    cout << "3. salir " << endl << endl;
    cin >> opcion; // se guarda la opcion que escogio el usuario

    switch (opcion) { // se crea un meno, para que escoja la opcion que desea
    case 1:
      cout << "cuantos numeros quiere: ";
      cin >> x.tamaño;      // cuantos numeros se van a crear.
      numeros_aleatorios(); // se llama la funcion.
      cout << endl << endl;
      break;
    case 2:
      histograma();
      cout << endl << endl;

      break;

    case 3:
      return 0;

      break;
    default:
      cout << "esta opcion no existe" << endl;
      break;
    }
  } while (opcion != 3);
}

void numeros_aleatorios() { // se crea la funcion de numeros aleatorios.

  srand(time(NULL));
  for (int i = 0; i < x.tamaño;
       i++) { // cantidad de datos con que se va a llenar el array

    x.arreglo[i] = rand() % 10; // se llena el array con los numeroa aletorios
  }
  for (int j = 0; j < x.tamaño; j++) { // mostrar los datos.
    cout << "su numero " << j + 1 << " es " << x.arreglo[j] << endl;
  }
  for (int i = 0; i < x.tamaño; i++) {
    for (int j = i+1; j < x.tamaño; j++) {
      if (x.arreglo[i] > x.arreglo[j]) {
        x.max_valor = x.arreglo[i];
      }
    }
  }
  cout << endl;
  cout << "max :" << x.max_valor;
  cout << endl;
  cout << "size: " << x.tamaño;
  cout << endl;
}

void histograma() {

  // se crean dos blucles, en el cual se va a comprar el arreglo, buscando los que sea repitan.
  cout << endl;

  cout << "valor"
       << "  "
       << "veces que repite"
       << "  "
       << "histograma";
  cout << endl;
  for (int i = 0; i < x.tamaño; i++) {
    int contador = 0;
    for (int j = i + 1; j < x.tamaño; j++) {
      if (x.arreglo[j] ==
          x.arreglo[i]) { // compara los arreglos y cuando encuentran que dos valores coinciden, se suma 1 al contador

        contador++;
      }
    }
    if (contador > 0) { // si hay elemntos repetidos los mostramos

      cout << "   " << x.arreglo[i] << "              " << contador + 1
           << "          ";
      for (int j = 0; j < contador + 1; j++) {
        cout << "* ";
      }
      cout << endl;
    }
  }
}

