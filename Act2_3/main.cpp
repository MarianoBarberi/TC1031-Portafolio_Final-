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
#include "DoublyLinkedList.h"
#include "Registro.h"
#include "ListNode.h"
#include "Bitacora.h"
#include <fstream>
#include <ctime>

int main()
{
    std::ifstream in("bitacora.txt");
    std::cout << "Leyendo archivo..." << std::endl;
    Bitacora b;
    b.ReadFile(in);
    std::cout << "Archivo leido" << std::endl;
    in.close();
    std::cout << "Ordenando registros..." << std::endl;
    b.sort();
    std::cout << "Registros ordenados" << std::endl;

    std::ofstream out1("bitacora_ordenada.txt");
    b.print(out1);
    out1.close();

    std::cout << "Introduzca la fecha de inicio del rango (ej: Jun 01 00:22:36): ";
    std::string line;
    std::getline(std::cin, line);
    Registro start(line);
    std::cout << "Introduzca la fecha de fin del rango (ej: Jun 01 00:22:36): ";
    std::getline(std::cin, line);
    Registro end(line);
    std::ofstream out("resultado_busqueda.txt");
    b.busquedaRango(start, end, out);
    std::cout << "Busqueda terminada" << std::endl;
    out.close();
    return 0;
}