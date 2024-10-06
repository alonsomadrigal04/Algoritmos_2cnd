#include <iostream>
#include <string>
using namespace std;

#include "PrioriryQueue.h"

ColaPrioridad::Nodo::Nodo(int d, Nodo * n) : prioridad{d}, siguiente{n} {}

ColaPrioridad::ColaPrioridad() : primero{nullptr}, ultimo{nullptr} {}

void ColaPrioridad::insertar(int prioridad){ //O(1)
    if(primero == nullptr || primero->prioridad > prioridad){
        primero = new Nodo(prioridad, primero);
        return; 
    }

    Nodo * anterior = nullptr;
    for(Nodo * actual = primero; actual != nullptr; actual = actual->siguiente){
        if(actual->prioridad >= prioridad){
            anterior->siguiente = new Nodo(prioridad, actual);
            return;
        }
        anterior = actual;
    }
}

void ColaPrioridad::insertarRecursivo(int n, Nodo *& actual){
    if(actual == nullptr || n <= actual->prioridad)
        actual = new Nodo(n, actual->siguiente);
    else
        insertarRecursivo(n, actual->siguiente);
}

void ColaPrioridad::insertarRecursivo(int n){
    insertarRecursivo(n, primero);
}

int ColaPrioridad::consultarMinimo() const{
    return primero->prioridad;
}

void ColaPrioridad::eliminarMinimo(){
    if(primero == nullptr)
        throw string("intentando borrar elemento de lista vacia");
    
    Nodo * basura = primero;
    primero = primero->siguiente;
    delete basura;
}