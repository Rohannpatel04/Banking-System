#ifndef JOLLYBANKER_CLIENT_H
#define JOLLYBANKER_CLIENT_H

#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Client {
public:
    /* Constructor */
    Client(const string &lastName, const string &firstName, const int &clientID);

    /* Accessor Methods */
        /* Getters */
        int getID() const;
        double getAccountFunds(const char &accountType) const;
        string getLastName() const;
        string getFirstName() const;
        unordered_map<char, vector<string>> getTransactionHistory() const;
        vector<string> getAccountHistory(char accountType) const;

        /* Setters */
        bool addTransactionRecord(const char &accountType, const string &s);
        bool addAccountFunds(const char &accountType, const double &amount);
        bool withdrawAccountFunds(const char &accountType, const double &amount);

    /* Operator Overloads */
    friend ostream &operator<<(ostream &output, Client &c);

private:
    string lastName, firstName;
    int clientID;
    unordered_map<char, vector<string>> accountTransactions;
    unordered_map<char, double> accountFunds = {{'0', 0},
                                                {'1', 0},
                                                {'2', 0},
                                                {'3', 0},
                                                {'4', 0},
                                                {'5', 0},
                                                {'6', 0},
                                                {'7', 0},
                                                {'8', 0},
                                                {'9', 0}};
};


#endif //JOLLYBANKER_CLIENT_H
