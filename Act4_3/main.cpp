/*
    Iván Alberto Romero Wells - A00833623
    Mariano Barberi Garza - A01571226

    Compilación:
        g++ -std=c++17 -Wall -o main *.cpp

    Ejecución:
        main
*/

#include <iostream>
#include "Graph.h"
#include <sstream>
#include <fstream>

int main()
{
    std::ifstream in("bitacoraGrafos.txt");
    Graph g;
    std::ofstream out2("grados_ips.txt");
    std::ofstream out3("mayores_grados_ips.txt");
    g.readGraph(in);
    g.countGraph(out2);
    g.getTopN(3, out3);
    out2.close();
    out3.close();
    in.close();
    std::cout << "Boot Master: " << g.getBootMaster() << std::endl;
    g.getMinCaminos(g.getBootMaster());
    std::ofstream out4("distancia_bootmaster.txt");
    g.printMinCaminos(out4);
    out4.close();

    g.printMaxDistancia(std::cout);

    return 0;
}