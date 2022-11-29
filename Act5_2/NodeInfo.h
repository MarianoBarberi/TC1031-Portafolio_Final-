#ifndef _NODE_INFO_H_
#define _NODE_INFO_H_

#include <iostream>
#include <string>
#include "PriorityQueue.h"

class NodeInfo
{
private:
    std::string ip;
    PriorityQueue<std::string> out;
    int outCount;
    PriorityQueue<std::string> in;
    int inCount;

public:
    NodeInfo();
    NodeInfo(std::string ip);
    std::string getIp();
    void setIp(std::string ip);
    std::vector<std::string> getOut();
    void setOut(std::vector<std::string> out);
    void addOut(std::string ip);
    int getOutSize();
    std::vector<std::string> getIn();
    void addIn(std::string ip);
    int getInSize();
    friend std::ostream &operator<<(std::ostream &out, const NodeInfo &nodeInfo);
};

NodeInfo::NodeInfo()
{
    // O(1)
    this->ip = "";
    this->outCount = 0;
    this->inCount = 0;
}

NodeInfo::NodeInfo(std::string ip)
{
    // O(1)
    this->ip = ip;
}

std::string NodeInfo::getIp()
{
    // O(1)
    return ip;
}

void NodeInfo::setIp(std::string ip)
{
    // O(1)
    this->ip = ip;
}

std::vector<std::string> NodeInfo::getOut()
{
    // O(nlogn)
    PriorityQueue<std::string> temp = out;
    std::vector<std::string> outVector;
    while (!temp.empty())
    {
        outVector.push_back(temp.top());
        temp.pop();
    }
    return outVector;
}

void NodeInfo::setOut(std::vector<std::string> out)
{
    // O(nlogn)
    for (auto ip : out)
    {
        this->out.push(ip);
    }
}

void NodeInfo::addOut(std::string ip)
{
    // O(logn)
    out.push(ip);
    outCount++;
}

int NodeInfo::getOutSize()
{
    // O(1)
    return outCount;
}

std::vector<std::string> NodeInfo::getIn()
{
    // O(nlogn)
    PriorityQueue<std::string> temp = in;
    std::vector<std::string> inVector;
    while (!temp.empty())
    {
        inVector.push_back(temp.top());
        temp.pop();
    }
    return inVector;
}

void NodeInfo::addIn(std::string ip)
{
    // O(logn)
    in.push(ip);
    inCount++;
}

int NodeInfo::getInSize()
{
    // O(1)
    return inCount;
}

std::ostream &operator<<(std::ostream &out, const NodeInfo &nodeInfo)
{
    // O(nlogn)
    out << "IP: " << nodeInfo.ip << std::endl;
    out << "Out: " << std::endl;
    PriorityQueue<std::string> temp = nodeInfo.out;
    while (!temp.empty())
    {
        out << temp.top() << std::endl;
        temp.pop();
    }
    out << "In: " << std::endl;
    temp = nodeInfo.in;
    while (!temp.empty())
    {
        out << temp.top() << std::endl;
        temp.pop();
    }
    return out;
}

#endif // _NODE_INFO_H_