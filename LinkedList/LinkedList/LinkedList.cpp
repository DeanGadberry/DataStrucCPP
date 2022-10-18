// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
private:
    int x;
    Node *nextNode;

public:
    Node(Node*, int);
    void setx(int);
    void setptr(Node*);
    int getx();
    Node* getptr();
    ~Node();
};

Node::Node(Node *t_nextNode = nullptr, int t_x = 10)
{
    this->x = t_x;
    this->nextNode = t_nextNode;
}

void Node::setx(int t_x)
{
    this->x = t_x;
}

void Node::setptr(Node* t_nextNode)
{
    this->nextNode = t_nextNode;
}

int Node::getx()
{
    return this->x;
}

Node* Node::getptr()
{
    return this->nextNode;
}

Node::~Node()
{

}


class LinkList
{
private:
    Node *first_node;
public:
    LinkList(int, Node*);
    void printlist();
    void addnode(int);
    void removenode(int);
    ~LinkList();
};

LinkList::LinkList(int t_x, Node* t_ptr = nullptr)
{
    // we will point to the first node!
    this->first_node = new Node(t_ptr, t_x);
}

void LinkList::printlist()
{
    Node* nextNode = this->first_node;
    while (nextNode != nullptr)
    {
        Node* thisnode = nextNode;
        nextNode = thisnode->getptr();
        std::cout << thisnode->getx() << std::endl;
    }
    std::cout << "end of list" << std::endl;
}

void LinkList::addnode(int t_x)
{
    Node* newnode = new Node(nullptr, t_x);
    Node* nextnode = this->first_node;
    Node* thisnode = nullptr;
    while (nextnode != nullptr)
    {
        thisnode = nextnode; /// both point to first node
        nextnode = thisnode->getptr(); /// node what is the next node?
    }
    // list(node(10)-> node(20)-> null)
    thisnode->setptr(newnode);
    std::cout << "added new node..." << std::endl;

}

void LinkList::removenode(int x)
{
    // loop through list, and look for x value and remove it...
    Node* nextnode = this->first_node;
    
    // what is the problem, read access vio, but the next node only loops if not null, so how am I getting this error
    while (nextnode->getptr() != nullptr)
    {
        // traverse the linked list
        Node* thisnode = nextnode;
        nextnode = thisnode->getptr();
        if (nextnode->getx() == x)
        {
            // remove this node
            // grab the node after
            Node* rejoin = nextnode->getptr();

            // this node set beyond next node
            thisnode->setptr(rejoin);

            // after the node is unlinked, then remove the node
            delete nextnode;

            // continue looping
            nextnode = rejoin;

            // final node deletion exception fix
            if (nextnode == nullptr)
            {
                // is last node, so no need to loop anymore
                break;
            }
        }

    }

}

LinkList::~LinkList()
{
    // starting at the first node, we delete then move to the next adn then delete
    Node* nextNode = this->first_node;

    while (nextNode != nullptr)
    {
        // hold this node in one pointer and the next in the other
        Node* thisnode = nextNode;
        nextNode = thisnode->getptr();
        // delete one node, while pointer holds on to next node
        delete thisnode;
    }
    std::cout << "list deleted!" << std::endl;
}

int main()
{

    // first node val 10, points to nothing
    LinkList list(10, nullptr);
    for (int i = 0; i <= 10; i++)
    {
        list.addnode(i);
    }
    
    list.printlist();

    list.removenode(4);
    list.removenode(10);

    list.printlist();
}
