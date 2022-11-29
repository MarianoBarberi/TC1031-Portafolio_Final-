#ifndef _Registro_H_
#define _Registro_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <unordered_map>
#include <cmath>

class Registro
{
private:
    struct tm timeStruct;
    time_t timeStamp;
    std::string mes, dia, hora, minuto, segundo, ip, puerto, falla;
    std::unordered_map<std::string, int> meses = {{"Jan", 0}, {"Feb", 1}, {"Mar", 2}, {"Apr", 3}, {"May", 4}, {"Jun", 5}, {"Jul", 6}, {"Aug", 7}, {"Sep", 8}, {"Oct", 9}, {"Nov", 10}, {"Dec", 11}};
    int IPtoInt(std::string ip) const;

public:
    Registro();
    Registro(std::string mes, std::string dia, std::string hora, std::string minuto, std::string segundo, std::string ip, std::string puerto, std::string falla);
    bool operator<(const Registro &r) const;
    bool operator>(const Registro &r) const;
    bool operator==(const Registro &r) const;
    bool operator!=(const Registro &r) const;
    bool operator<=(const Registro &r) const;
    bool operator>=(const Registro &r) const;
    time_t getTimeStamp();
    void print();
    std::string toString();
    friend std::ostream &operator<<(std::ostream &os, const Registro &r);
    std::string getIP();
};

Registro::Registro()
{
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

int Registro::IPtoInt(std::string ip) const
{
    // O(1)
    std::vector<std::string> octetos;
    std::string octeto = "";
    for (long long unsigned int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == '.')
        {
            octetos.push_back(octeto);
            octeto = "";
        }
        else
        {
            octeto += ip[i];
        }
    }
    octetos.push_back(octeto);
    int ipInt = 0;
    for (long long unsigned int i = 0; i < octetos.size(); i++)
    {
        ipInt += stoi(octetos[i]) * pow(256, 3 - i);
    }
    return ipInt;

}

bool Registro::operator==(const Registro &otro) const
{
    // O(1)
    std::string ip1 = this->ip;
    std::string ip2 = otro.ip;
    return ip1 == ip2;
}
bool Registro::operator!=(const Registro &otro) const
{
    // O(1)
    return !(*this == otro);
}
bool Registro::operator<(const Registro &otro) const
{
    // O(1)
    std::string ip1 = this->ip;
    std::string ip2 = otro.ip;
    return IPtoInt(ip1) < IPtoInt(ip2);
}

bool Registro::operator>(const Registro &otro) const
{
    // O(1)
    std::string ip1 = this->ip;
    std::string ip2 = otro.ip;
    return IPtoInt(ip1) > IPtoInt(ip2);
}

bool Registro::operator<=(const Registro &otro) const
{
    // O(1)
    return !(*this > otro);
}

bool Registro::operator>=(const Registro &otro) const
{
    // O(1)
    return !(*this < otro);
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

std::string Registro::getIP()
{
    // O(1)
    return this->ip;
}
#endif