#ifndef _ADMIN_H  
#define _ADMIN_H
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Person.h"
using namespace std;

//Admin Class Declaration
class Admin : public Person //Inheriting from Person class
{
private:
    int adminID;

public:
    Admin() : Person(){}; //Default constructor
    Admin(int id) : adminID(id), Person("admin", "admin", "admin1", "admin1") {} //1st Admin constructor
    Admin(int id, string fn, string ln, string un, string pd) : adminID(id), Person(fn, ln, un, pd) {} //Non-Default constructor

    // getters and setters function prototypes
    string getAdminUsername();

    string getAdminPass();

    string getAdminFN();

    string getAdminLN();

    int getAdminID();

};
#endif