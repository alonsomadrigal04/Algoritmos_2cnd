class ColaPrioridad {

    struct Nodo {
        int prioridad;
        Nodo * siguiente;
        Nodo(int, Nodo *);
    };

    Nodo * primero;
    Nodo * ultimo;

    void insertarRecursivo(int, Nodo*&);

public:

    ColaPrioridad();

    void insertar(int);

    void insertarRecursivo(int);

    int consultarMinimo() const;

    void eliminarMinimo();
};