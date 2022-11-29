#ifndef _REGISTRO_COUNT_H_
#define _REGISTRO_COUNT_H_

#include <iostream>
#include "Registro.h"

class Registro_Count
{
private:
    Registro registro;
    int count;

public:
    Registro_Count();
    Registro_Count(Registro registro, int count);
    Registro_Count(Registro registro);
    ~Registro_Count();
    Registro getRegistro();
    int getCount();
    void setCount(int count);
    bool operator<(const Registro_Count &other) const;
    bool operator>(const Registro_Count &other) const;
    bool operator==(const Registro_Count &other) const;
    bool operator!=(const Registro_Count &other) const;
    void operator++();
    friend std::ostream &operator<<(std::ostream &out, const Registro_Count &registro_count);
};

Registro_Count::Registro_Count()
{
    // O(1)
    count = 0;
}

Registro_Count::Registro_Count(Registro registro, int count)
{
    // O(1)
    this->registro = registro;
    this->count = count;
}

Registro_Count::Registro_Count(Registro registro)
{
    // O(1)
    this->registro = registro;
    count = 1;
}

Registro_Count::~Registro_Count()
{
    // O(1)
}

Registro Registro_Count::getRegistro()
{
    // O(1)
    return registro;
}

int Registro_Count::getCount()
{
    // O(1)
    return count;
}

void Registro_Count::setCount(int count)
{
    // O(1)
    this->count = count;
}

bool Registro_Count::operator<(const Registro_Count &other) const
{
    // O(1)
    return count < other.count;
}

bool Registro_Count::operator>(const Registro_Count &other) const
{
    // O(1)
    return count > other.count;
}

bool Registro_Count::operator==(const Registro_Count &other) const
{
    // O(1)
    return count == other.count;
}

bool Registro_Count::operator!=(const Registro_Count &other) const
{
    // O(1)
    return count != other.count;
}

void Registro_Count::operator++()
{
    // O(1)
    count++;
}

std::ostream &operator<<(std::ostream &out, const Registro_Count &registro_count)
{
    // O(1)
    out << registro_count.registro << " " << registro_count.count;
    return out;
}

#endif // _REGISTRO_COUNT_H_