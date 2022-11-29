#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#include <iostream>

template <typename T>
class ListNode
{
private:
    T data;
    ListNode<T> *next;
    ListNode<T> *prev;

public:
    ListNode();
    ListNode(T data);
    ListNode(T data, ListNode<T> *next, ListNode<T> *prev);
    T getData();
    void setData(T data);
    ListNode<T> *getNext();
    void clearNext();
    void setNext(ListNode<T> *next);
    ListNode<T> *getPrev();
    void clearPrev();
    void setPrev(ListNode<T> *prev);
    void operator=(ListNode<T> *node);
    void operator=(T data);
    bool operator==(ListNode<T> *node);
    bool operator==(T data);
    bool operator!=(ListNode<T> *node);
    bool operator!=(T data);
    bool operator<(ListNode<T> *node);
    bool operator<(T data);
    bool operator>(ListNode<T> *node);
    bool operator>(T data);
    bool operator<=(ListNode<T> *node);
    bool operator<=(T data);
    bool operator>=(ListNode<T> *node);
    bool operator>=(T data);
    void operator++();
    void operator--();
};

template <typename T>
ListNode<T>::ListNode()
{
    // O(1)
    this->data = T();
    this->next = NULL;
    this->prev = NULL;
}

template <typename T>
ListNode<T>::ListNode(T data)
{
    // O(1)
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

template <typename T>
ListNode<T>::ListNode(T data, ListNode<T> *next, ListNode<T> *prev)
{
    // O(1)
    this->data = data;
    this->next = next;
    this->prev = prev;
}

template <typename T>
T ListNode<T>::getData()
{
    // O(1)
    return data;
}

template <typename T>
void ListNode<T>::setData(T data)
{
    // O(1)
    this->data = data;
}

template <typename T>
ListNode<T> *ListNode<T>::getNext()
{
    // O(1)
    return next;
}

template <typename T>
void ListNode<T>::setNext(ListNode<T> *next)
{
    // O(1)
    this->next = next;
}

template <typename T>
void ListNode<T>::clearNext()
{
    // O(1)
    this->next = NULL;
}

template <typename T>
ListNode<T> *ListNode<T>::getPrev()
{
    // O(1)
    return prev;
}

template <typename T>
void ListNode<T>::setPrev(ListNode<T> *prev)
{
    // O(1)
    this->prev = prev;
}

template <typename T>
void ListNode<T>::clearPrev()
{
    // O(1)
    this->prev = NULL;
}

template <typename T>
void ListNode<T>::operator=(ListNode<T> *node)
{
    // O(1)
    this->data = node->data;
    this->next = node->next;
    this->prev = node->prev;
}

template <typename T>
void ListNode<T>::operator=(T data)
{
    // O(1)
    this->data = data;
}

template <typename T>
bool ListNode<T>::operator==(ListNode<T> *node)
{
    // O(1)
    return this->data == node->data;
}

template <typename T>
bool ListNode<T>::operator==(T data)
{
    // O(1)
    return this->data == data;
}

template <typename T>
bool ListNode<T>::operator!=(ListNode<T> *node)
{
    // O(1)
    return this->data != node->data;
}

template <typename T>
bool ListNode<T>::operator!=(T data)
{
    // O(1)
    return this->data != data;
}

template <typename T>
bool ListNode<T>::operator<(ListNode<T> *node)
{
    // O(1)
    return this->data < node->data;
}

template <typename T>
bool ListNode<T>::operator<(T data)
{
    // O(1)
    return this->data < data;
}

template <typename T>
bool ListNode<T>::operator>(ListNode<T> *node)
{
    // O(1)
    return this->data > node->data;
}

template <typename T>
bool ListNode<T>::operator>(T data)
{
    // O(1)
    return this->data > data;
}

template <typename T>
bool ListNode<T>::operator<=(ListNode<T> *node)
{
    // O(1)
    return this->data <= node->data;
}

template <typename T>
bool ListNode<T>::operator<=(T data)
{
    // O(1)
    return this->data <= data;
}

template <typename T>
bool ListNode<T>::operator>=(ListNode<T> *node)
{
    // O(1)
    return this->data >= node->data;
}

template <typename T>
bool ListNode<T>::operator>=(T data)
{
    // O(1)
    return this->data >= data;
}

template <typename T>
void ListNode<T>::operator++()
{
    // O(1)
    this = this->next;
}

template <typename T>
void ListNode<T>::operator--()
{
    // O(1)
    this = this->prev;
}

#endif // _LISTNODE_H_
