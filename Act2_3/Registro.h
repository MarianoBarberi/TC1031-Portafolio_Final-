#ifndef _Registro_H_
#define _Registro_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <unordered_map>
#include <sstream>

class Registro
{
private:
    struct tm timeStruct;
    time_t timeStamp;
    std::string mes, dia, hora, minuto, segundo, ip, puerto, falla;
    std::unordered_map<std::string, int> meses = {{"Jan", 0}, {"Feb", 1}, {"Mar", 2}, {"Apr", 3}, {"May", 4}, {"Jun", 5}, {"Jul", 6}, {"Aug", 7}, {"Sep", 8}, {"Oct", 9}, {"Nov", 10}, {"Dec", 11}};

public:
    Registro();
    Registro(std::string mes, std::string dia, std::string hora, std::string minuto, std::string segundo, std::string ip, std::string puerto, std::string falla);
    Registro(std::string fecha);
    bool operator<(const Registro &r) const;
    bool operator<(const time_t &r) const;
    bool operator>(const Registro &r) const;
    bool operator>(const time_t &r) const;
    bool operator==(const Registro &r) const;
    bool operator==(const time_t &otro) const;
    bool operator!=(const Registro &r) const;
    bool operator!=(const time_t &r) const;
    bool operator<=(const Registro &r) const;
    bool operator<=(const time_t &r) const;
    bool operator>=(const Registro &r) const;
    bool operator>=(const time_t &r) const;
    time_t getTimeStamp();
    void print();
    std::string toString();
    friend std::ostream &operator<<(std::ostream &os, const Registro &r);
};

Registro::Registro()
{
    // O(1)
    this->mes = "0";
    this->dia = "0";
    this->hora = "0";
    this->minuto = "0";
    this->segundo = "0";
    this->ip = "0";
    this->puerto = "0";
    this->falla = "0";
    this->timeStamp = 0;
}

Registro::Registro(std::string mes, std::string dia, std::string hora, std::string minuto, std::string segundo, std::string ip, std::string puerto, std::string falla)
{
    // O(1)
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
    this->ip = ip;
    this->puerto = puerto;
    this->falla = falla;
    this->timeStruct.tm_mon = meses[mes];
    this->timeStruct.tm_mday = stoi(dia);
    this->timeStruct.tm_hour = stoi(hora);
    this->timeStruct.tm_min = stoi(minuto);
    this->timeStruct.tm_sec = stoi(segundo);
    this->timeStruct.tm_year = 122;
    this->timeStamp = mktime(&timeStruct);
}

Registro::Registro(std::string fecha)
{
    // O(1)
    // Jun 01 00:22:36
    std::stringstream ss(fecha);
    ss >> this->mes >> this->dia >> this->hora;
    this->minuto = this->hora.substr(3, 2);
    this->segundo = this->hora.substr(6, 2);
    this->hora = this->hora.substr(0, 2);
    this->timeStruct.tm_mon = meses[this->mes];
    this->timeStruct.tm_mday = stoi(this->dia);
    this->timeStruct.tm_hour = stoi(this->hora);
    this->timeStruct.tm_min = stoi(this->minuto);
    this->timeStruct.tm_sec = stoi(this->segundo);
    this->timeStruct.tm_year = 122;
    this->timeStamp = mktime(&timeStruct);
    this->ip = "0";
    this->puerto = "0";
    this->falla = "0";
}

bool Registro::operator==(const Registro &otro) const
{
    // O(1)
    return this->timeStamp == otro.timeStamp;
}
bool Registro::operator==(const time_t &otro) const
{
    // O(1)
    return this->timeStamp == otro;
}
bool Registro::operator!=(const Registro &otro) const
{
    // O(1)
    return this->timeStamp != otro.timeStamp;
}
bool Registro::operator!=(const time_t &otro) const
{
    // O(1)
    return this->timeStamp != otro;
}
bool Registro::operator<(const Registro &otro) const
{
    // O(1)
    return this->timeStamp < otro.timeStamp;
}
bool Registro::operator<(const time_t &otro) const
{
    // O(1)
    return this->timeStamp < otro;
}
bool Registro::operator>(const Registro &otro) const
{
    // O(1)
    return this->timeStamp > otro.timeStamp;
}
bool Registro::operator>(const time_t &otro) const
{
    // O(1)
    return this->timeStamp > otro;
}
bool Registro::operator<=(const Registro &otro) const
{
    // O(1)
    return this->timeStamp <= otro.timeStamp;
}
bool Registro::operator<=(const time_t &otro) const
{
    // O(1)
    return this->timeStamp <= otro;
}
bool Registro::operator>=(const Registro &otro) const
{
    // O(1)
    return this->timeStamp >= otro.timeStamp;
}
bool Registro::operator>=(const time_t &otro) const
{
    // O(1)
    return this->timeStamp >= otro;
}
time_t Registro::getTimeStamp()
{
    // O(1)
    return this->timeStamp;
}
void Registro::print()
{
    // O(1)
    std::cout << this->mes << " " << this->dia << " " << this->hora << ":" << this->minuto << ":" << this->segundo << " " << this->ip << ":" << this->puerto << " " << this->falla << std::endl;
}
std::string Registro::toString()
{
    // O(1)
    return this->mes + " " + this->dia + " " + this->hora + ":" + this->minuto + ":" + this->segundo + " " + this->ip + ":" + this->puerto + " " + this->falla;
}
std::ostream &operator<<(std::ostream &os, const Registro &r)
{
    // O(1)
    os << r.mes << " " << r.dia << " " << r.hora << ":" << r.minuto << ":" << r.segundo << " " << r.ip << ":" << r.puerto << " " << r.falla;
    return os;
}

#endif // _Registro_H_