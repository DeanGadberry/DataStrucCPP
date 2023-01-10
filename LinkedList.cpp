// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// to-do:
//      -[ ]create a ordered linkedlist


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
    // set the Node's val and it's pointer
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
    // the list will just hold a pointer to the first Node
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
    // start list by creating node, and pointing to it
    this->first_node = new Node(t_ptr, t_x);
    std::cout << "list created!" << std::endl;
}

void LinkList::printlist()
{
    // prints all of the nodes attached to list but more optimised
    Node* currentNode = this->first_node;
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

void LinkList::addnode(int t_x)
{
    // adds a node to the end of the linked list
    // create the node that will be added in teh heap
    Node* newnode = new Node(nullptr, t_x);
    Node* nextnode = this->first_node;
    Node* thisnode = nullptr;
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

void LinkList::removenode(int x)
{
    // loop through list, and look for x value and remove it...
    Node* nextnode = this->first_node;
    
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
            Node* thisnode = nextnode;
            nextnode = thisnode->getptr();
            // when the node is found then remove it
            if (nextnode->getx() == x)
            {
                // grab the node after
                Node* rejoin = nextnode->getptr();

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


LinkList::~LinkList()
{
    // starting at the first node, we delete then move to the next adn then delete
    Node* nextNode = this->first_node;
    
    // loop through list
    while (nextNode != nullptr)
    {
        // hold this node in one pointer and the next in the other
        Node* thisnode = nextNode;
        nextNode = thisnode->getptr();
        // delete one node, while pointer holds on to next node
        delete thisnode;
    }

    // make sure that we aren't pointing to heap for no reason
    this->first_node = nullptr;
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
