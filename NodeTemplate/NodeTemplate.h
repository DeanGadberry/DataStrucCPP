#ifndef NODETEMPLATE_H
#define NODETEMPLATE_H

template <class Data>
class NodeTemplate
{
    private:
        Data x;
        NodeTemplate *nextNode;

    public:
        NodeTemplate<Data>(NodeTemplate<Data>*, Data);
        void setx(Data);
        void setptr(NodeTemplate<Data>*);
        Data getx();
        // I have to put this here cause vs is dumb
        NodeTemplate<Data>* getptr();
        ~NodeTemplate<Data>();
};


#endif
