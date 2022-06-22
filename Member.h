#ifndef _MEMBER_H
#define _MEMBER_H
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Person.h"
using namespace std;


//Member class declaration
class Member : public Person
{
private:
    int memberID;

public:
    Member() : Person() {} //Default constructor

    Member(int id, string fn, string ln, string un, string pd) : memberID(id), Person(fn, ln, un, pd) {} //Non-default constructor
   
    // getters and setters
    string getMemberUsername();
    
    string getMemberPass();
 
    int getMemberID();
 
    string getMemberFN();

    string getmemberLN();

};

#endif