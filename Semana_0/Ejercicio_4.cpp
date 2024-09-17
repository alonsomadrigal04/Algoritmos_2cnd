#include <iostream>
#include <vector>

using namespace std;
// Bascar valor dentro de un vector

// buscqueda Binaria recursiva
int BusquedaBinariaRecursiva(int n, vector<int> listaNumeros, int inicio, int final)
{
    if (inicio > final) return -1;
    int mitad = (inicio + final) / 2;

    if (listaNumeros[mitad] > n)
        return BusquedaBinariaRecursiva(n, listaNumeros, inicio, mitad - 1);
    else if (listaNumeros[mitad] < n)
        return BusquedaBinariaRecursiva(n, listaNumeros, mitad + 1, final);
    else
        return mitad;
}