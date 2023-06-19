#include "Node.h"

template <class ItemType>
__attribute__((unused)) __attribute__((unused)) Node<ItemType>::Node(ItemType *dataObjectPtr, Node<ItemType>* leftPtr, Node<ItemType>* rightPtr) {
    dataObject = dataObjectPtr;
    left = leftPtr;
    right = rightPtr;
    nodeID = dataObjectPtr->getID();
}

//Creates a node with a left and right branch, a place for data, and an ID
template <class ItemType>
Node<ItemType>::Node(ItemType *dataObjectPtr) {
    dataObject = dataObjectPtr;
    nodeID = dataObjectPtr->getID();
    left = nullptr;
    right = nullptr;
}

template <class ItemType>
ItemType* Node<ItemType>::getNodeData() const {
    return dataObject;
}

template <class ItemType>
Node<ItemType>* Node<ItemType>::getNodeLeft() const {
    return left;
}
template <class ItemType>
Node<ItemType>* Node<ItemType>::getNodeRight() const {
    return right;
}
template <class ItemType>
int Node<ItemType>::getNodeID() const {
    return nodeID;
}
template <class ItemType>
bool Node<ItemType>::setNodeLeft(Node<ItemType>* leftPtr) {
    left = leftPtr;
    return true;
}
template <class ItemType>
bool Node<ItemType>::setNodeRight(Node<ItemType>* rightPtr) {
    right = rightPtr;
    return true;
}

template<class ItemType>
Node<ItemType>::Node() {

}
