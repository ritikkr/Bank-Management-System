#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "person.h"
using namespace std;

class Bank : public Person
{

    static int currentAccount;
    int accountNumber;
    int custID;
    int accountBalance;
    static std::map<int, int> accountObjectPairs;

public:
    ///function to displays the menu or welcome screen to perform different banking activities
    void menu();

    /// function to create a new account
    void newAccount();

    /// function to view exisiting account holder details
    void details();

    /// function to list the details of all existing users
    void list();

    /// function to edit the details of existing user
    void edit();

    /// function to make a transcation
    void transction();

    ///  function to erase the details of existing user
    void erase();

    /// function to check if particular account number exist or not
    int check(int);

    /// function to switch between different exisiting functionality
    void funcSwitcher(int choice);

    /// function to map or associate the account number with object number
    void addAccount(int);

    /// function to check your account balance
    void viewBalance();

    /// function to add given money to your account
    void addMoney(int);

    /// function to withdrawl given amount
    bool withdrawlAmount(int);

    /// function to transfer you fund to another bank account
    bool fundTransfer(int);
};
int Bank ::currentAccount = 1000;
std::map<int, int> Bank ::accountObjectPairs;

void Bank ::menu()
{
    int choice;
    char temp;
    details();
    cout << "1. Check Account Balance " << endl;
    cout << "2. Add Money " << endl;
    cout << "3. Withdrawl Money " << endl;
    cout << "4. Money Transfer " << endl;
    cout << "5. Exit" << endl;
    cout << "Choice(1-5): ";
    cin >> choice;
    funcSwitcher(choice);

    getchar();
    cin >> temp;
}
void Bank::newAccount()
{
    std::string name, gender, panNo, address, dob;
    int aadharNo, age;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\t \t Hey there, so you're new to here :-)  " << endl;
    std::cout << "\t Don't worry we'll make opening an account is just one tap work " << endl;
    std::cout << std::endl;
    std::cout << " Fill up the following details and you're ready to go -> -> -> ->  " << endl;
    std::cout << endl;
    std::cout << endl;

    getchar();
    std::cout << "Name: ";
    getline(cin, name);

    std::cout << "Age: ";
    std::cin >> age;

    std::cout << "Gender: ";
    std::cin >> gender;

    std::cout << "Date Of Birth(dd-mm-year): ";
    std::cin >> dob;

    std::cout << "PAN Card number: ";
    std::cin >> panNo;

    std::cout << "Aadhar Card number: ";
    std::cin >> aadharNo;

    getchar();
    std::cout << "Address: ";
    getline(cin, address);

    setData(name, age, gender, aadharNo, panNo, address, dob);

    accountNumber = currentAccount;
    menu();
    currentAccount++;
}
void Bank ::details()
{
    std::cout << " -------------------------------------------------------------" << endl;
    std::cout << "|Account Number: " << this->accountNumber << endl;
    Person ::printDetails();
    std::cout << "-------------------------------------------------------------- " << endl;
}
void Bank ::list()
{
    std::cout << " list function to get the details of all existing user " << endl;
}
void Bank ::edit()
{
    std::cout << " Edit function to edit the exisiting user data " << endl;
}
void Bank ::transction()
{
    std::cout << " Transaction function for making transaction existing user " << endl;
}
void Bank ::erase()
{
    std::cout << " Erase function for existing user " << endl;
}
int Bank ::check(int accountNumber)
{
    if (accountObjectPairs.find(accountNumber) != accountObjectPairs.end())
    {
        int obj = accountObjectPairs[accountNumber];
        return obj;
    }
    return -1;
}
void Bank ::funcSwitcher(int choice)
{
    int amount = 0, accountNum;
    switch (choice)
    {
    case 1:
        viewBalance();
        break;
    case 2:
        std::cout << "Enter Amount to be Added: ";
        cin >> amount;
        addMoney(amount);
        break;
    case 3:
        std::cout << "Enter Amount to be Withdrawl: ";
        cin >> amount;
        std::cout << endl;
        if (withdrawlAmount(amount) == false)
        {
            cout << "Sorry you do not have a sufficient Account Balance!!!!" << endl;
        }
        break;
    case 4:
        std::cout << "***** ONLINE FUND TRANSFER *****" << endl;
        std::cout << "Enter Account Number: ";
        std::cin >> accountNum;
        if (fundTransfer(accountNum) == false)
        {
            std::cout << "Sorry we are unable to initiate your transaction !!! " << endl;
        }
        else
        {
            std::cout << "Your fund has been transfere sucessfully " << endl;
        }

        break;
    default:
        break;
    }
}
void Bank ::addAccount(int objectNumber)
{
    accountObjectPairs.insert({this->accountNumber, objectNumber});
}
void Bank ::viewBalance()
{
    cout << "Account Balance: " << accountBalance << endl;
}
void Bank::addMoney(int amount)
{
    accountBalance += amount;
}
bool Bank ::withdrawlAmount(int amount)
{
    if (amount <= accountBalance)
    {
        accountBalance -= amount;
        return true;
    }
    return false;
}
bool Bank ::fundTransfer(int accountNum)
{
    if (check(accountNum) == -1)
    {
        return false;
    }
    int objNo = accountObjectPairs[accountNum];
}