#include "WithdrawHandler.h"
#include "Bank.h"
#include <sstream>

//Used to determine if accounts are paired when withdrawing from an account without enough money
    unordered_map<char, char> pairedAccounts = {{'0', '1'}, {'1', '0'}, {'2', '3'}, {'3', '2'}};

WithdrawHandler::WithdrawHandler(const BST<Client> &clientSearchTree, const string &transaction) {
    parseWithdraw(clientSearchTree, transaction);
}

bool WithdrawHandler::parseWithdraw(BST<Client> clientSearchTree, const string &transaction) {
    stringstream s(transaction);
    string word;

    //Pushing strings separated by spaces from transaction into the parsedTransaction vector
    while (s >> word) {
        parsedTransaction.push_back(word);
    }

    //String operations to gather account and transaction information
    accountType = parsedTransaction[1].at(4);
    parsedTransaction[1].erase(4, 1);
    clientID = stoi(parsedTransaction[1]);
    amount = stoi(parsedTransaction[2]);
    client = clientSearchTree.contains(clientSearchTree.getRoot(), clientID);
    clientName = client->getFirstName() + " " + client->getLastName();
    return true;
}

bool WithdrawHandler::withdrawFromClient() {

    //Checks if the client exists
    if (!client) {
        cerr << "ERROR: Client " + to_string(clientID) + " does not exist." << endl;
        return false;

        //Checks if the client has enough money in their account
    } else
    if (client->getAccountFunds(accountType) < amount) {

        //Checks if the client has enough money in a paired account
        if (pairedAccounts.find(accountType) != pairedAccounts.end() &&
            client->getAccountFunds(pairedAccounts[accountType]) + client->getAccountFunds(accountType) > amount) {
            double remainder = amount - client->getAccountFunds(accountType);

            client->withdrawAccountFunds(pairedAccounts[accountType], remainder);
            client->withdrawAccountFunds(accountType, amount - remainder);

            client->addTransactionRecord(accountType, "W: $" + to_string(amount - remainder));
            client->addTransactionRecord(pairedAccounts[accountType], "W: $" + to_string(remainder) + " to deposit into " +
                                                        Bank::getAccountMapping(accountType) + " to cover a $" +
                                                        to_string(amount) + " withdrawal");
            return true;
        } else {
            //If the client does not have enough money to withdraw, then send an error message to cerr
            cerr << "ERROR:: Withdraw Failed :: " + clientName + " does not have sufficient funds in: " +
                    Bank::getAccountMapping(accountType) << "." << endl;
            transactionRecord = "W: $" + to_string(amount) + " (Failed)";
            client->addTransactionRecord(accountType, transactionRecord);
        }
    }
    return false;
}

char WithdrawHandler::getAccountType() const {
    return accountType;
}
