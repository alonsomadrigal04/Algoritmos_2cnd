

#include <iostream>
#include <string>
using namespace std;

#include "Cola.h"

Cola::Nodo::Nodo(int d) : dato{d}, siguiente{nullptr} {
}

Cola::Cola() : primero{nullptr}, ultimo{nullptr} {
}
  
void Cola::encolar(int d) {
   Nodo * nuevo = new Nodo(d);

   if (primero == nullptr) // Tambien valdria if (estaVacia()); asi nos ahorramos la llamada
      primero = nuevo;
   else
      ultimo->siguiente = nuevo;
   ultimo = nuevo;
}

void Cola::desencolar() {
   if (primero == nullptr)
      throw string("Intentando desencolar en una cola vacia");

   Nodo * aux = primero;
   primero = primero->siguiente;
   delete aux;
   if (primero == nullptr)
      ultimo = nullptr;
}

int Cola::consultarPrimero() const {
   if (primero == nullptr)
      throw string("Intentando consultar el primero en una cola vacia");
   return primero->dato;
}

void Cola::mostrar(Nodo * aux) const {
   if (aux != nullptr) {
      cout << aux->dato;
      if (aux != ultimo)
	 cout << ", ";
      mostrar(aux->siguiente);
   }
}

void Cola::mostrar() const {
   cout << "[";
   mostrar(primero);
   cout << "]";
}

bool Cola::estaVacia() const {
   return primero == nullptr;
}

bool Cola::buscar(int n) const {
    if(primero == nullptr) return false;
    for(Nodo * actual = primero; actual != nullptr; actual = actual->siguiente)
        if(actual->dato == n)
            return true;
    return false;
}

bool Cola::buscarRecursivo(int n) const{
    return buscarRecursivo(n, primero);
}

bool Cola::buscarRecursivo(int n, Nodo * actual) const{
    if(actual == nullptr)
        return false;
    if(actual->dato == n)
        return true;
    return buscarRecursivo(n, actual->siguiente);
}

void Cola::eliminar(int n) {
    if (primero == nullptr) {
        throw string("Intentando eliminar elemento de cola vacia");
    }

    Nodo* anterior = nullptr;
    for (Nodo* actual = primero; actual != nullptr; actual = actual->siguiente) {
        if (actual->dato == n) {
            if (actual == primero) {
                primero = primero->siguiente;
                if (primero == nullptr)
                    ultimo = nullptr;
            }
            else if (actual == ultimo) {
                anterior->siguiente = nullptr;
                ultimo = anterior;
            }
            else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            return;
        }
        anterior = actual;
    }
    throw string("Elemento no encontrado en la cola");
}

void Cola::eliminarRecursivo(int n)
{
    if(primero == nullptr)
        throw string("Intentando borrar nodo de una cola vacia");
    eliminarRecursivo(n , primero, nullptr);
}

void Cola::eliminarRecursivo(int n, Nodo* actual, Nodo*anterior)
{
    if(actual->dato == n)
    {
        if(actual == nullptr)
            return;
        if(actual == primero){
            primero = primero->siguiente;
            if(primero == nullptr){
                ultimo = nullptr;
            }
        }
        else if(actual == ultimo){
            anterior->siguiente = nullptr;
            ultimo = anterior;
        }
        else{
            anterior->siguiente = actual->siguiente;
        }
        delete actual;
        return;
    }
    else
        eliminarRecursivo(n, actual->siguiente, actual);
}

int Cola::buscarPosicion(int n) const{
    int pos = 0;
    if(primero == nullptr) return -1;
    for(Nodo * actual = primero; actual != nullptr; actual = actual->siguiente){
        if(actual->dato == n) return pos;
        else pos++;
    }
    return -1;
}

int Cola::buscarPosicionRecursivo(int n) const{
    if(primero == nullptr) return -1;
    int pos = 0;
    return buscarPosicionRecursivo(n, primero, pos);
}


int Cola::buscarPosicionRecursivo(int n, Nodo * actual, int& pos) const{
    if(actual->dato == n) return pos;
    else return buscarPosicionRecursivo(n, actual->siguiente, ++pos);
}



bool Cola::colasIguales(const Cola & cola2) const
{
    Nodo * n1 = primero, * n2 = cola2.primero;
    while(n1->dato == n2->dato && n1 != nullptr && n2 != nullptr)
    {
        n1 = n1->siguiente;
        n2 = n2->siguiente;
    }

    return n1 == n2;
}
bool Cola::colasIgualesRecursivo(const Cola & cola2, Nodo * n1, Nodo *n2) const{
    if(n1 == nullptr || n2 == nullptr)
        return n1 == n2;
    else
        return n1->dato == n2->dato && colasIgualesRecursivo(cola2, n1->siguiente, n2->siguiente);
}

bool Cola::colasIgualesRecursivo(const Cola & cola2) const{
    if(cola2.primero == nullptr && primero == nullptr)
        return true;
    return colasIgualesRecursivo(cola2, primero, cola2.primero);
}
