#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& listaNumeros) {
    int aux;
    for (int i = 0; i < listaNumeros.size() - 1; i++) {
        int indice = i;
        int minimo = listaNumeros[i];

        for (int j = i + 1; j < listaNumeros.size(); j++) {
            if (listaNumeros[j] < minimo) {
                minimo = listaNumeros[j];
                indice = j;
            }
        }
        aux = listaNumeros[i];
        listaNumeros[i] = listaNumeros[indice];
        listaNumeros[indice] = aux;
    }
}

// Mejor y peor caso es el mismo O(n^2) por que tenemos que pasar primero por todo el vector para comprobar
// di el numero que tenemos es el menor de todos los demas para intercambiarlo. así con todos los numeros
// 2 pasadas del vector.

int main() {
    vector<int> numeros = {9, 3, 5, 2, 8, 1};

    selectionSort(numeros);

    for (int num : numeros) {
        cout << num << " ";
    }

    return 0;
}
