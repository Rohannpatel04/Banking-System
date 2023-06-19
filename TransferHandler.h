#ifndef JOLLYBANKER_TRANSFERHANDLER_H
#define JOLLYBANKER_TRANSFERHANDLER_H

#include "BST.h"

class TransferHandler {
public:
    /* Constructor */
    TransferHandler(const BST<Client> &clientSearchTreePtr, const string &transaction);

    /* Behavior Methods */
    bool withdrawFromTransferClient();
    bool depositIntoReceivingClient();
    bool isValidTransfer();

private:
    Client *transferClient;
    Client *receivingClient;
    string transferClientTransaction, receivingClientTransaction;
    vector<string> parsedTransaction;
    int transferClientID, receivingClientID;
    char transferAccountType, receivingAccountType;

    bool parseTransfer(BST<Client> clientSearchTree, const string &transaction);

    double amount;
    string transferClientName, receivingClientName;
};

#endif //JOLLYBANKER_TRANSFERHANDLER_H