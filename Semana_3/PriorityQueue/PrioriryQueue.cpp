#include <iostream>
#include <string>
using namespace std;

#include "PrioriryQueue.h"

ColaPrioridad::Nodo::Nodo(int d, Nodo * n) : prioridad{d}, siguiente{n} {}

ColaPrioridad::ColaPrioridad() : primero{nullptr}, minimo{nullptr} {}

void ColaPrioridad::insertar(int prioridad){ //O(1)
    primero = new Nodo(prioridad, primero);
    if(minimo == nullptr || primero->prioridad < minimo->prioridad)
        minimo = primero;
}

int ColaPrioridad::consultarMinimo() const{ //O(1)
    if(minimo == nullptr){
        throw string("intentando usar cola vacia");
    }
    return minimo->prioridad;
}

void ColaPrioridad::eliminarMinimo() { // O(n)
    if (primero == nullptr) {
        throw string("Intentando eliminar el minimo en una cola de prioridad vacia");
    }

    Nodo *nuevoMinimo = nullptr;
    Nodo *anterior = nullptr;

    for (Nodo *actual = primero; actual != nullptr; actual = actual->siguiente) {
        if (actual == minimo){
            if (anterior == nullptr) {
                primero = minimo->siguiente;
            } else {
                anterior->siguiente = minimo->siguiente;
            }
        } else {
            if (nuevoMinimo == nullptr || actual->prioridad < nuevoMinimo->prioridad) {
                nuevoMinimo = actual;
            }
        }
        anterior = actual;
    }

    delete minimo;
    minimo = nuevoMinimo;
}


