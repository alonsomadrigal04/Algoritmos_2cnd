#include <iostream>
#include <string>
using namespace std;

#include "Double-ended Priority Queue.h"

ColaPrioridad::Nodo::Nodo(int d, Nodo * s, Nodo * a) : prioridad{d}, anterior{s}, siguiente{a}{}

ColaPrioridad::ColaPrioridad() : maximo{nullptr}, minimo{nullptr}, laTalla{0} {}

void ColaPrioridad::insertar(int n){
    laTalla++;

    if(maximo == nullptr){
        maximo = new Nodo(n, nullptr, nullptr);
        minimo = maximo;
    }

    if(maximo->prioridad < n){
        maximo = new Nodo(n, maximo, nullptr);
        maximo->anterior->siguiente = maximo;
    }
    else if(minimo->prioridad > n){
        minimo = new Nodo(n, nullptr, minimo);
        minimo->siguiente->anterior = minimo;
    }
    else{
        for(Nodo*actual = minimo; actual != nullptr ; actual = actual->siguiente){
            if(actual->prioridad > n){
                Nodo * nuevo = new Nodo(n, actual->anterior, actual);
                actual->anterior->siguiente = nuevo;
                actual->anterior = nuevo;
                return;
            }
        }
    }


}

void ColaPrioridad::insertarRecursivo(int n, Nodo * actual){
    if(actual->prioridad > n){
        Nodo * nuevo = new Nodo(n, actual->anterior, actual);
        nuevo->anterior->siguiente = nuevo;
        actual->anterior = nuevo;
        return;
    }
    else
        insertarRecursivo(n, actual->siguiente);
}

void ColaPrioridad::insertarRecursivo(int n){
    if(minimo == nullptr){
        minimo = new Nodo(n, nullptr, nullptr);
        minimo = maximo;
    }
    else if(minimo->prioridad > n){
        minimo = new Nodo(n, nullptr, minimo);
        minimo->siguiente->anterior = minimo;
    }
    else if(maximo->prioridad < n){
        maximo = new Nodo(n, maximo, nullptr);
        maximo->anterior->siguiente = maximo;
    }
    else{
        insertarRecursivo(n, minimo);
    }
}

void ColaPrioridad::mostrar() const{
    if(talla == 0){
        throw string("cola vacia");
    }

    cout << "[" ;
    for(Nodo * actual = minimo; actual != nullptr; actual = actual->siguiente){
        cout << actual->prioridad << ", ";
    }
}

void ColaPrioridad::eliminar(int n){
    if(laTalla == 0)
        throw string("la cola está vacia");
    for(Nodo * actual = minimo; actual != nullptr; actual = actual->siguiente){
        if(actual->prioridad == n){
            if(minimo == maximo){
                minimo = maximo = nullptr;
            }
            if(actual == minimo){
                minimo = minimo->siguiente;
                minimo->anterior = nullptr;
            }
            if(actual == maximo){
                maximo = maximo->anterior;
                maximo->siguiente = nullptr;
            }
            else{
                actual->anterior->siguiente = actual->siguiente;
	            actual->siguiente->anterior = actual->anterior;
            }
            delete actual;
            laTalla--;
            return;
        }
    }
    throw string("intentando eliminar elemento inxistente");
}   

void ColaPrioridad::eliminarRecursivo(int n, Nodo *& actual){
    if(actual->prioridad == n){
        if(minimo == actual)
            minimo = minimo->siguiente;
        else
            actual->anterior->siguiente = actual->siguiente;

        if(maximo == actual)
            maximo = maximo->anterior;
        else
            actual->siguiente->anterior = actual->anterior;

        laTalla--;
        delete actual;
    }else{
        eliminarRecursivo(n, actual->siguiente);
    }
}

void ColaPrioridad::eliminarRecursivo(int n){
    if(minimo == nullptr || minimo->prioridad > n)
        throw string("Intenando borrar elemento inexistente");

    eliminarRecursivo(n, minimo);

}

int ColaPrioridad::consultarMinimo() const{
    cmpVacia();
    return minimo->prioridad;
}

void ColaPrioridad::eliminarMinimo(){
    cmpVacia();
    if(minimo == maximo )
        minimo = maximo = nullptr;
    else{
        minimo = minimo->siguiente;
        minimo->anterior = nullptr;
    }
}

int ColaPrioridad::consultarMaximo() const{
    cmpVacia();
    return maximo->prioridad;
}

int ColaPrioridad::talla() const{
    return laTalla;
}

void ColaPrioridad::eliminarMaximo(){
    cmpVacia();
    if(minimo == maximo )
        minimo = maximo = nullptr;
    else{
        maximo = maximo->anterior;
        maximo->siguiente = nullptr;
    }
}

void ColaPrioridad::cmpVacia() const{
    if(minimo == nullptr)
        throw string("Intenando usar cola inexistente");
}

void ColaPrioridad::vaciar(){
    cmpVacia();

    for(Nodo * actual = minimo; actual != nullptr; actual = actual ->siguiente){
        actual->anterior = nullptr;
        delete actual;
    }
    minimo = maximo = nullptr;
    laTalla = 0;
}