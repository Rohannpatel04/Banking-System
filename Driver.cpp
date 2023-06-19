#include <iostream>
#include <fstream>

using namespace std;

#include "Bank.h"

//Takes in the file with transactions as the argument
int main(int argc,  char **argv){
    string transactionsFile(argv[1]);
    Bank b;
    b.readIntoQueue(transactionsFile);
    b.processQueue();
    return 0;
}
