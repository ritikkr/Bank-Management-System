#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    int aadharNo;
    int age;
    std::string dob;
    std::string panNo;
    std::string gender;
    std::string name;
    std::string address;

public:
    void setData(std::string, int, std::string, int, std::string, std::string, std::string);

    /// return person Name
    std::string getName() { return name; }

    /// return person Age
    int getAge() { return age; }

    /// return person Gender
    std::string getGender() { return gender; }

    /// return person Aadhar Number
    int getAadhar() { return aadharNo; }

    /// return person PAN number
    std::string getPan() { return panNo; }

    /// return person Date of Birth
    std::string getDob() { return dob; }

    /// return person Address
    std::string getAddress() { return address; }

    /// print person all details
    void printDetails()
    {
        std::cout << "|Name: " << getName() << endl;
        std::cout << "|Age: " << getAge() << endl;
        std::cout << "|Date Of Birth(dd-mm-yy): " << getDob() << endl;
        std::cout << "|Gender: " << getGender() << endl;
        std::cout << "|Aadhar No: " << getAadhar() << endl;
        std::cout << "|PAN No: " << getPan() << endl;
        std::cout << "|Aadhar No: " << getAadhar() << endl;
        std::cout << "|Address: " << getAddress() << endl;
    }
};

/**
 * function to set data for Person class
 * name - name of a particular person
 * age - age of a particular person
 * gender - gender of a particular person
 * aadharNo - Aadhar card number of particular person
 * panNo - Pan card number of a particular person
 * address - address of particular person
*/
void Person ::setData(std::string name, int age, std::string gender, int aadharNo, std::string panNo, std::string address, std::string dob)
{
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->dob = dob;
    this->aadharNo = aadharNo;
    this->panNo = panNo;
    this->address = address;
}