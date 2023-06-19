#ifndef JOLLYBANKER_TRANSACTIONHISTORYHANDLER_H
#define JOLLYBANKER_TRANSACTIONHISTORYHANDLER_H

#include "BST.h"

class TransactionHistoryHandler {
public:
    /* Constructor */
    TransactionHistoryHandler(BST<Client> &clientSearchTree, const string &transaction);

    /* Getters */
    char getAccountType() const;
    Client *getClient() const;

private:
    Client *client;
    char accountType;
    int clientID;

    bool parseHistory(BST<Client> clientSearchTree, const string &transaction);

    vector<string> parsedTransaction;
};

#endif //JOLLYBANKER_TRANSACTIONHISTORYHANDLER_H