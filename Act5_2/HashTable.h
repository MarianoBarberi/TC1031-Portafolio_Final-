#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <iostream>
#include <vector>
#include <stdexcept>
#include "HashNode.h"
#include "NodeInfo.h"

class HashTable
{
private:
    std::vector<HashNode> table;
    int size;
    int maxSize;
    int colisions;
    void readEdges(std::istream &in, int m);

public:
    HashTable(int selectedMaxSize);
    void readFromFile(std::istream &in);
    int getHashIndex(std::string ip);
    int getSize();
    void print();
    void add(std::string ip);
    int findIndex(std::string ip);
    NodeInfo getDataAt(int index);
    void addOut(std::string ip);
    void addIn(std::string ip);
    void clearData(std::string ip);
    void remove(std::string ip);
    int getColisions();
    void getIPSummary(std::string ip);
};

HashTable::HashTable(int maxSize)
{
    // O(1)
    this->size = 0;
    this->maxSize = maxSize;
    this->table.resize(maxSize);
}

int HashTable::getHashIndex(std::string ip)
{
    // O(1)
    int sum = 0;
    for (int i = 0; i < (int)ip.length(); i++)
    {
        // sumar el valor numérico ASCII de cada caracter para pasar de string a int
        sum += ip[i];
    }
    // utilizando el método de residuales (llave % tamaño) ** Tamaño debe ser primo (mientras más grande, posiblemente menores colisiones) **
    return sum % maxSize;
}

int HashTable::getSize()
{
    // O(1)
    return size;
}

void HashTable::print()
{
    // O(n)
    for (auto i : table)
    {
        if (i.getStatus() == 1)
        {
            std::cout << i.getData() << std::endl;
        }
    }
}

void HashTable::add(std::string ip)
{
    // O(1)
    if (size == maxSize)
    {
        throw std::out_of_range("Limit of records reached");
    }
    int index = getHashIndex(ip);
    HashNode nodeAt = table[index];

    if (nodeAt.getStatus() != 1)
    {
        // posición vacía
        table[index] = HashNode(ip);
        size++;
    }
    else
    {
        if (nodeAt.getIp() == ip)
        {
            throw std::invalid_argument("Key already exists");
        }
        else
        {
            // colisión
            int i = 1;
            // Encontrando el siguiente espacio libre usando la exploración cuadrática (index + i^2) hasta encontrar un espacio vacío
            // https://www.geeksforgeeks.org/quadratic-probing-in-hashing/
            while (table[(index + i * i) % maxSize].getStatus() == 1)
            {
                i++;
            }
            table[(index + i * i) % maxSize] = HashNode(ip);
            table[index].addToOverflow((index + i * i) % maxSize);
            size++;
            colisions++;
        }
    }
}
int HashTable::findIndex(std::string ip)
{
    // O(n)
    int index = getHashIndex(ip);
    HashNode nodeAt = table[index];

    if (nodeAt.getStatus() == 1)
    {
        if (nodeAt.getIp() == ip)
        {
            return index;
        }
        else
        {
            // colisión
            // O(n)
            for (int i = 0; i < nodeAt.getOverflowSize(); i++)
            {
                if (table[nodeAt.getOverflowAt(i)].getIp() == ip)
                {
                    return nodeAt.getOverflowAt(i);
                }
            }
            return -1;
        }
    }
    return -1;
}

NodeInfo HashTable::getDataAt(int index)
{
    // O(1)
    return table[index].getData();
}

void HashTable::addOut(std::string ip)
{
    // O(n)
    int index = findIndex(ip);
    if (index != -1)
    {
        table[index].addOut(ip);
    }
    else
    {
        throw std::invalid_argument("Key does not exist");
    }
}

void HashTable::addIn(std::string ip)
{
    // O(n)
    int index = findIndex(ip);
    if (index != -1)
    {
        table[index].addIn(ip);
    }
    else
    {
        throw std::invalid_argument("Key does not exist");
    }
}

void HashTable::clearData(std::string ip)
{
    // O(n)
    int index = findIndex(ip);
    if (index != -1)
    {
        table[index].clearData();
    }
    else
    {
        throw std::invalid_argument("Key does not exist");
    }
}

void HashTable::remove(std::string ip)
{
    // O(n)
    int index = findIndex(ip);
    if (index != -1)
    {
        table[index].clearData();
        table[index].setStatus(0);
        size--;
    }
    else
    {
        throw std::invalid_argument("Key does not exist");
    }
}

void HashTable::readEdges(std::istream &in, int m)
{
    // O(n)
    std::string mes, dia, hora, origen, destino, peso, type;
    std::string originIp, destIp;

    for (int i = 0; i < m; i++)
    {
        in >> mes >> dia >> hora >> origen >> destino >> peso;
        std::getline(in, type);
        originIp = origen.substr(0, origen.find(":"));
        destIp = destino.substr(0, destino.find(":"));

        addOut(destIp);
        table[findIndex(originIp)].addIn(destIp);
    }
}

void HashTable::readFromFile(std::istream &in)
{
    // O(n^2 + mn)
    std::string n, m;
    in >> n >> m;
    for (int i = 0; i < std::stoi(n); i++)
    {
        std::string ip;
        in >> ip;
        ip = ip.substr(0, ip.find(":"));
        add(ip);
    }
    readEdges(in, std::stoi(m));
}

int HashTable::getColisions()
{
    // O(1)
    return colisions;
}

void HashTable::getIPSummary(std::string ip)
{
    // O(n)
    int index = findIndex(ip);
    if (index != -1)
    {
        std::cout << table[index].getData() << std::endl;
    }
    else
    {
        throw std::invalid_argument("Key does not exist");
    }
}

#endif // _HASH_TABLE_H_
