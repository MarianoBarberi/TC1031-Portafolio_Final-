#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include "Registro.h"

class Bitacora
{
private:
    std::vector<Registro> Registros;
    int lowerBound(time_t fecha);
    int upperBound(time_t fecha);
    std::vector<Registro> Rango;
    time_t fechaInicial;
    time_t fechaFinal;
    void setFecha(std::string fecha1, int tipo);
    void getInputRango();

public:
    Bitacora();
    Bitacora(std::vector<Registro> Registros);
    ~Bitacora();
    void readInput(std::ifstream &input);
    void print(std::ostream &os);
    void sort();
    void getRango();
    void printRango(std::ostream &output);
};

Bitacora::Bitacora()
{
    // O(1)
    Registros = std::vector<Registro>();
    Rango = std::vector<Registro>();
}

Bitacora::Bitacora(std::vector<Registro> Registros)
{
    // O(1)
    this->Registros = Registros;
    Rango = std::vector<Registro>();
}

Bitacora::~Bitacora()
{
    // O(n + m) (m = Rango.size())
    Registros.clear();
    Rango.clear();
}

void Bitacora::readInput(std::ifstream &input)
{
    // O(n)
    std::string line;
    while (std::getline(input, line))
    {
        Registros.push_back(Registro(line));
    }
}

void Bitacora::print(std::ostream &os)
{
    // O(n)
    for (int i = 0; i < (int)Registros.size(); i++)
    {
        os << Registros[i] << std::endl;
    }
}

void Bitacora::sort()
{
    // O(n log n)
    // merge sort
    std::vector<Registro> RegistrosSorted;
    if (Registros.size() <= 1)
    {
        return;
    }
    Bitacora left(std::vector<Registro>(Registros.begin(), Registros.begin() + Registros.size() / 2));
    Bitacora right(std::vector<Registro>(Registros.begin() + Registros.size() / 2, Registros.end()));
    left.sort();
    right.sort();
    int i = 0, j = 0;
    while (i < (int)left.Registros.size() || j < (int)right.Registros.size())
    {
        if (i < (int)left.Registros.size() && j < (int)right.Registros.size())
        {
            if (left.Registros[i].getTimeStamp() < right.Registros[j].getTimeStamp())
            {
                RegistrosSorted.push_back(left.Registros[i]);
                i++;
            }
            else
            {
                RegistrosSorted.push_back(right.Registros[j]);
                j++;
            }
        }
        else if (i < (int)left.Registros.size())
        {
            RegistrosSorted.push_back(left.Registros[i]);
            i++;
        }
        else
        {
            RegistrosSorted.push_back(right.Registros[j]);
            j++;
        }
    }
    Registros = RegistrosSorted;
}

int Bitacora::lowerBound(time_t fecha)
{
    // O(log n)
    int i = 0, j = Registros.size() - 1, m;
    while (i < j)
    {
        m = (i + j) / 2;
        if (Registros[m].getTimeStamp() < fecha)
        {
            i = m + 1;
        }
        else
        {
            j = m;
        }
    }
    return i;
}

int Bitacora::upperBound(time_t fecha)
{
    // O(log n)
    int i = 0, j = Registros.size() - 1, m;
    while (i < j)
    {
        m = (i + j) / 2;
        if (Registros[m].getTimeStamp() <= fecha)
        {
            i = m + 1;
        }
        else
        {
            j = m;
        }
    }
    return i;
}

void Bitacora::setFecha(std::string fecha1, int tipo)
{
    // O(1)
    // Jun 01 00:22:36
    std::stringstream ss(fecha1);
    std::string mes, dia, hora;
    ss >> mes >> dia >> hora;
    struct tm tm;
    tm.tm_year = 122;
    std::unordered_map<std::string, int> meses = {
        {"Jan", 0},
        {"Feb", 1},
        {"Mar", 2},
        {"Apr", 3},
        {"May", 4},
        {"Jun", 5},
        {"Jul", 6},
        {"Aug", 7},
        {"Sep", 8},
        {"Oct", 9},
        {"Nov", 10},
        {"Dec", 11}};

    tm.tm_mon = meses[mes];
    tm.tm_mday = std::stoi(dia);
    tm.tm_hour = std::stoi(hora.substr(0, 2));
    tm.tm_min = std::stoi(hora.substr(3, 2));
    tm.tm_sec = std::stoi(hora.substr(6, 2));

    time_t fecha = mktime(&tm);
    if (tipo == 0)
    {
        this->fechaInicial = fecha;
    }
    else
    {
        this->fechaFinal = fecha;
    }
}

void Bitacora::getInputRango()
{
    // O(1)
    std::string fecha1, fecha2;
    std::cout << "Ingrese la fecha inicial (formato: Jun 01 00:22:36): ";
    std::getline(std::cin, fecha1);
    std::cout << "Ingrese la fecha final (formato: Jun 01 00:22:36): ";
    std::getline(std::cin, fecha2);
    setFecha(fecha1, 0);
    setFecha(fecha2, 1);
}

void Bitacora::getRango()
{
    // O(log n)
    getInputRango();
    int i = lowerBound(fechaInicial);
    int j = upperBound(fechaFinal);
    for (int k = i; k < j; k++)
    {
        Rango.push_back(Registros[k]);
    }
    if (Rango[0].getTimeStamp() != fechaInicial)
    {
        std::cout << "No se encontraro la primer fecha en el rango" << std::endl;
    }
    if (Rango[Rango.size() - 1].getTimeStamp() != fechaFinal)
    {
        std::cout << "No se encontraro la ultima fecha en el rango" << std::endl;
    }
}

void Bitacora::printRango(std::ostream &os)
{
    // O(n)
    for (int i = 0; i < (int)Rango.size(); i++)
    {
        os << Rango[i] << std::endl;
    }
}

#endif // _BITACORA_H_
