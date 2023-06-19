#include "TransactionHistoryHandler.h"
#include <sstream>

TransactionHistoryHandler::TransactionHistoryHandler(BST<Client> &clientSearchTree, const string &transaction) {
    parseHistory(clientSearchTree, transaction);
}

//Reads the transaction string input to extract data
bool TransactionHistoryHandler::parseHistory(BST<Client> clientSearchTree, const string &transaction) {
    stringstream s(transaction);
    string word;
    while (s >> word) {
        parsedTransaction.push_back(word);
    }
    if (parsedTransaction[1].length() == 4) {
        clientID = stoi(parsedTransaction[1]);
        accountType = '\0';
    } else {
        accountType = parsedTransaction[1].at(4);
        parsedTransaction[1].erase(4, 1);
        clientID = stoi(parsedTransaction[1]);
    }
    client = clientSearchTree.contains(clientSearchTree.getRoot(), clientID);
    return true;
}

char TransactionHistoryHandler::getAccountType() const {
    return accountType;
}

Client* TransactionHistoryHandler::getClient() const {
    return client;
}
