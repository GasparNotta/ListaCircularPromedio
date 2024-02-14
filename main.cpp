#include <iostream>
#include "listaCircular.h"


int main() {
    Lista lista;
 
    // Agregar algunos elementos a la lista
    lista.alta(10);
    lista.alta(20);
    lista.alta(30);
    lista.alta(40);
    lista.alta(50);
    std::cout << "______________Lista inicial______________" << std::endl;
    lista.imprimir();


    // Agregar más elementos que el tamaño máximo de la lista
    std::cout << "______________Lista primer cambio______________" << std::endl;
    lista.alta(60);
    lista.imprimir();

    std::cout << "______________Lista segundo cambio______________" << std::endl;
    lista.alta(70);
    lista.imprimir();

    std::cout << "______________Lista tercer cambio______________" << std::endl;
    lista.alta(80);
    lista.imprimir();

    std::cout << "______________Lista cuarto cambio______________" << std::endl;
    lista.alta(90);
    lista.imprimir();
    
    std::cout << "______________Lista ultimo cambio (Final)______________" << std::endl;
    lista.alta(100);
    lista.imprimir();


    return 0;
}