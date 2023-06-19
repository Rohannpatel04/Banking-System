
#ifndef JOLLYBANKER_WITHDRAWHANDLER_H
#define JOLLYBANKER_WITHDRAWHANDLER_H

#include "BST.h"

class WithdrawHandler {
public:
    /* Constructor */
    WithdrawHandler(const BST<Client> &clientSearchTree, const string &transaction);

    /* Getter */
    char getAccountType() const;

    /* Behavior Method */
    bool withdrawFromClient();

private:
    int clientID;
    string clientName;
    Client *client;
    double amount;
    char accountType;
    string transactionRecord;
    vector<string> parsedTransaction;

    /* Behavior Methods */
    bool parseWithdraw(BST<Client> clientSearchTree, const string &transaction);
    bool isValidWithdraw();
};


#endif //JOLLYBANKER_WITHDRAWHANDLER_H
