Course: CSS342
Assignment: Final - Project Implementation
Group: G++
Name: Rohan Patel 
Date: 12/12/2022

    Program Description: 

        Created a banking application which processes transactions. 
            - The program reads in a txt file into a queue, line by line. 
            - The program then outputs individaul transactions from the queue and determines what transaction needs to take place.
            - A transaction handler object is created depending on the transaction type, which takes in the client search tree and 
            the transaction string. 
            - The program then executes the transaction in it's correseponding transaction handler class. 
            - Thereafter transactions are saved within the client node, which are stored in the clinet bianry search tree. 
            - Finally, clients stored in the binary search tree are printed out into the console.    

    Class Structure: 
        - main 
            - Bank
                - Client 
                - DepositHandler
                - OpenAccountHandler
                - TransactionHistoryHandler
                - TransferHandler
                - WithdrawHandler
            - BST
                - Node

    My Contributions: 

        Binary Search Tree and Node Class: 
            - Implemted functions to store, remove, treverse, and print client nodes which contain
             client data.
            - Each Node contains the the Client ID, a pointer to the client object, and a pointer to the left node and right node. 

        Withdraw Class Implementation: 

            - Implemented a function to withdraw from a clients funds 
            - Implemented the edge case of a specific fund not having enough money so the 
            program withdraws from a similar client fund. 

        Output Implementation: 

            - Implemented operator overlaod to work with the binary search tree print function to output client information. 
        
        Code Review: 

            - Made suggestions to the class designs and suggested and helped omptimize the program. 
                - Caught issues of using const and references 
                - Suggested using a global hash table to store fund types, but we ended up implementing it in a different way. 

    To Compile: 

        - We used: g++ -std=c++17 *.h Driver.cpp TransferHandler.cpp TransactionHistoryHandler.cpp Client.cpp WithdrawHandler.cpp DepositHandler.cpp OpenAccountHandler.cpp Bank.cpp


