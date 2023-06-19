#include <fstream>
#include "Bank.h"

Bank::Bank() = default;

//Handles the queue of transactions
bool Bank::processQueue() {
    while (!transactionQueue.empty()) {

        //Takes in one transaction from the queue on each loop
        string transaction = transactionQueue.front();

        //Depending on the type of transaction, a different Handler object is called.
        if (transaction[0] == 'T') {
            TransferHandler t(clientSearchTree, transaction);
            transfer(t);
        } else if (transaction[0] == 'W') {
            WithdrawHandler w(clientSearchTree, transaction);
            withdraw(w);
        } else if (transaction[0] == 'D') {
            DepositHandler d(clientSearchTree, transaction);
            deposit(d);
        } else if (transaction[0] == 'O') {
            OpenAccountHandler o(transaction);
            openAccount(o);
        } else if (transaction[0] == 'H') {
            TransactionHistoryHandler h(clientSearchTree, transaction);

            //If there is no specified account type, retrieve transaction history for all account types.
            if (!h.getAccountType()) {
                getClientHistory(h.getClient());

            //Otherwise, only retrieve transaction history for the specified account type.
            } else {
                getClientAccountHistory(h.getClient(), h.getAccountType());
            }
        }

        //Getting next transaction from the queue
        transactionQueue.pop();
    }

    //Print out list of all processed transactions and empty the tree.
    cout << "Processing Done. Final Balances" << endl;
    clientSearchTree.PrintInOrder();
    clientSearchTree.emptyTree(clientSearchTree.getRoot());
    clientSearchTree.isEmpty();
    return true;
}

//Add client to the BST
bool Bank::openAccount(OpenAccountHandler openAccountHandler) {
    return openAccountHandler.openAccount(clientSearchTree);
}

//Add funds to client account
bool Bank::deposit(DepositHandler d) {
    return d.depositIntoClientAccount();
}

//Transfers funds between accounts
bool Bank::transfer(TransferHandler transferHandler) {

    //Ensures the transfer can be completed (there is enough cash in the account to transfer)
    if (transferHandler.isValidTransfer()) {
        transferHandler.withdrawFromTransferClient();
        transferHandler.depositIntoReceivingClient();
        return true;
    } else {
        return false;
    }
}

//Withdraws funds from an account
bool Bank::withdraw(WithdrawHandler withdrawHandler) {
    return withdrawHandler.withdrawFromClient();
}

//Opens the specified file and generates a queue of transactions
bool Bank::readIntoQueue(string &fileName) {
    ifstream transactionsFile;
    transactionsFile.open(fileName);
    string line;
    while (getline(transactionsFile, line)) {
        transactionQueue.push(line);
    }
    transactionsFile.close();
    return true;
}

//Prints the transaction history for a client
bool Bank::getClientHistory(Client *client) {
    if (client) {
        cout << "Transaction History for Client: " << client->getFirstName() << " " << client->getLastName() << endl;
        unordered_map<char, vector<string>> clientTransactions = client->getTransactionHistory();
        auto it = clientTransactions.begin();
        for (auto &clientTransaction: clientTransactions) {
            cout << accountTypes[clientTransaction.first] << ": " << "$"
                 << to_string(client->getAccountFunds(clientTransaction.first)) << endl;
            for (const string &transaction: clientTransaction.second) {
                cout << transaction << endl;
            }
        }
        cout << endl;
        return true;
    }
    return false;
}

//Prints the transaction history for a client's specific account
bool Bank::getClientAccountHistory(Client *client, const char &accountType) {
    if (client) {
        cout << "Transaction History for Client: " << client->getFirstName() << " " << client->getLastName() << ": "
             << accountTypes[accountType] << endl;
        vector<string> clientAccountTransactions = client->getAccountHistory(accountType);
        for (const string &transaction: clientAccountTransactions) {
            cout << transaction << endl;
        }
        return true;
    }
    return false;
}

//Returns string mapped to input char
string Bank::getAccountMapping(const char &accountType) {
    return accountTypes[accountType];
}
