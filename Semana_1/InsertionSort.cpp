#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& listaNumeros) {
    int aux;
    for (int i = 1; i < listaNumeros.size(); i++) {
        if (listaNumeros[i] < listaNumeros[i - 1]) {
            int j = i;
            while (j > 0 && listaNumeros[j] < listaNumeros[j - 1]) {
                aux = listaNumeros[j];
                listaNumeros[j] = listaNumeros[j - 1];
                listaNumeros[j - 1] = aux;
                j--;
            }
        }
    }
}

// Mejor caso O(n) este caso es que el vector ya esté ordenado por lo que no tendremos que pasar
//  por los elementos del vector.

// Peor caso O(n^2) este caso es que el vector no esté ordenado y todos estén en desorden
// tendriamos que repasar todo el vector dos veces, primero para comprar si el anterior es menor,
// hasta que lo sea. Asi con todos los numeros.


int main() {
    vector<int> numeros = {9, 3, 5, 2, 8, 1};

    insertionSort(numeros);

    for (int num : numeros) {
        cout << num << " ";
    }

    return 0;
}
