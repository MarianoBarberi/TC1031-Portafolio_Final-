#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include "DoublyLinkedList.h"
#include "ListNode.h"
#include "Registro.h"
#include <string>
#include <fstream>
#include <sstream>

class Bitacora
{
private:
    DoublyLinkedList<Registro> bitacora;
    void ReadEdge(std::string line);

public:
    Bitacora();
    ~Bitacora();
    void print(std::ostream &out);
    void ReadFile(std::ifstream &file);
    void sort();
    void busquedaRango(Registro start, Registro end, std::ofstream &resultado_busqueda);
};

Bitacora::Bitacora()
{
    // O(1)
}

Bitacora::~Bitacora()
{
    // O(n)
    bitacora.clear();
}

void Bitacora::ReadFile(std::ifstream &file)
{
    // O(n)
    std::string line;
    while (getline(file, line))
    {
        ReadEdge(line);
    }
}

void Bitacora::ReadEdge(std::string line)
{
    // O(1)
    std::string mes, dia, hora, minuto, segundo, ip, puerto, falla;
    std::stringstream ss(line);
    ss >> mes >> dia >> hora >> ip;
    std::getline(ss, falla);
    minuto = hora.substr(3, 2);
    segundo = hora.substr(6, 2);
    hora = hora.substr(0, 2);
    puerto = ip.substr(ip.find(":") + 1, ip.length());
    ip = ip.substr(0, ip.find(":"));
    Registro r(mes, dia, hora, minuto, segundo, ip, puerto, falla);
    bitacora.addLast(r);
}

void Bitacora::print(std::ostream &out)
{
    // O(n)
    bitacora.print(out);
}

void Bitacora::sort()
{
    // O(n log n)
    bitacora.mergeSort();
}

void Bitacora::busquedaRango(Registro start, Registro end, std::ofstream &resultado_busqueda)
{
    // O(n) (n = cantidad de registros en el rango)
    // log n comparaciones
    DoublyLinkedList<Registro> rango = bitacora.getRange(start, end);
    if (rango.getTail()->getData() > end)
    {
        rango.removeLast();
    }
    if (rango.getHead()->getData() < start)
    {
        rango.removeFirst();
    }
    std::cout << "Rango de busqueda: " << start << " - " << end << std::endl;
    rango.print();
    ListNode<Registro> *current = rango.getHead();
    while (current != NULL)
    {
        resultado_busqueda << current->getData() << std::endl;
        current = current->getNext();
    }
    if (rango.getHead()->getData() != start)
    {
        std::cout << "No se encontro el primer registro en el rango especificado" << std::endl;
        resultado_busqueda << "No se encontro el primer registro en el rango especificado" << std::endl;
    }
    if (rango.getTail()->getData() != end)
    {
        std::cout << "No se encontro el ultimo registro en el rango especificado" << std::endl;
        resultado_busqueda << "No se encontro el ultimo registro en el rango especificado" << std::endl;
    }
    rango.clear();
    delete current;
}

#endif // _BITACORA_H_