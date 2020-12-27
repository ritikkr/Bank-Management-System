#include <iostream>
#include <stdlib.h>
#include "bank.h"
using namespace std;

int startMenu()
{
    int choice;
    std::cout << "----------Welcome to Our Bank Service----------" << endl;
    std::cout << endl;
    std::cout << endl;
    std::cout << "1. Create a New Account " << endl;
    std::cout << "2. Open a Exisiting Account " << endl;
    std::cout << "3. Exit " << endl;
    std::cout << "Choice(1-3): ";

    cin >> choice;
    system("clear");
    return choice;
}
int main()
{
    static Bank *users = new Bank[100];
    int current = 0;
    int choice = startMenu();
    if (choice == 1)
    {
        (users + current)->newAccount();
        (users + current)->addAccount(current);
    }
    else if (choice == 2)
    {
        Bank tempObj;
        int accountNumber;
        cout << "Enter Your Account No: " << endl;
        cin >> accountNumber;
        int obj = tempObj.check(accountNumber);
        if (obj == -1)
        {
            std::cout << "\n\tInvalid Account Number !!!! \n\n" << endl;
        }
        else
        {
            (users + obj)->menu();
        }
    }
    else if (choice == 3)
    {
        std::cout << "Thank you for using our bank service :-) " << endl;
        std::cout << "Happy to serve you !!! " << endl;
        exit(0);
    }
    else
    {
        std::cout << "Wrong input !!!! " << endl;
        exit(0);
    }
    main();
    return 0;
}