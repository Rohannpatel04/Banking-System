
#ifndef JOLLYBANKER_NODE_H
#define JOLLYBANKER_NODE_H

template<class ItemType>
class Node {

public:
    /* Constructors */
    Node();
    explicit Node(ItemType *dataObjectPtr);
    Node(ItemType *dataObjectPtr, Node<ItemType> *leftPtr, Node<ItemType> *rightPtr);

    /* Accessor Methods */
        /* Getters */
        ItemType *getNodeData() const;
        Node<ItemType> *getNodeLeft() const;
        Node<ItemType> *getNodeRight() const;
        int getNodeID() const;

        /* Setters */
        bool setNodeLeft(Node<ItemType> *leftPtr);
        bool setNodeRight(Node<ItemType> *rightPtr);

private:
    Node<ItemType> *left;
    Node<ItemType> *right;
    ItemType *dataObject;
    int nodeID;
};

#include "Node.cpp"

#endif //JOLLYBANKER_NODE_H