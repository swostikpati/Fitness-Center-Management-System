#ifndef _FITNESSCLASS_H 
#define _FITNESSCLASS_H
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

//Fitness Class Declaration
class FitnessClass
{
private:
    int classID;
    string classN;
    string classDate;
    string classTime;
    int maxCap;
    int currCap = 0;
    int roomN;
    int *memberList;

public:
    //Declaring classes as Friends
    friend class Admin;

    friend class Member;

    FitnessClass() {} //Default constructor

    FitnessClass(int id, string cn, string cd, string ct, int cap, int rno); //Non-default constructor

    //Important Function Declarations
    void addMemberToClass(int mID);

    void removeMemberFromClass(int mID);

    void printClassInfo();

    // getters and setters prototypes
    int getClassID();

    void setClassName(string cn);

    void setClassCap(int cap);

    void setClassRoom(int rno);

    void setClassTime(string ct);

    void setClassDate(string cd);

    int getCurrCap();

    int getMaxCap();

    string getClassName();

    string getClassDate();

    string getClassTime();

    int getClassRno();
};

#endif