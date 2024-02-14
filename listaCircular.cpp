#include "listaCircular.h"
#include <iostream>

Lista::Lista() {
    primero = nullptr;
    cantidad = 0;
    suma = 0;
}
 
Nodo* Lista::obtener_nodo(int pos) {
    Nodo* pn = primero;
    for (int i = 1; i < pos; i++)
        pn = pn->obtener_siguiente();
    return pn;
}

void Lista::alta(Dato d) {
    Nodo* nuevo = new Nodo(d);
    if (cantidad < N) {
        if (primero == nullptr) {
            primero = nuevo;
            nuevo->cambiar_siguiente(nuevo);
        } else {
            Nodo* ultimo = primero;
            while (ultimo->obtener_siguiente() != primero) {
                ultimo = ultimo->obtener_siguiente();
            }
            ultimo->cambiar_siguiente(nuevo);
            nuevo->cambiar_siguiente(primero);
        }
        cantidad++;
        suma += d;
    } else {
        eliminar_mas_antiguo();
        Nodo* ultimo = primero;
        while (ultimo->obtener_siguiente() != primero) {
            ultimo = ultimo->obtener_siguiente();
        }
        nuevo->cambiar_siguiente(primero);
        ultimo->cambiar_siguiente(nuevo);
        cantidad++;
        suma += d;
    }
}

void Lista::baja(int pos) {
    Nodo* borrar = primero;
    if (pos == 1) {
        primero = borrar->obtener_siguiente();
    } else {
        Nodo* anterior = obtener_nodo(pos-1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    delete borrar;
    cantidad--;
}

Dato Lista::consulta(int pos) {
    Nodo* pn = obtener_nodo(pos);
    return pn->obtener_dato();
}

bool Lista::esta_vacia() {
return (cantidad == 0);
}

int Lista::obtener_cantidad() {
return cantidad;
}

Lista::~Lista() {
    while (!esta_vacia())
        baja(1);
}

Dato Lista::mas_antiguo() {
    if (cantidad == 0) {
        return 0;
    }
    return primero->obtener_dato();
}

double Lista::promedio() {
    if (cantidad == 0) {
        return 0.0;
    }
    return static_cast<double>(suma) / cantidad;
}

void Lista::eliminar_mas_antiguo() {
    if (primero == nullptr) {
        return;
    }

    Nodo* antiguo = primero;
    Nodo* ultimo = nullptr;

    while (antiguo->obtener_siguiente() != primero) {
        ultimo = antiguo;
        antiguo = antiguo->obtener_siguiente();
    }
    ultimo = antiguo;

    if (ultimo != nullptr) {
        ultimo->cambiar_siguiente(primero->obtener_siguiente());
    }
    
    suma -= primero->obtener_dato();
    cantidad--;

    if (ultimo != nullptr) {
        delete primero;
        primero = ultimo->obtener_siguiente();
    } else {
        delete primero;
        primero = nullptr;
    }
}

void Lista::imprimir() {
    if (primero == nullptr) {
        std::cout << "Lista vacía" << std::endl;
    } else {
        Nodo* pn = primero;
        std::cout << "Lista: [ ";
        for (int i = 0; i < cantidad; i++) {
            std::cout << pn->obtener_dato() << " ";
            pn = pn->obtener_siguiente();
        }
        std::cout<< ']' << std::endl;
        // Mostrar el valor más antiguo
        std::cout << "Valor más antiguo: " << mas_antiguo() << std::endl;

        // Mostrar el promedio de los elementos en la lista
        std::cout << "Promedio de los elementos: " << promedio() << std::endl;
        std::cout << std::endl;
    }
}