class Cola {

    struct Nodo {
        int prioridad;
        Nodo * siguiente;
        Nodo(int);
    };

    Nodo * primero;
    Nodo * minimo;

public:

    Cola();

};