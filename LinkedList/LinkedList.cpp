// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// to-do:
//      -[ ]create a ordered linkedlist


#include <iostream>
#include "Node.h"
#include "LinkedList.h"

template <class NodeData>
LinkedList<NodeData>::LinkedList(NodeData t_x, Node<NodeData>* t_ptr)
{
    // start list by creating node, and pointing to it
    this->first_node = new Node<NodeData>(t_ptr, t_x);
    std::cout << "list created!" << std::endl;
}

template <class NodeData>
void LinkedList<NodeData>::printlist()
{
    // prints all of the nodes attached to list but more optimised
    Node<NodeData>* currentNode = this->first_node;
    std::cout << "printing list:" << std::endl;
    // loop through list, and print each node
    while (currentNode != nullptr)
    {
        // print current node var
        std::cout << currentNode->getx() << std::endl;
        // go to next node
        currentNode = currentNode->getptr();
    }
    std::cout << "end of list..." << std::endl;
}

template <class NodeData>
void LinkedList<NodeData>::addnode(NodeData t_x)
{
    // adds a node to the end of the linked list
    // create the node that will be added in teh heap
    Node<NodeData>* newnode = new Node(nullptr, t_x);
    Node<NodeData>* nextnode = this->first_node;
    Node<NodeData>* thisnode = nullptr;
    // loop through the list
    while (nextnode != nullptr)
    {
        thisnode = nextnode; 
        nextnode = thisnode->getptr();
    }
    // list(node(10)-> node(20)-> null)
    // append node to end of list
    thisnode->setptr(newnode);
    // newnode already has nullptr set done!
    std::cout << "added new node..." << std::endl;

}

template <class NodeData>
void LinkedList<NodeData>::removenode(NodeData x)
{
    // loop through list, and look for x value and remove it...
    Node<NodeData>* nextnode = this->first_node;
    
    if (nextnode->getx() == x)
    {
        // then the first node is the value
        this->first_node = nextnode->getptr();

        // reallocate memory at the first node
        delete nextnode;

        // set nextnode so no longer pointing to unalloc mem
        nextnode = nullptr;
    }
    else
    {
        // what is the problem, read 
        while (nextnode->getptr() != nullptr)
        {
            // traverse the linked list
            Node<NodeData>* thisnode = nextnode;
            nextnode = thisnode->getptr();
            // when the node is found then remove it
            if (nextnode->getx() == x)
            {
                // grab the node after
                Node<NodeData>* rejoin = nextnode->getptr();

                // this node set beyond next node
                thisnode->setptr(rejoin);

                // after the node is unlinked, then remove the node
                delete nextnode;

                // continue looping
                nextnode = rejoin;

                std::cout << "node deleted :" << x << std::endl;

                // final node deletion exception fix, this is not a loop cond for efficiency
                if (nextnode == nullptr)
                {
                    // is last node, so no need to loop anymore
                    break;
                }
            }

        }
    }

}

template <class NodeData>
LinkedList<NodeData>::~LinkedList()
{
    // starting at the first node, we delete then move to the next adn then delete
    Node<NodeData> nextNode = this->first_node;
    
    // loop through list
    while (nextNode != nullptr)
    {
        // hold this node in one pointer and the next in the other
        Node<NodeData>* thisnode = nextNode;
        nextNode = thisnode->getptr();
        // delete one node, while pointer holds on to next node
        delete thisnode;
    }

    // make sure that we aren't pointing to heap for no reason
    this->first_node = nullptr;
    std::cout << "list deleted!" << std::endl;
}
