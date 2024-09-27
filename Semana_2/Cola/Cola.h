class Cola {

    struct Nodo {
        int dato;
        Nodo * siguiente;
        Nodo(int);
    };

    Nodo * primero;
    Nodo * ultimo;

    void mostrar(Nodo *) const;

    bool buscarRecursivo(int, Nodo*) const;

    void eliminarRecursivo(int, Nodo*, Nodo*);

    int buscarPosicionRecursivo(int, Nodo *, int&) const;

    bool colasIgualesRecursivo(const Cola &, Nodo *, Nodo*) const;



public:

    Cola();

    bool buscarRecursivo(int) const;

    void encolar(int);

    void desencolar();

    int consultarPrimero() const;

    void mostrar() const;

    bool estaVacia() const;

    bool buscar(int) const;

    void eliminar(int);

    void eliminarRecursivo(int);

    int buscarPosicion(int) const;

    int buscarPosicionRecursivo(int) const;

    bool colasIguales(const Cola &) const;

    bool colasIgualesRecursivo(const Cola &) const;

};