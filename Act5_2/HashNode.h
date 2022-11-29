#ifndef _HASH_NODE_H_
#define _HASH_NODE_H_

#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include "NodeInfo.h"

class HashNode
{
private:
    std::string ip;
    NodeInfo data;
    int status;
    std::vector<int> overflow;

public:
    HashNode();
    HashNode(std::string ip);
    std::string getIp();
    void setIp(std::string ip);
    NodeInfo getData();
    void setData(NodeInfo data);
    void addOut(std::string ip);
    void addIn(std::string ip);
    int getStatus();
    void setStatus(int);
    void clearData();
    void addToOverflow(int hashIndex);
    int getOverflowSize();
    int getOverflowAt(int index);
    void removeFromOverflow(int value);
};

HashNode::HashNode()
{
    // O(1)
    this->ip = "";
    this->status = 0;
}

HashNode::HashNode(std::string ip)
{
    // O(1)
    this->ip = ip;
    this->status = 1;
    this->data = NodeInfo(ip);
}

std::string HashNode::getIp()
{
    // O(1)
    return ip;
}
void HashNode::setIp(std::string ip)
{
    // O(1)
    this->ip = ip;
}

NodeInfo HashNode::getData()
{
    // O(1)
    return data;
}
void HashNode::setData(NodeInfo data)
{
    // O(1)
    this->data = data;
}

void HashNode::addOut(std::string ip)
{
    // O(1)
    data.addOut(ip);
}

void HashNode::addIn(std::string ip)
{
    // O(1)
    data.addIn(ip);
}

int HashNode::getStatus()
{
    // O(1)
    return status;
}

void HashNode::setStatus(int status)
{
    // O(1)
    this->status = status;
}

void HashNode::clearData()
{
    // O(1)
    ip = "";
    data = NodeInfo();
    status = 2;
    overflow.clear();
}

void HashNode::addToOverflow(int hashIndex)
{
    // O(1)
    overflow.push_back(hashIndex);
}

int HashNode::getOverflowSize()
{
    // O(1)
    return overflow.size();
}

int HashNode::getOverflowAt(int index)
{
    // O(1)
    return overflow[index];
}

void HashNode::removeFromOverflow(int value)
{
    // O(n)
    overflow.erase(
        std::remove(
            overflow.begin(), overflow.end(), value),
        overflow.end());
}

#endif // _HASH_NODE_H_