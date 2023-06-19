
#ifndef JOLLYBANKER_DEPOSITHANDLER_H
#define JOLLYBANKER_DEPOSITHANDLER_H

#include "BST.h"

class DepositHandler {
public:
    /* Constructor */
    DepositHandler(const BST<Client> &clientSearchTree, const string &transaction);

    /* Behavior Method */
    bool depositIntoClientAccount();

private:
    vector<string> parsedTransaction;
    double amount;
    Client* client;
    char accountType;
    int clientID;
    string transactionRecord;
    bool parseDeposit(BST<Client> clientSearchTree, const string &transaction);
};


#endif //JOLLYBANKER_DEPOSITHANDLER_H
