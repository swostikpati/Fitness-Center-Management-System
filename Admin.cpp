#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Person.h"
#include "Admin.h"
using namespace std;

// getters and setters
string Admin::getAdminUsername()
{
    return userN;
}
string Admin::getAdminPass()
{
    return pswd;
}
string Admin::getAdminFN()
{
    return firstN;
}
string Admin::getAdminLN()
{
    return lastN;
}
int Admin::getAdminID()
{
    return adminID;
}

