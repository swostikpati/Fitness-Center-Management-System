#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "FitnessClass.h"

using namespace std;

//Function Definitions of FitnessClass 
FitnessClass::FitnessClass(int id, string cn, string cd, string ct, int cap, int rno) : classID(id), classN(cn), classDate(cd), classTime(ct), maxCap(cap), roomN(rno)
{
    memberList = new int[cap];
}

void FitnessClass::addMemberToClass(int mID)
{
    memberList[currCap] = mID;
    currCap++;
}

void FitnessClass::removeMemberFromClass(int mID)
{
    //making new dynamic array, copying the contents and then deleting the temporary array
    bool flag = false; //to check if member is present in list
    for (int i = 0; i < currCap; i++)
    {
        if (memberList[i] == mID)
        {
            flag = true;
            int *temp = new int[currCap - 1];
            for (int j = 0; j < i; j++)
            {
                temp[j] = memberList[j];
            }
            for (int k = i; k < currCap - 1; k++)
            {
                temp[k] = memberList[k + 1];
            }
            memberList = temp;
            delete[] temp;
        }
    }
    if (!flag)
    {
        cout << "Member not in Class" << endl;
    }
}

//To print details of a Fitness Class
void FitnessClass::printClassInfo()
{
    cout << "Class Details" << endl;
    cout << "Class ID: " << classID << endl;
    cout << "Class Name: " << classN << endl;
    cout << "Class Date: " << classDate << endl;
    cout << "Class Time: " << classTime << endl;
    cout << "Room Number: " << roomN << endl;
}

//Defining getters and setters
int FitnessClass::getClassID()
{
    return classID;
}

void FitnessClass::setClassName(string cn)
{
    classN = cn;
}
void FitnessClass::setClassCap(int cap)
{
    maxCap = cap;
}
void FitnessClass::setClassRoom(int rno)
{
    roomN = rno;
}
void FitnessClass::setClassTime(string ct)
{
    classTime = ct;
}
void FitnessClass::setClassDate(string cd)
{
    classDate = cd;
}
int FitnessClass::getCurrCap()
{
    return currCap;
}
int FitnessClass::getMaxCap()
{
    return maxCap;
}
string FitnessClass::getClassName()
{
    return classN;
}
string FitnessClass::getClassDate()
{
    return classDate;
}
string FitnessClass::getClassTime()
{
    return classTime;
}
int FitnessClass::getClassRno()
{
    return roomN;
}