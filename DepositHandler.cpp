//
// Created by Matthew Jeffries on 12/4/22.
//

#include "DepositHandler.h"
#include <sstream>

DepositHandler::DepositHandler(const BST<Client> &clientSearchTree, const string &transaction) {
    parseDeposit(clientSearchTree, transaction);
}

//Reads in the transaction string and extracts data from the string
bool DepositHandler::parseDeposit(BST<Client> clientSearchTree, const string &transaction) {
    stringstream s(transaction);
    string word;
    while (s >> word) {
        parsedTransaction.push_back(word);
    }
    accountType = parsedTransaction[1].at(4);
    parsedTransaction[1].erase(4, 1);
    clientID = stoi(parsedTransaction[1]);
    amount = stoi(parsedTransaction[2]);
    client = clientSearchTree.contains(clientSearchTree.getRoot(), clientID);
    return true;
}

//Verifies the information extracted from the transaction can be used to complete a deposit
//Returns errors if there are issues, comlpletes the transaction if there are no issues
bool DepositHandler::depositIntoClientAccount() {

    //Error handling
    if(!client) {
        cerr << "ERROR:: Deposit Rejected ::  Client Account: " + to_string(clientID) + " does not exist." << endl;
        return false;
    }
    if(amount < 0) {
        cerr << "ERROR:: Deposit Rejected :: Cannot Deposit Negative Funds." << endl;
        return false;
    }

    //Transaction
    transactionRecord = "D: $" + to_string(amount);//Generating a transaction record
    client->addAccountFunds(accountType, amount);//Completing the transaction
    client->addTransactionRecord(accountType, transactionRecord);//Storing transaction record
    
    return true;
    }