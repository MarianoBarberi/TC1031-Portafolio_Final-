/*
    Iván Alberto Romero Wells - A00833623
    Mariano Barberi Garza - A01571226

    Compilación:
        g++ -std=c++17 -Wall -o main *.cpp

    Ejecución:
        main
*/

#include <iostream>
#include <fstream>
#include "Bitacora.h"

int main()
{
    std::ifstream input("bitacora.txt");
    Bitacora bitacora;
    bitacora.readInput(input);
    // bitacora.print();
    bitacora.sort();
    std::ofstream output("bitacora_ordenada.txt");
    bitacora.print(output);
    output.close();
    // bitacora.print();
    bitacora.getRango();
    std::cout << "Rango obtenido: " << std::endl;
    bitacora.printRango(std::cout);

    // Ejemplos para bitacora.txt

    // Rango completo
    // Jul 04 18:49:57
    // Jul 13 21:30:11

    // Rango parcial (no inicio)
    // Jul 04 18:49:58
    // Jul 13 21:30:11

    // Rango parcial (no fin)
    // Jul 04 18:49:57
    // Jul 13 21:30:10

    // Rango parcial (no inicio ni fin)
    // Jul 04 18:49:58
    // Jul 13 21:30:10

    return 0;
}