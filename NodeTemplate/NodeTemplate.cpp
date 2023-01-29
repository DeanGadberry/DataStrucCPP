
#include "NodeTemplate.h"

// this is still not working for some reason
template <typename Data>
NodeTemplate<Data>::NodeTemplate(NodeTemplate<Data> *t_nextNode, Data t_x)
{
    this->x = t_x;
    this->nextNode = t_nextNode;
}

template <typename Data>
void NodeTemplate<Data>::setx(Data t_x)
{
    this->x = t_x;
}

template <typename Data>
void NodeTemplate<Data>::setptr(NodeTemplate<Data> *t_nextNode)
{
    this->nextNode = t_nextNode;
}

template <typename Data>
Data NodeTemplate<Data>::getx()
{
    return this->x;
}

template <typename Data>
NodeTemplate<Data>* NodeTemplate<Data>::getptr()
{
    return this->nextNode;
}

template <typename Data>
NodeTemplate<Data>::~NodeTemplate()
{}
