
#include "Node.h"

template <class Data>
Node<Data>::Node(Node *t_nextNode, Data t_x)
{
    this->x = t_x;
    this->nextNode = t_nextNode;
}

template <class Data>
void Node<Data>::setx(Data t_x)
{
    this->x = t_x;
}

template <class Data>
void Node<Data>::setptr(Node *t_nextNode)
{
    this->nextNode = t_nextNode;
}

template <class Data>
Data Node<Data>::getx()
{
    return this->x;
}

template <class Data>
Node* Node<Data>::getptr()
{
    return this->nextNode;
}

template <class Data>
Node<Data>::~Node()
{}
