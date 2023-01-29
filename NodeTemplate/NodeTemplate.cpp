
#include "NodeTemplate.h"

// this is still not working for some reason
template <class Data>
NodeTemplate<Data>::NodeTemplate(NodeTemplate *t_nextNode, Data t_x)
{
    this->x = t_x;
    this->nextNode = t_nextNode;
}

template <class Data>
void NodeTemplate<Data>::setx(Data t_x)
{
    this->x = t_x;
}

template <class Data>
void NodeTemplate<Data>::setptr(NodeTemplate *t_nextNode)
{
    this->nextNode = t_nextNode;
}

template <class Data>
Data NodeTemplate<Data>::getx()
{
    return this->x;
}

template <class Data>
NodeTemplate<Data>::~NodeTemplate()
{}
