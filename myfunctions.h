#ifndef _MYFUNCTIONS_H
#define _MYFUNCTIONS_H

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Admin.h"
#include "Member.h"
#include "FitnessClass.h"
#include "Person.h"
using namespace std;

//Function Prototypes
bool checkAdmin(Admin **adminArr);

bool checkMember(Member **memberArr, int &mID);

void login(Admin **adminArr, Member **memberArr, FitnessClass **classArr, bool &mL, bool &aL, int &mID);


bool checkAdmin(Admin **adminArr);

bool checkMember(Member **memberArr, int &mID);

//Template function as it can take multiple datatypes
template <typename T>
int indexNext(T arr) //Gives the next index which is empty
{
    int index(0);
    while (arr[index] != NULL)
    {
        index++;
    }
    // index++;
    cout << "Index: " << index << endl;
    return index;
}

Member registerMember(Member **memberArr);


Admin registerAdmin(Admin **adminArr);

FitnessClass addFitnessClass(FitnessClass **classArr);

int findClassByID(FitnessClass **classArr, int id);


void deleteFitnessClass(FitnessClass **classArr, int id);


void updateClassDetails(FitnessClass **classArr, int id);


void bookAClass(FitnessClass **classArr, int id, int mID);


void viewClassesWithVacancies(FitnessClass **classArr);


void cancelBooking(FitnessClass **classArr, int id, int mID);


void quitProgram(Admin **adminArr, Member **memberArr, FitnessClass **classArr);


#endif
