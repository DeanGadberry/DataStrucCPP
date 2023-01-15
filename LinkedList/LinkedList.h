#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class NodeData>
class LinkedList
{
    private:
        // the list will just hold a pointer to the first Node
        Node<NodeData> *first_node;
    public:
        LinkedList(NodeData, Node<NodeData>*);
        void printlist();
        void addnode(NodeData);
        void removenode(NodeData);
        ~LinkedList();
};


#endif
