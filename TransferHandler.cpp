#include "TransferHandler.h"
#include "Bank.h"
#include <sstream>

TransferHandler::TransferHandler(const BST<Client> &clientSearchTree, const string &transaction) {
    parseTransfer(clientSearchTree, transaction);

}

//Reads the transaction string input to extract data
bool TransferHandler::parseTransfer(BST<Client> clientSearchTree, const string &transaction) {
    stringstream s(transaction);
    string word;
    while (s >> word) {
        parsedTransaction.push_back(word);
    }
    transferAccountType = parsedTransaction[1].at(4);
    parsedTransaction[1].erase(4, 1);
    transferClientID = stoi(parsedTransaction[1]);
    receivingAccountType = parsedTransaction[3].at(4);
    parsedTransaction[3].erase(4, 1);
    receivingClientID = stoi(parsedTransaction[3]);
    amount = stoi(parsedTransaction[2]);

    //The rest of this function gets the memory addresses and names of the clients the transfer will be between
    transferClient = clientSearchTree.contains(clientSearchTree.getRoot(), transferClientID);
    receivingClient = clientSearchTree.contains(clientSearchTree.getRoot(), receivingClientID);

    if (transferClient) {
        transferClientName = transferClient->getFirstName() + " " + transferClient->getLastName();
    }
    if (receivingClient) {
        receivingClientName = receivingClient->getFirstName() + " " + receivingClient->getLastName();
    }
    return true;
}

//Adds account funds into the dpecified client
bool TransferHandler::depositIntoReceivingClient() {
    receivingClient->addAccountFunds(receivingAccountType, amount);
    receivingClientTransaction = "T: $" + to_string(amount) + " from " + transferClientName;
    receivingClient->addTransactionRecord(receivingAccountType, receivingClientTransaction);
    return true;
}

//Removes account funds from the specified client
bool TransferHandler::withdrawFromTransferClient() {
    transferClient->withdrawAccountFunds(transferAccountType, amount);
    transferClientTransaction = "T: $" + to_string(amount) + " to " + receivingClientName;
    transferClient->addTransactionRecord(transferAccountType, transferClientTransaction);
    return true;
}

//Ensures both clients exist, and the transfer client has sufficient funds
bool TransferHandler::isValidTransfer() {
    if (!transferClient) {
        cerr << "ERROR: Client " + to_string(transferClientID) + " does not exist." << endl;
        return false;
    }
    if (!receivingClient) {
        cerr << "ERROR:: Transfer Failed :: Client " + to_string(receivingClientID) + " does not exist." << endl;
        return false;
    }
    if (transferClient->getAccountFunds(transferAccountType) - amount < 0) {
        cerr << "ERROR:: Transfer Failed :: " + transferClientName + " does not have sufficient funds in: " + Bank::getAccountMapping(transferAccountType) + "."
             << endl;
        return false;
    }
    return true;
}
