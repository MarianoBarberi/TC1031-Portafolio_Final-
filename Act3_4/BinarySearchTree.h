#ifndef _BIN_SEARCH_TREE_H
#define _BIN_SEARCH_TREE_H

#include <iostream>
#include <queue>
#include <unordered_map>
#include "Node.h"
#include "Registro_Count.h"
#include "Registro.h"

class BinarySearchTree
{
private:
    int size;
    Node<Registro_Count> *root;
    void clear_helper(Node<Registro_Count> *node);
    void insert_helper(Node<Registro_Count> *node, Registro_Count data);
    void remove_helper(Node<Registro_Count> *node, Registro_Count data);
    void delete_node(Node<Registro_Count> *node);
    void print_helper(Node<Registro_Count> *node);
    bool find_helper(Node<Registro_Count> *node, Registro_Count data);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void clear();
    void insert(Registro_Count val);
    void deleteNode(Registro_Count val);
    void print();
    bool find(Registro_Count val);
    int getSize();
    Registro_Count popBiggest();
};

BinarySearchTree::BinarySearchTree()
{
    // O(1)
    size = 0;
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    // O(1)
    clear();
}

void BinarySearchTree::clear()
{
    // O(n)
    clear_helper(root);
}

void BinarySearchTree::clear_helper(Node<Registro_Count> *node)
{
    // O(n)
    if (node == nullptr)
    {
        return;
    }
    clear_helper(node->getLeft());
    clear_helper(node->getRight());
    delete node;
}

void BinarySearchTree::insert(Registro_Count val)
{
    // O(log n)
    if (root == nullptr)
    {
        root = new Node<Registro_Count>(val);
        size++;
        return;
    }
    insert_helper(root, val);
}

void BinarySearchTree::insert_helper(Node<Registro_Count> *node, Registro_Count data)
{
    // O(log n)
    if (node == nullptr)
    {
        node = new Node<Registro_Count>(data);
        size++;
        return;
    }
    if (data < node->getData())
    {
        if (node->getLeft() == nullptr)
        {
            node->setLeft(new Node<Registro_Count>(data));
            size++;
            return;
        }
        else
        {
            insert_helper(node->getLeft(), data);
        }
    }
    else
    {
        if (node->getRight() == nullptr)
        {
            node->setRight(new Node<Registro_Count>(data));
            size++;
            return;
        }
        else
        {
            insert_helper(node->getRight(), data);
        }
    }
}

void BinarySearchTree::deleteNode(Registro_Count val)
{
    // O(log n)
    remove_helper(root, val);
}

void BinarySearchTree::remove_helper(Node<Registro_Count> *node, Registro_Count data)
{
    // O(log n)
    if (node == nullptr)
    {
        return;
    }
    if (data < node->getData())
    {
        remove_helper(node->getLeft(), data);
    }
    else if (data > node->getData())
    {
        remove_helper(node->getRight(), data);
    }
    else
    {
        if (node->getData().getRegistro() == data.getRegistro())
        {
            delete_node(node);
            return;
        }
        else
        {
            remove_helper(node->getRight(), data);
            remove_helper(node->getLeft(), data);
            return;
        }
    }
    std::cout << "Elemento eliminado" << std::endl;
}

void BinarySearchTree::delete_node(Node<Registro_Count> *node)
{
    // O(log n)
    // node is the node to be deleted
    if (node->getLeft() == nullptr && node->getRight() == nullptr)
    {
        // node is a leaf
        delete node;
        node = nullptr;
    }
    else if (node->getLeft() == nullptr)
    {
        // node has no left child
        Node<Registro_Count> *temp = node;
        node = node->getRight();
        delete temp;
    }
    else if (node->getRight() == nullptr)
    {
        Node<Registro_Count> *temp = node;
        node = node->getLeft();
        delete temp;
    }
    else
    {
        // let left child be the inorder predecessor
        Node<Registro_Count> *temp = node->getLeft();
        while (temp->getRight() != nullptr)
        {
            temp = temp->getRight();
        }
        node->setData(temp->getData());
        delete_node(temp);
    }
}

void BinarySearchTree::print()
{
    // O(n)
    print_helper(root);
}

void BinarySearchTree::print_helper(Node<Registro_Count> *node)
{
    // O(n)
    if (node == nullptr)
    {
        return;
    }
    print_helper(node->getLeft());
    std::cout << node->getData() << std::endl;
    print_helper(node->getRight());
}

bool BinarySearchTree::find(Registro_Count val)
{
    // O(log n)
    return find_helper(root, val);
}

bool BinarySearchTree::find_helper(Node<Registro_Count> *node, Registro_Count data)
{
    // O(log n)
    if (node == nullptr)
    {
        return false;
    }
    if (data < node->getData())
    {
        return find_helper(node->getLeft(), data);
    }
    else if (data > node->getData())
    {
        return find_helper(node->getRight(), data);
    }
    else
    {
        return true;
    }
}

int BinarySearchTree::getSize()
{
    // O(1)
    return size;
}

Registro_Count BinarySearchTree::popBiggest()
{
    // O(log n)
    Node<Registro_Count> *temp = root;
    Node<Registro_Count> *parent = nullptr;
    while (temp->getRight() != nullptr)
    {
        parent = temp;
        temp = temp->getRight();
    }
    Registro_Count data = temp->getData();
    if (parent == nullptr)
    {
        root = temp->getLeft();
    }
    else
    {
        parent->setRight(temp->getLeft());
    }
    delete temp;
    size--;
    return data;
}

#endif // _BIN_SEARCH_TREE_H