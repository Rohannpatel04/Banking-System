
#ifndef JOLLYBANKER_BANK_H
#define JOLLYBANKER_BANK_H

#include <unordered_map>
#include <string>
#include <queue>
#include "Client.h"
#include "BST.h"
#include "TransferHandler.h"
#include "WithdrawHandler.h"
#include "DepositHandler.h"
#include "OpenAccountHandler.h"
#include "TransactionHistoryHandler.h"

using namespace std;

class Bank {
public:
    /* Constructor */
    Bank();

    /* Getter */
    static string getAccountMapping(const char &accountType);

    /* Behavior Methods */
    bool processQueue();
    bool readIntoQueue(string &fileName);

protected:
    /* Getters */
    static bool getClientHistory(Client *client);
    static bool getClientAccountHistory(Client *client, const char &accountType);

    /* Behavior Methods */
    static bool withdraw(WithdrawHandler withdrawHandler);
    bool openAccount(OpenAccountHandler openAccountHandler);
    static bool deposit(DepositHandler depositHandler);
    static bool transfer(TransferHandler transferHandler);

private:
    BST<Client> clientSearchTree;
    queue<string> transactionQueue;
    static inline unordered_map<char, string> accountTypes = {{'0', "Money Market"},
                                                       {'1', "Prime Money Market"},
                                                       {'2', "Long-Term Bond"},
                                                       {'3', "Short-Term Bond"},
                                                       {'4', "500 Index Fund"},
                                                       {'5', "Capital Value Fund"},
                                                       {'6', "Growth Equity Fund"},
                                                       {'7', "Growth Index Fund"},
                                                       {'8', "Value Fund"},
                                                       {'9', "Value Stock Index"}};
};

#endif //JOLLYBANKER_BANK_H