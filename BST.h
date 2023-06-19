#include <iostream>
#include "Node.h"
#include "Client.h"

#ifndef JOLLYBANKER_BST_H
#define JOLLYBANKER_BST_H

template<class ItemType>
class BST {
protected:
    /* Behavior Methods */
    Node<ItemType> *inOrderInsert(Node<ItemType> *subTreePtr, Node<ItemType> *newNodePtr); //Recursive helper method to add nodes to tree
    void PrintInOrderPrivate(Node<ItemType> *ptr);

public:
    /* Constructors */
    BST();
    explicit BST(Node<ItemType> *rootPtr);

    /* Getter */
    Node<ItemType> *getRoot() const;

    /* Setter */
    bool add(ItemType *newDataObject); //Adds an object to the BST

    /* Behavior Methods */
    void emptyTree(Node<ItemType> *node);
    bool isEmpty();
    ItemType *contains(Node<ItemType> *rootPtr, int id);//Searches BST for object, returns pointer to object
    void PrintInOrder();

private:
    Node<ItemType> *root;
};

#include "BST.cpp"

#endif //JOLLYBANKER_BST_H
