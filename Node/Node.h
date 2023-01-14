#ifndef NODE_H
#define NODE_H

template <class Data>
class Node
{
    private:
        Data x;
        Node *nextNode;

    public:
        Node(Node*, Data);
        void setx(Data);
        void setptr(Node*);
        Data getx();
        // I have to put this here cause vs is dumb
        template <class Data>
        Node* Node<Data>::getptr()
        {
            return this->nextNode;
        }
        ~Node();
};


#endif
