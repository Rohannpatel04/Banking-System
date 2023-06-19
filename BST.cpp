using namespace std;

#include "BST.h"

template<class ItemType>
BST<ItemType>::BST() : root(nullptr) {}

template<class ItemType>
BST<ItemType>::BST(Node<ItemType> *rootPtr) {
    root = rootPtr;
}

template<class ItemType>
bool BST<ItemType>::add(ItemType *newDataObject) {
    auto *newNodePtr = new Node<ItemType>(newDataObject);
    root = inOrderInsert(root, newNodePtr);
    return true;
}

template<class ItemType>
Node<ItemType> *BST<ItemType>::inOrderInsert(Node<ItemType> *subTreePtr, Node<ItemType> *newNodePtr) {
    
    //Base case: subTreePtr is NULL
    if (subTreePtr == NULL)
        return newNodePtr;

    //The ID of the item to add is larger than the current item ID, traverse to right subtree
    else if (subTreePtr->getNodeID() < newNodePtr->getNodeID()) {
        auto tempPtr = inOrderInsert(subTreePtr->getNodeRight(), newNodePtr);
        subTreePtr->setNodeRight(tempPtr);

    //The ID of the item to add is smaller than the current item ID, traverse to left subtree
    } else {
        auto tempPtr = inOrderInsert(subTreePtr->getNodeLeft(), newNodePtr);
        subTreePtr->setNodeLeft(tempPtr);
    }

    return subTreePtr;
}

template <class ItemType>
ItemType *BST<ItemType>::contains(Node<ItemType> *rootPtr, int id) {

    //Return nullptr if the tree is empty
    if (root == NULL) {
        return nullptr;
    }

    Node<ItemType> *current;

    current = root;

    //Checking if the item is in the BST iteratively with the node ID
    while (current != NULL) {
        if (current->getNodeID() == id) {
            return current->getNodeData();
        } else
        if (id > current->getNodeID()) {
            current = current->getNodeRight();
        }
        else
            current = current->getNodeLeft();
        }
    return nullptr;
}

template<class ItemType>
void BST<ItemType>::PrintInOrder() {
    if (root == NULL) {
        cout << "No Clients Found!" << endl;
    } else {
        PrintInOrderPrivate(root);
    }
}

//Helper function for PrintInOrder
//Recursively traverses the BST and prints the values of the tree in order
template<class ItemType>
void BST<ItemType>::PrintInOrderPrivate(Node<ItemType> *ptr) {
    if (ptr == NULL) {
        return;
    } else {
        PrintInOrderPrivate(ptr->getNodeLeft());
        cout << *ptr->getNodeData();
        PrintInOrderPrivate(ptr->getNodeRight());
    }
}

//Recursively deletes the tree nodes
template<class ItemType>
void BST<ItemType>::emptyTree(Node<ItemType> *node) {
    if (node == NULL) {
        root = NULL;
        return;
    }
    emptyTree(node->getNodeLeft());
    emptyTree(node->getNodeRight());
    delete node;
}

template<class ItemType>
Node<ItemType> *BST<ItemType>::getRoot() const {
    return root;
}

template<class ItemType>
bool BST<ItemType>::isEmpty() {
    if (getRoot() == NULL) {
        cout << "The Tree is Empty!" << endl;
        return true;
    } else {
        return false;
    }
}
