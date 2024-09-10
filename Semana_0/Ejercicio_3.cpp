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
    int mitad = listaNumeros.size() / 2;
    while(n != listaNumeros[mitad])
    {
        int mitad = listaNumeros.size() / 2;
        if(mitad >)
    }
    
}