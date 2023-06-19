#include "Client.h"
#include <iostream>
#include "Bank.h"

Client::Client(const string &clientLastName, const string &clientFirstName, const int &newClientID) {
    firstName = clientFirstName;
    lastName = clientLastName;
    clientID = newClientID;

}

int Client::getID() const {
    return clientID;
}

double Client::getAccountFunds(const char &accountType) const {
    return accountFunds.at(accountType);
}

bool Client::addAccountFunds(const char &accountType, const double &amount) {
    accountFunds[accountType] += amount;
    return true;
}

bool Client::withdrawAccountFunds(const char &accountType, const double &amount) {
    accountFunds[accountType] -= amount;
    return true;
}

bool Client::addTransactionRecord(const char &accountType, const string &s) {
    accountTransactions[accountType].push_back(s);
    return true;
}

unordered_map<char, vector<string>> Client::getTransactionHistory() const {
    return accountTransactions;
}

string Client::getLastName() const {
    return lastName;
}

string Client::getFirstName() const {
    return firstName;
}

vector<string> Client::getAccountHistory(char accountType) const {
    return accountTransactions.at(accountType);
}

//Prints the associated first and last names, account ID, and account funds in a formatted order.
ostream &operator<<(ostream &output, Client &c) {
    output << c.getFirstName() << " " << c.getLastName() << " Account ID: " << c.getID() << endl;

    for (auto &accountFund: c.accountFunds) {
        output << "     " << Bank::getAccountMapping(accountFund.first) << ": $" << accountFund.second << endl;
    }

    return output;
}

