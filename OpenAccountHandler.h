#ifndef JOLLYBANKER_OPENACCOUNTHANDLER_H
#define JOLLYBANKER_OPENACCOUNTHANDLER_H
#include "BST.h"

class OpenAccountHandler {
public:
    /* Constructor */
    explicit OpenAccountHandler(const string& transaction);

    /* Behavior Method */
    bool openAccount(BST<Client> &clientSearchTree);

private:
    int clientID;
    string firstName, lastName;
    vector<string> parsedTransaction;
    bool parseAccountOpen(const string &transaction);
};

#endif //JOLLYBANKER_OPENACCOUNTHANDLER_H