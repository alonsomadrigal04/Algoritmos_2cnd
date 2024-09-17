#include <iostream>
#include <vector>

using namespace std;
// Bascar valor dentro de un vector

// Secuencial iterativo
int BusquedaLenta(int n, vector<int> listaNumeros)
{
    for(int i = 0; i < listaNumeros.size(); i++)
    {
        int posicion = listaNumeros[i];
        if(posicion == n) return posicion;
    }
    return -1;
}

// Busqueda Binaria iterativa
int BusquedaBinariaLenta(int n, vector<int> listaNumeros)
{
    int final = listaNumeros.size();
    int inicio = 0;
    int mitad = (final + inicio) / 2;
    while(n != listaNumeros[mitad])
    {
        int mitad = (final + inicio) / 2;
        if(listaNumeros[mitad] > n) final = mitad - 1;
        else if(listaNumeros[mitad] < n) inicio = mitad + 1;
        else return mitad;
    }
    return -1;
}



