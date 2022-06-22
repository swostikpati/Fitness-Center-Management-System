#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

//Class definition for Parent class 
class Person
{
protected:
    string firstN;
    string lastN;
    string userN;
    string pswd;

public:
    Person() {}
    Person(string fN, string lN, string uN, string p) : firstN(fN), lastN(lN), userN(uN), pswd(p) {}
};
#endif