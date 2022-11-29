#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "PriorityQueue.h"
#include "Ip_Value.h"

// n: número de nodos
// m: número de aristas
class Graph
{
private:
    int numNodes;
    int numEdges;
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph;
    std::unordered_set<std::string> nodes;
    std::vector<Ip_Value> adjNum;
    std::unordered_map<std::string, int> minCaminos;

    void readNodes(std::istream &in, int n);
    void readEdges(std::istream &in, int m);
    std::string bootMaster;

public:
    Graph();
    ~Graph();
    void readGraph(std::istream &in);
    void printGraph(std::ostream &out);
    void countGraph(std::ostream &out);
    void getTopN(int n, std::ostream &out);
    std::string getBootMaster();
    void getMinCaminos(std::string ipOrigen);
    void printMinCaminos(std::ostream &out);
    void printMaxDistancia(std::ostream &out);
};

Graph::Graph()
{
    // O(1)
    numNodes = 0;
    numEdges = 0;
}

Graph::~Graph()
{
    // O(1)
    graph.clear();
    nodes.clear();
}

void Graph::readNodes(std::istream &in, int n)
{
    // O(n)
    std::string node;
    for (int i = 0; i < n; i++)
    {
        in >> node;
        nodes.insert(node);
    }
}

void Graph::readEdges(std::istream &in, int m)
{
    // O(m)
    std::string mes, dia, hora, origen, destino, peso, type;
    std::string originIp, destIp;

    for (int i = 0; i < m; i++)
    {
        in >> mes >> dia >> hora >> origen >> destino >> peso;
        std::getline(in, type);
        originIp = origen.substr(0, origen.find(":"));
        destIp = destino.substr(0, destino.find(":"));
        graph[originIp].push_back(std::make_pair(destIp, std::stoi(peso)));
    }
}

void Graph::readGraph(std::istream &in)
{
    // O(n + m)
    in >> numNodes >> numEdges;
    readNodes(in, numNodes);
    readEdges(in, numEdges);
}

void Graph::printGraph(std::ostream &out)
{
    // O(n + m)
    for (auto i : nodes)
    {
        out << i << " -> ";
        for (auto j : graph[i])
        {
            out << j.first << " (" << j.second << ") ";
        }
        out << std::endl;
    }
    for (auto it = graph.begin(); it != graph.end(); it++)
    {
        out << it->first << " -> ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            out << it2->first << " (" << it2->second << ") ";
        }
        out << std::endl;
    }
}

void Graph::countGraph(std::ostream &out)
{
    // O(n + m)
    for (auto i : nodes)
    {
        adjNum.push_back(Ip_Value(i, graph[i].size()));
        out << i << " " << graph[i].size() << std::endl;
    }
}

void Graph::getTopN(int n, std::ostream &out)
{
    // O(n log n)
    PriorityQueue<Ip_Value> pq(adjNum);
    bootMaster = pq.top().getIp();
    for (int i = 0; i < n; i++)
    {
        out << pq.top().getIp() << " " << pq.top().getValue() << std::endl;
        pq.pop();
    }
}

std::string Graph::getBootMaster()
{
    // O(1)
    return bootMaster;
}

void Graph::getMinCaminos(std::string ipOrigen)
{
    // O(m log n)
    PriorityQueue<std::pair<int, std::string>> pq(false);
    std::unordered_map<std::string, bool> visitados;
    std::unordered_map<std::string, int> distancias;

    visitados[ipOrigen] = true;
    distancias[ipOrigen] = 0;
    pq.push(std::make_pair(0, ipOrigen));
    // o(m log n)
    while (!pq.empty())
    {
        // o(m)
        for (auto i : graph[pq.top().second])
        {
            // o(m_n)
            if (visitados[i.first] == false)
            {
                // o(1)
                visitados[i.first] = true;
                distancias[i.first] = distancias[pq.top().second] + i.second;
                minCaminos[i.first] = distancias[i.first];
                // o(log n)
                pq.push(std::make_pair(distancias[i.first], i.first));
            }
            else if (distancias[i.first] > distancias[pq.top().second] + i.second)
            {
                // o(1)
                distancias[i.first] = distancias[pq.top().second] + i.second;
                minCaminos[i.first] = distancias[i.first];
                // o(log n)
                pq.push(std::make_pair(distancias[i.first], i.first));
            }
        }
        // o(log n)
        pq.pop();
    }
}

void Graph::printMinCaminos(std::ostream &out)
{
    // O(n)
    for (auto i : minCaminos)
    {
        out << i.first << " " << i.second << std::endl;
    }
}

void Graph::printMaxDistancia(std::ostream &out)
{
    // O(n)
    int max = 0;
    std::string maxIp;
    for (auto i : minCaminos)
    {
        if (i.second > max)
        {
            max = i.second;
            maxIp = i.first;
        }
    }
    out << "La ip mas lejana del bootmaster es " << maxIp << " con una distancia de " << max << std::endl;
}

#endif /* _GRAPH_H_ */