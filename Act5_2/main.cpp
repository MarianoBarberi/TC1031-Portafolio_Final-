/*
    Iván Alberto Romero Wells - A00833623
    Mariano Barberi Garza - A01571226

    Compilación:
        g++ -std=c++17 -Wall -o main *.cpp

    Ejecución:
        main
*/

#include <iostream>
#include "HashTable.h"
#include "HashNode.h"
#include "NodeInfo.h"
#include <fstream>
#include <string>

int main()
{
    std::ifstream in("bitacoraGrafos.txt");
    std::cout << "Leyendo archivo..." << std::endl;
    HashTable Registros(18181);
    std::cout << "Leyendo registros..." << std::endl;
    Registros.readFromFile(in);
    std::cout << "Registros leidos" << std::endl;
    in.close();
    std::cout << "Archivo cerrado" << std::endl;
    // Registros.print();
    std::cout << "Imprimiendo nodos..." << std::endl;
    std::cout << "Colisiones: " << Registros.getColisions() << std::endl;

    std::cout << "Summary: 36.54.83.103" << std::endl;
    Registros.getIPSummary("36.54.83.103");

    return 0;
}