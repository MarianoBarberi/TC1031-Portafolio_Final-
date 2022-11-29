#ifndef _IP_VALUE_H_
#define _IP_VALUE_H_
#include <iostream>
#include <string>

class Ip_Value
{
private:
    std::string ip;
    int value;

public:
    Ip_Value();
    Ip_Value(std::string ip, int value);
    ~Ip_Value();
    std::string getIp();
    int getValue();
    void setValue(int value);
    bool operator<(const Ip_Value &other) const;
    bool operator>(const Ip_Value &other) const;
    bool operator==(const Ip_Value &other) const;
    bool operator!=(const Ip_Value &other) const;
    friend std::ostream &operator<<(std::ostream &out, const Ip_Value &ip_value);
};

Ip_Value::Ip_Value()
{
    // O(1)
    ip = "";
    value = 0;
}

Ip_Value::Ip_Value(std::string ip, int value)
{
    // O(1)
    this->ip = ip;
    this->value = value;
}

Ip_Value::~Ip_Value()
{
    // O(1)
}

std::string Ip_Value::getIp()
{
    // O(1)
    return ip;
}

int Ip_Value::getValue()
{
    // O(1)
    return value;
}

void Ip_Value::setValue(int value)
{
    // O(1)
    this->value = value;
}

bool Ip_Value::operator<(const Ip_Value &other) const
{
    // O(1)
    return value < other.value;
}

bool Ip_Value::operator>(const Ip_Value &other) const
{
    // O(1)
    return value > other.value;
}

bool Ip_Value::operator==(const Ip_Value &other) const
{
    // O(1)
    return value == other.value;
}

bool Ip_Value::operator!=(const Ip_Value &other) const
{
    // O(1)
    return value != other.value;
}

std::ostream &operator<<(std::ostream &out, const Ip_Value &ip_value)
{
    // O(1)
    out << ip_value.ip << " " << ip_value.value;
    return out;
}

#endif // _IP_VALUE_H_
