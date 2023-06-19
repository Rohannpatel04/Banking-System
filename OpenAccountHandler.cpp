#include "OpenAccountHandler.h"
#include <sstream>

OpenAccountHandler::OpenAccountHandler(const string &transaction) {
    parseAccountOpen(transaction);
}

//Reads the transaction string input to extract data
bool OpenAccountHandler::parseAccountOpen(const string &transaction) {
    stringstream s(transaction);
    string word;
    while (s >> word) {
        parsedTransaction.push_back(word);
    }
    lastName = parsedTransaction[1];
    firstName = parsedTransaction[2];
    clientID = stoi(parsedTransaction[3]);
    return true;
}

//Generates an account with data from parsing the transaction string.
bool OpenAccountHandler::openAccount(BST<Client> &clientSearchTree) {
    auto *newClientPtr = new Client(lastName, firstName, clientID);//Making a new client

    //Verifying a client doesn't already exist in the tree at the specified index to add the new client
    if (!clientSearchTree.contains(clientSearchTree.getRoot(), newClientPtr->getID())) {
        clientSearchTree.add(newClientPtr);
        return true;

    //A client already exists at the specified index, delete this new client and return an error.
    } else {
        delete newClientPtr;
        cerr << "ERROR:: Opening Account Failed :: Client " << clientID << " Already has an open account." << endl;
        return false;
    }
}