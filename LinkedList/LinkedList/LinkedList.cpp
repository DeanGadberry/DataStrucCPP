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
    this->nextNode = t_nextNode; /// problem?
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
    LinkList(Node);
    void printlist();
    void addnode(Node);
    void removenode(int);
    ~LinkList();
};

LinkList::LinkList(Node f_node)
{
    // we will point to the first node!
    this->first_node = new Node(f_node.getptr(), f_node.getx());
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

void LinkList::addnode(Node t_addnode)
{
    Node* newnode = new Node(t_addnode.getptr(), t_addnode.getx());
    Node* nextnode = this->first_node;
    Node* thisnode = {};
    while (nextnode != nullptr)
    {
        Node* thisnode = nextnode; /// both point to first node
        nextnode = thisnode->getptr(); /// node what is the next node?
    }
    // list(node(10)-> node(20)-> null)
    thisnode->setptr(newnode);
    std::cout << "added new node..." << std::endl;

}

void LinkList::removenode(int x)
{


}

LinkList::~LinkList()
{
    // starting at the first node, we delete then move to the next adn then delete
    Node* nextNode = this->first_node;

    while (nextNode != nullptr)
    {
        // grab this node in one hand and the next in the other
        Node* thisnode = nextNode;
        nextNode = thisnode->getptr();
        // delete one node, while hand holds on to next node
        delete thisnode;
    }
    std::cout << "list deleted!" << std::endl;
}

int main()
{
    // Linkedlist (first pointer to node one)(Node(10) -> Node(20) -> Node(30) -> null)
    // 
    // adding nodes
    // list (Node(10)->null)
    // list (Node(10)->Node(20)->Node(30)->null)
    // Node new
    // Node fistnode
    // Node nextnode->null | newnode
    // 
    // jerry -> Bruce -> Carla (10 bytes) x 100
    // pointer (1 byte) x 100 functions = 100 bytes
    // heap memory "new" <- no var name
    // no var name <- where is it?
    // heap meme <- must be pointed to

    //
    
    int x = 10;
    int* ptr = nullptr;
    
    ptr = &x;
    std::cout << *ptr;


    Node newnode(nullptr, 10);
    LinkList list(newnode);
    //Node evennewernode(nullptr, 20);
    //list.addnode(evennewernode);
    
    list.printlist();

}
