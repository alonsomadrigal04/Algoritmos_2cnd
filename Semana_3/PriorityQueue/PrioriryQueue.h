class ColaPrioridad {

    struct Nodo {
        int prioridad;
        Nodo * siguiente;
        Nodo(int, Nodo *);
    };

    Nodo * primero;
    Nodo * minimo;

public:

    ColaPrioridad();

    void insertar(int);

    int consultarMinimo() const;

    void eliminarMinimo();
};