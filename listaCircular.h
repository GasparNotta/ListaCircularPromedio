#ifndef _LISTA_H_
#define _LISTA_H_
 
#include "nodo.h"

const int N = 5; // Tamaño máximo de la lista

class Lista {
private:
    Nodo* primero;
    int cantidad;
    int suma;
 
    // pre: -
    // pos: elimina el nodo más antiguo de la lista
    void eliminar_mas_antiguo();

    // pre: 0 < pos <= cantidad
    // pos: devuelve un puntero al nodo en la posicion pos
    Nodo* obtener_nodo(int pos);
    
public:
    // CONSTRUCTOR
    // pre: -
    // pos: construye una Lista
    Lista();

    // METODOS PUBLICOS
    
    // pre: -
    // pos: 1.Se agregará un nuevo nodo con el dato d al final de la lista si hay espacio disponible en la lista (cantidad < N).
    //      2.Si la lista ya tiene N elementos, el nodo más antiguo será eliminado y el nuevo nodo será agregado al final de la lista.
    //      3.La lista circular estará correctamente actualizada para mantener la integridad de la estructura.
    //      4.La cantidad total de elementos en la lista (cantidad) se incrementará en 1.
    //      5.La suma de todos los elementos en la lista (suma) se incrementará en d.
    //      6.El puntero primero apuntará al primer nodo de la lista, y la lista seguirá siendo válida después de la ejecución de la función.
    void alta(Dato d);

    // pre: 0 < pos <= obtener_cantidad()
    // pos: elimina de la Lista el elemento en la posicion pos 
    void baja(int pos);

    // pre: -
    // pos: devuelve true si la Lista esta vacia
    // devuelve false en caso contrario
    bool esta_vacia();

    // pre: 0 < pos <= obtener_cantidad()
    // pos: devuelve el elemento de la posicion pos 
    Dato consulta(int pos);

    // pre: -
    // pos: devuelve la cantidad de elementos en la lista
    int obtener_cantidad();

    // pre: -
    // pos: devuelve el valor más antiguo en la lista
    Dato mas_antiguo();

    // pre: -
    // pos: devuelve el promedio de los elementos en la lista
    double promedio();

    // pre: -
    // pos: imprime la lista en consola
    void imprimir();

    // DESTRUCTOR
    // pre: -
    // pos: destruye la Lista y libera toda la memoria utilizada.
    ~Lista();
};


#endif // _LISTA_H_