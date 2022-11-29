#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>

template <typename T>
class Node
{
private:
    T data;
    Node<T> *left;
    Node<T> *right;

public:
    Node();
    Node(T data);
    Node(T data, Node<T> *left, Node<T> *right);
    T getData();
    void setData(T data);
    Node<T> *getLeft();
    void clearLeft();
    void setLeft(Node<T> *left);
    Node<T> *getRight();
    void clearRight();
    void setRight(Node<T> *right);
    void operator=(Node<T> *node);
    void operator=(T data);
    bool operator==(Node<T> *node);
    bool operator==(T data);
    bool operator!=(Node<T> *node);
    bool operator!=(T data);
    bool operator<(Node<T> *node);
    bool operator<(T data);
    bool operator>(Node<T> *node);
    bool operator>(T data);
    bool operator<=(Node<T> *node);
    bool operator<=(T data);
    bool operator>=(Node<T> *node);
    bool operator>=(T data);
};

template <typename T>
Node<T>::Node()
{
    // O(1)
    this->data = T();
    this->left = NULL;
    this->right = NULL;
}

template <typename T>
Node<T>::Node(T data)
{
    // O(1)
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

template <typename T>
Node<T>::Node(T data, Node<T> *left, Node<T> *right)
{
    // O(1)
    this->data = data;
    this->left = left;
    this->right = right;
}

template <typename T>
T Node<T>::getData()
{
    // O(1)
    return this->data;
}

template <typename T>
void Node<T>::setData(T data)
{
    // O(1)
    this->data = data;
}

template <typename T>
Node<T> *Node<T>::getLeft()
{
    // O(1)
    return this->left;
}

template <typename T>
void Node<T>::clearLeft()
{
    // O(1)
    this->left = NULL;
}

template <typename T>
void Node<T>::setLeft(Node<T> *left)
{
    // O(1)
    this->left = left;
}

template <typename T>
Node<T> *Node<T>::getRight()
{
    // O(1)
    return this->right;
}

template <typename T>
void Node<T>::clearRight()
{
    // O(1)
    this->right = NULL;
}

template <typename T>
void Node<T>::setRight(Node<T> *right)
{
    // O(1)
    this->right = right;
}

template <typename T>
void Node<T>::operator=(Node<T> *node)
{
    // O(1)
    this->data = node->getData();
    this->left = node->getLeft();
    this->right = node->getRight();
}

template <typename T>
void Node<T>::operator=(T data)
{
    // O(1)
    this->data = data;
}

template <typename T>
bool Node<T>::operator==(Node<T> *node)
{
    // O(1)
    return this->data == node->getData();
}

template <typename T>
bool Node<T>::operator==(T data)
{
    // O(1)
    return this->data == data;
}

template <typename T>
bool Node<T>::operator!=(Node<T> *node)
{
    // O(1)
    return this->data != node->getData();
}

template <typename T>
bool Node<T>::operator!=(T data)
{
    // O(1)
    return this->data != data;
}

template <typename T>
bool Node<T>::operator<(Node<T> *node)
{
    // O(1)
    return this->data < node->getData();
}

template <typename T>
bool Node<T>::operator<(T data)
{
    // O(1)
    return this->data < data;
}

template <typename T>
bool Node<T>::operator>(Node<T> *node)
{
    // O(1)
    return this->data > node->getData();
}

template <typename T>
bool Node<T>::operator>(T data)
{
    // O(1)
    return this->data > data;
}

template <typename T>
bool Node<T>::operator<=(Node<T> *node)
{
    // O(1)
    return this->data <= node->getData();
}

template <typename T>
bool Node<T>::operator<=(T data)
{
    // O(1)
    return this->data <= data;
}

template <typename T>
bool Node<T>::operator>=(Node<T> *node)
{
    // O(1)
    return this->data >= node->getData();
}

template <typename T>
bool Node<T>::operator>=(T data)
{
    // O(1)
    return this->data >= data;
}

#endif // NODE_H
