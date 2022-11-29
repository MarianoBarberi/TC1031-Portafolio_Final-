#ifndef _DOUBLYLINKEDLIST_H
#define _DOUBLYLINKEDLIST_H

#include <iostream>
#include <string>
#include <vector>
#include "ListNode.h"

template <typename T>
class DoublyLinkedList
{
private:
    ListNode<T> *head;
    ListNode<T> *tail;
    int size;
    void split(DoublyLinkedList<T> &list1, DoublyLinkedList<T> &list2);
    DoublyLinkedList<T> merge(DoublyLinkedList<T> &list1, DoublyLinkedList<T> &list2);
    ListNode<T> *getMiddleNode(ListNode<T> *start, ListNode<T> *end);
    ListNode<T> *BS(ListNode<T> *start, ListNode<T> *end, T value);

public:
    DoublyLinkedList();
    DoublyLinkedList(std::vector<T> &v);
    ~DoublyLinkedList();
    void addFirst(T value);
    void addLast(T value);
    bool deleteData(T value);
    bool deleteAt(int index);
    T getData(int index);
    void updateData(T pastVal, T newVal);
    void updateAt(int index, T newVal);
    int findData(T val);
    int getSize();
    void setSize(int size);
    void print();
    void print(std::ostream &out);
    // void operator=(DoublyLinkedList<T> &list);
    void operator=(std::vector<T> &list);
    void operator=(DoublyLinkedList<T> &list);
    void clear();
    void mergeSort();
    void duplicate();
    void removeDuplicates();
    void reverse();
    void setHead(ListNode<T> *head);
    void setTail(ListNode<T> *tail);
    DoublyLinkedList<T> getReversedSublist(int start, int end);
    DoublyLinkedList<T> getRange(T start, T end);
    ListNode<T> *getHead();
    ListNode<T> *getTail();
    void removeFirst();
    void removeLast();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    // O(1)
    head = NULL;
    tail = NULL;
    size = 0;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(std::vector<T> &v)
{
    // O(n)
    head = NULL;
    tail = NULL;
    size = 0;
    for (long long unsigned int i = 0; i < v.size(); i++)
    {
        addLast(v[i]);
    }
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    // O(n)
    ListNode<T> *temp = head;
    while (temp != NULL)
    {
        head++;
        delete temp;
        temp = head;
    }
}

template <typename T>
void DoublyLinkedList<T>::addFirst(T value)
{
    // O(1)
    ListNode<T> *node = new ListNode<T>(value);
    if (head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::addLast(T value)
{
    // O(1)
    ListNode<T> *node = new ListNode<T>(value);
    if (head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->setNext(node);
        node->setPrev(tail);
        tail = node;
    }
    size++;
}

template <typename T>
bool DoublyLinkedList<T>::deleteData(T value)
{
    // O(n)
    ListNode<T> *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            if (temp == head)
            {
                head = head->next;
                if (head != NULL)
                {
                    head->prev = NULL;
                }
                else
                {
                    tail = NULL;
                }
            }
            else if (temp == tail)
            {
                tail = tail->prev;
                tail->next = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
            size--;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
bool DoublyLinkedList<T>::deleteAt(int index)
{
    // O(n)
    if (index < 0 || index >= size)
    {
        return false;
    }
    else
    {
        ListNode<T> *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->getNext();
        }
        if (temp == head)
        {
            head = head->getNext();
            if (head != NULL)
            {
                head->setPrev(NULL);
            }
            else
            {
                tail = NULL;
            }
        }
        else if (temp == tail)
        {
            tail = tail->getPrev();
            tail->setNext(NULL);
        }
        else
        {
            temp->getPrev()->setNext(temp->getNext());
            temp->getNext()->setPrev(temp->getPrev());
        }
        delete temp;
        size--;
        return true;
    }
}

template <typename T>
T DoublyLinkedList<T>::getData(int index)
{
    // O(n)
    if (index < 0 || index >= size)
    {
        return -1;
    }
    else
    {
        ListNode<T> *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
}

template <typename T>
void DoublyLinkedList<T>::updateData(T pastVal, T newVal)
{
    // O(n)
    ListNode<T> *temp = head;
    while (temp != NULL)
    {
        if (temp->data == pastVal)
        {
            temp->data = newVal;
        }
        temp = temp->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::updateAt(int index, T newVal)
{
    // O(n)
    if (index < 0 || index >= size)
    {
        return;
    }
    else
    {
        ListNode<T> *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->data = newVal;
    }
}

template <typename T>
int DoublyLinkedList<T>::findData(T val)
{
    // O(n)
    ListNode<T> *temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

template <typename T>
int DoublyLinkedList<T>::getSize()
{
    // O(1)
    return size;
}

template <typename T>
void DoublyLinkedList<T>::setSize(int size)
{
    // O(1)
    this->size = size;
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
    // O(n)
    ListNode<T> *temp = head;
    while (temp != NULL)
    {
        head = head->getNext();
        delete temp;
        temp = head;
    }
    size = 0;
}

template <typename T>
ListNode<T> *DoublyLinkedList<T>::getHead()
{
    // O(1)
    return head;
}

template <typename T>
ListNode<T> *DoublyLinkedList<T>::getTail()
{
    // O(1)
    return tail;
}

template <typename T>
void DoublyLinkedList<T>::print()
{
    // O(n)
    ListNode<T> *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->getData() << std::endl;
        temp = temp->getNext();
    }
    std::cout << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::print(std::ostream &out)
{
    // O(n)
    ListNode<T> *temp = head;
    while (temp != NULL)
    {
        out << temp->getData() << " " << std::endl;
        temp = temp->getNext();
    }
}

template <typename T>
void DoublyLinkedList<T>::operator=(std::vector<T> &vec)
{
    // O(n)
    clear();
    for (int i = 0; i < vec.size(); i++)
    {
        this->addLast(vec[i]);
    }
}

template <typename T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> &list)
{
    // O(n)
    clear();
    ListNode<T> *temp = list.getHead();
    while (temp != NULL)
    {
        addLast(temp->getData());
        temp = temp->getNext();
    }
    delete temp;
    return;
}

template <typename T>
void DoublyLinkedList<T>::split(DoublyLinkedList<T> &list1, DoublyLinkedList<T> &list2)
{
    // O(n)
    ListNode<T> *slow = head;
    ListNode<T> *fast = head;
    list1.clear();
    list2.clear();
    while (fast != NULL)
    {
        list1.addLast(slow->getData());
        slow = slow->getNext();
        fast = fast->getNext();
        if (fast != NULL)
        {
            fast = fast->getNext();
        }
    }
    while (slow != NULL)
    {
        list2.addLast(slow->getData());
        slow = slow->getNext();
    }
}

template <typename T>
DoublyLinkedList<T> DoublyLinkedList<T>::merge(DoublyLinkedList<T> &list1, DoublyLinkedList<T> &list2)
{
    // O(n)
    DoublyLinkedList<T> list;
    ListNode<T> *temp1 = list1.getHead();
    ListNode<T> *temp2 = list2.getHead();
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->getData() < temp2->getData())
        {
            list.addLast(temp1->getData());
            temp1 = temp1->getNext();
        }
        else
        {
            list.addLast(temp2->getData());
            temp2 = temp2->getNext();
        }
    }
    while (temp1 != NULL)
    {
        list.addLast(temp1->getData());
        temp1 = temp1->getNext();
    }
    while (temp2 != NULL)
    {
        list.addLast(temp2->getData());
        temp2 = temp2->getNext();
    }
    return list;
}

template <typename T>
void DoublyLinkedList<T>::mergeSort()
{
    // O(n log n)
    // Merge Sort
    if (size == 1)
    {
        return;
    }
    DoublyLinkedList<T> list1, list2;
    split(list1, list2);
    list1.mergeSort();
    list2.mergeSort();
    DoublyLinkedList<T> list = merge(list1, list2);
    *this = list;
    list1.clear();
    list2.clear();
    list.clear();
    return;
}

template <typename T>
void DoublyLinkedList<T>::duplicate()
{
    // O(n)
    ListNode<T> *temp = head;
    while (temp != NULL)
    {
        ListNode<T> *newNode = new ListNode<T>(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        if (newNode->next != NULL)
        {
            newNode->next->prev = newNode;
        }
        temp = newNode->next;
        size++;
    }
}

template <typename T>
void DoublyLinkedList<T>::removeDuplicates()
{
    // O(n)
    ListNode<T> *temp = head;
    while (temp != NULL)
    {
        ListNode<T> *temp2 = temp->next;
        while (temp2 != NULL)
        {
            if (temp->data == temp2->data)
            {
                temp2->prev->next = temp2->next;
                if (temp2->next != NULL)
                {
                    temp2->next->prev = temp2->prev;
                }
                ListNode<T> *temp3 = temp2;
                temp2 = temp2->next;
                delete temp3;
                size--;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::reverse()
{
    // O(n)
    ListNode<T> *temp = head;
    while (temp != NULL)
    {
        ListNode<T> *temp2 = temp->next;
        temp->next = temp->prev;
        temp->prev = temp2;
        temp = temp2;
    }
    temp = head;
    head = tail;
    tail = temp;
}

template <typename T>
void DoublyLinkedList<T>::setHead(ListNode<T> *head)
{
    // O(1)
    this->head = head;
}

template <typename T>
void DoublyLinkedList<T>::setTail(ListNode<T> *tail)
{
    // O(1)
    this->tail = tail;
}

template <typename T>
DoublyLinkedList<T> DoublyLinkedList<T>::getReversedSublist(int start, int end)
{
    // O(n)
    DoublyLinkedList<T> list;
    ListNode<T> *temp = head;
    for (int i = 0; i < start; i++)
    {
        temp = temp->next;
    }
    for (int i = start; i <= end; i++)
    {
        list.insertFront(temp->data);
        temp = temp->next;
    }
    return list;
}

template <typename T>
ListNode<T> *DoublyLinkedList<T>::getMiddleNode(ListNode<T> *start, ListNode<T> *end)
{
    // O(n)
    ListNode<T> *slow = start;
    ListNode<T> *fast = start->getNext();
    while (fast != end)
    {
        fast = fast->getNext();
        if (fast != end)
        {
            slow = slow->getNext();
            fast = fast->getNext();
        }
    }
    return slow;
}

template <typename T>
ListNode<T> *DoublyLinkedList<T>::BS(ListNode<T> *start, ListNode<T> *end, T value)
{
    // O(n)
    if (start->getNext() == end || start == end)
    {
        return start;
    }
    ListNode<T> *mid = getMiddleNode(start, end);
    if (mid->getData() == value)
    {
        return mid;
    }
    else if (mid->getData() > value)
    {
        return BS(start, mid->getPrev(), value);
    }
    else
    {
        return BS(mid->getNext(), end, value);
    }
}

template <typename T>
DoublyLinkedList<T> DoublyLinkedList<T>::getRange(T start, T end)
{
    // O(n)
    ListNode<T> *startNode = BS(head, tail, start);
    ListNode<T> *endNode = BS(head, tail, end);
    DoublyLinkedList<T> list;
    ListNode<T> *temp = startNode;
    while (temp != endNode->getNext())
    {
        list.addLast(temp->getData());
        temp = temp->getNext();
    }
    return list;
}

template <typename T>
void DoublyLinkedList<T>::removeFirst()
{
    // O(1)
    if (head == NULL)
    {
        return;
    }
    ListNode<T> *temp = head;
    head = head->getNext();
    if (head != NULL)
    {
        head->setPrev(NULL);
    }
    delete temp;
    size--;
}

template <typename T>
void DoublyLinkedList<T>::removeLast()
{
    // O(1)
    if (tail == NULL)
    {
        return;
    }
    ListNode<T> *temp = tail;
    tail = tail->getPrev();
    if (tail != NULL)
    {
        tail->setNext(NULL);
    }
    delete temp;
    size--;
}

#endif // _DoublyLinkedList_H_