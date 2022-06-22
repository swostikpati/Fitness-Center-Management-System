#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Person.h"
#include "Admin.h"
#include "Member.h"
#include "FitnessClass.h"
#include "myfunctions.h"
using namespace std;

//Defining maximum limit of arrays
#define max_admin 100
#define max_member 100
#define max_class 100


int main()
{
    //Creating first admin
    Admin adm(1);
    Admin *adminArr[max_admin]; //declaring array of admin pointer objects
    for (int i = 0; i < max_admin; i++)
    {
        adminArr[i] = NULL; //initializing them to NULL
    }

    adminArr[0] = &adm; //storing the first admin

    Member *memberArr[max_member]; //declaring array of member pointer objects
    for (int i = 0; i < max_member; i++)
    {
        memberArr[i] = NULL; //initializing them to NULL
    }

    FitnessClass *classArr[max_class]; //declaring array of admin pointer objects
    for (int i = 0; i < max_class; i++)
    {
        classArr[i] = NULL; //initializing them to NULL
    }

    bool mL(false), aL(false); //to check whether admin or member is logged in
    int mID; 
    login(adminArr, memberArr, classArr, mL, aL, mID);

    if (aL)
    {
        //Menu for Admins
        char n;
        cout << "The list of available operations for Admins:" << endl;
        cout << " 1) Register a new Admin \n 2) Register a new member \n 3) Add a fitness class \n 4) Delete a fitness class \n 5) Update the details of a fitness class \n 6) Display the classes with vacancies \n 7) Logout \n 8) Quit" << endl;
        do
        {
            cout << "Enter the number of the required action: [1-8]" << endl;
            cin >> n;
            switch (n)
            {
            case '1':
            {
                Admin tempA = registerAdmin(adminArr);
                int index = indexNext(adminArr);
                adminArr[index] = new Admin;
                *(adminArr[index]) = tempA;

                break;
            }
            case '2':
            {
                Member tempM = registerMember(memberArr);
                int index = indexNext(memberArr);
                memberArr[index] = new Member;
                *(memberArr[index]) = tempM;

                break;
            }
            case '3':
            {
                FitnessClass tempC = addFitnessClass(classArr);
                int index = indexNext(classArr);
                classArr[index] = new FitnessClass;
                *(classArr[index]) = tempC;
                break;
            }
            case '4':

            {
                int id;
                cout << "Please provide the Class ID: " << endl;
                cin >> id;
                deleteFitnessClass(classArr, id);
                break;
            }
            case '5':
            {
                int id;
                cout << "Please provide the Class ID: " << endl;
                cin >> id;
                updateClassDetails(classArr, id);
                break;
            }
            case '6':
            {
                viewClassesWithVacancies(classArr);
                break;
            }
            case '7':
            {
                aL = false;
                mL = false;
                login(adminArr, memberArr, classArr, mL, aL, mID);
                break;
            }
            case '8':
            {
                quitProgram(adminArr, memberArr, classArr);
                break;
            }
            default:
            {
                cout << "ERROR! Please select a valid option" << endl;
                break;
            }
            }

        } while (aL);
    }
    if (mL)
    {
        //Menu for Members
        char n;
        cout << "The list of available operations for Members:" << endl;
        cout << " 1) Book a Fitness Class \n 2) Display Classes with vacancies \n 3) Cancel booking \n 4) Quit" << endl;
        do
        {
            cout << "Enter the number of the required action: [1-4]" << endl;
            cin >> n;
            switch (n)
            {
            case '1':
            {
                int id;
                cout << "Please provide the Class ID of the class you want to book:" << endl;
                cin >> id;
                bookAClass(classArr, id, mID);
                break;
            }
            case '2':
            {
                viewClassesWithVacancies(classArr);
                break;
            }
            case '3':
            {
                int id;
                cout << "Please provide the Class ID of the class you want to cancel:" << endl;
                cin >> id;
                cancelBooking(classArr, id, mID);
                break;
            }
            case '4':
            {
                quitProgram(adminArr, memberArr, classArr);
                break;
            }
            default:
            {
                cout << "ERROR! Please select a valid option" << endl;
                break;
            }
            }

        } while (mL);
    }

    return 0;
}