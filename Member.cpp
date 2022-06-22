#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Member.h"
#include "Person.h"
using namespace std;

//Getters and setters definitions
string Member::getMemberUsername()
{
    return userN;
}

string Member::getMemberPass()
{
    return pswd;
}

int Member::getMemberID()
{
    return memberID;
}
string Member::getMemberFN()
{
    return firstN;
}
string Member::getmemberLN()
{
    return lastN;
}