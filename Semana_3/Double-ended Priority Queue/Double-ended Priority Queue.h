class ColaPrioridad {

    struct Nodo {
        int prioridad;
        Nodo * anterior;
        Nodo * siguiente;
        Nodo(int, Nodo *, Nodo *);
    };

    Nodo * maximo;
    Nodo * minimo;
    int laTalla;

    void insertarRecursivo(int, Nodo*);

    void eliminarRecursivo(int, Nodo*&);

public:

    ColaPrioridad();

    void insertar(int);          // O(n)

    void insertarRecursivo(int);  //O(n)

    void eliminar(int);          // O(n)

    void eliminarRecursivo(int);

    void eliminarMinimo();       // O(1) 

    int consultarMinimo() const; // O(1) 

    void eliminarMaximo();       // O(1) 

    int consultarMaximo() const; // O(1)

    int talla() const;           // O(1)

    void mostrar() const;        // O(n)

    void cmpVacia() const;

    void vaciar();
};