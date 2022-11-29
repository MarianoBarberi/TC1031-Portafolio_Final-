/*
    Iván Alberto Romero Wells - A00833623
    Mariano Barberi Garza - A01571226

    Compilación:
        g++ -std=c++17 -Wall -o main *.cpp

    Ejecución:
        main
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "BinarySearchTree.h"
#include "Bitacora.h"
#include "Node.h"
#include "PriorityQueue.h"
#include "Registro_Count.h"
#include "Registro.h"

int main()
{
    std::ifstream file("bitacoraHeap.txt");
    std::ofstream bitacora_ordenada("bitacora_ordenada.txt");
    std::ofstream ips_con_mayor_acceso("ips_con_mayor_acceso.txt");
    Bitacora bitacora;
    std::cout << "Leyendo archivo..." << std::endl;
    bitacora.ReadFile(file);
    std::cout << "Archivo leido" << std::endl;

    std::cout << "Ordenando registros..." << std::endl;
    bitacora.printBitacora(bitacora_ordenada);
    std::cout << "Contando accesos por IP..." << std::endl;
    bitacora.GroupByIP();

    std::cout << "Registros ordenados" << std::endl;
    bitacora.printTopN(5, ips_con_mayor_acceso);
    std::cout << "Top 5 IPs con mayor acceso" << std::endl;

    bitacora_ordenada.close();
    ips_con_mayor_acceso.close();

    return 0;
}
