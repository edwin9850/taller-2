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
#include <stdlib.h>
#include <time.h>
using namespace std;

void numeros_aleatorios(int arreglo[], int n);
void histograma(int arreglo[], int n);

int main() {
  int arreglo[100], opcion, n;

  do {
    cout << "escoga una opcion" << endl;
    cout << "1. numeros aleatorios y llenar el vector" << endl;
    cout << "2. histograma" << endl;
    cout << "3. salir " << endl << endl;
    cin >> opcion;

    switch (opcion) {
    case 1:
      cout << "cuantos numeros quiere: ";
      cin >> n;
      numeros_aleatorios(arreglo, n);
      cout << endl << endl;
      break;
    case 2:
      histograma(arreglo, n);
      cout << endl << endl;

      break;

    case 3:
      return 0;

      break;

    }
  } while (opcion != 3);
}

void numeros_aleatorios(int arreglo[], int n) {

  /*  cout << "cuantos numeros quiere: ";
    cin >> n; */
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    arreglo[i] = rand() % 20;
  }
  for (int j = 0; j < n; j++) {
    cout << "su numero " << j + 1 << " es " << arreglo[j] << endl;
  }
}

void histograma(int arreglo[], int n) {
  int *puntero, a;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (*puntero == arreglo[i]) {
        cout<<"*";
        
      }
    }
  }
}


