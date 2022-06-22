#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "myfunctions.h"
#include "Admin.h"
#include "Person.h"
#include "Member.h"
#include "FitnessClass.h"
using namespace std;

#define max_admin 100
#define max_member 100
#define max_class 100

// Login Function
void login(Admin **adminArr, Member **memberArr, FitnessClass **classArr, bool &mL, bool &aL, int &mID)
{
    string s;
    cout << "Welcome to the Fitness management System!" << endl;
    while (true)
    {
        cout << "Please enter category of account before logging in: [admin/member]" << endl;
        cin >> s;

        if (s == "admin")
        {
            if (checkAdmin(adminArr)) // checks admin Credentials
            {
                cout << "You have logged in successfully!" << endl;
                aL = true; // flag used to identify if admin is logged in or not
                break;
            }
            else
            {
                cout << "Wrong Credentials! Try again." << endl;
            }
        }
        else if (s == "member") // checks member credentials
        {
            if (checkMember(memberArr, mID))
            {
                cout << "You have logged in successfully!" << endl;
                mL = true; // flag used to identify if member is logged in or not

                break;
            }
            else
            {
                cout << "Wrong Credentials! Try again." << endl;
            }
        }
        // if the user enters something other than "admin" or "member"
        else
        {
            cout << "ERROR! Please enter a valid input." << endl;
        }
    }
}

// Checks the credentials of an admin
bool checkAdmin(Admin **adminArr)
{
    string u, p;
    cout << "Please enter your username:" << endl;
    cin >> u;
    cout << "Please enter your password:" << endl;
    cin >> p;
    bool flag = false;
    for (int i = 0; i < max_admin; i++)
    {
        if (adminArr[i] == NULL)
        {
            break;
        }
        if ((adminArr[i]->getAdminUsername()) == u && (adminArr[i]->getAdminPass()) == p)
        {
            flag = true; // Denotes credentials are true
            break;
        }
    }

    return flag;
}

// Checks the credentitals of an member
bool checkMember(Member **memberArr, int &mID)
{
    string u, p;
    cout << "Please enter your username:" << endl;
    cin >> u;
    cout << "Please enter your password:" << endl;
    cin >> p;
    bool flag = false;
    for (int i = 0; i < max_member; i++)
    {
        if (memberArr[i] == NULL)
        {
            break;
        }
        if ((memberArr[i]->getMemberUsername()) == u && (memberArr[i]->getMemberPass()) == p)
        {
            mID = memberArr[i]->getMemberID();
            flag = true; // Denotes credentials are true
            break;
        }
    }

    return flag;
}

// Registers member
Member registerMember(Member **memberArr)
{
    string fn, ln;
    cout << "Please provide the first name of the member" << endl;
    cin >> fn;
    cout << "Please provide the last name of the member" << endl;
    cin >> ln;

    srand(time(0)); // randomizes seed
    int mID;
    //checks if member ID is unique or not
    bool unique = true; 
    do
    {
        unique = false;
        mID = rand() % 9000 + 1000;
        for (int i = 0; i < max_member; i++)
        {
            if (memberArr[i] != NULL && memberArr[i]->getMemberID() == mID)
            {
                unique = true;
                break;
            }
        }

    } while (unique);

    string uName = "";
    for (int i = 0; i < fn.length(); i++)
    {
        uName += tolower(fn[i]);
    }
    uName += to_string(mID);

    int randNo = rand() % 9000 + 1000;
    string pwd = "";
    for (int i = 0; i < ln.length(); i++)
    {
        pwd += tolower(ln[i]);
    }
    pwd += to_string(randNo);
    Member newMember(mID, fn, ln, uName, pwd);
    cout << "The member is registered successfully! \nThe credentials are as follows:" << endl;
    cout << "Member ID, Username, Password: " << mID << ", " << uName << ", " << pwd << endl;
    return newMember;
}

Admin registerAdmin(Admin **adminArr)
{
    srand(time(0));
    string fn, ln;
    cout << "Please provide the first name of the admin" << endl;
    cin >> fn;
    cout << "Please provide the last name of the admin" << endl;
    cin >> ln;

    int aID; 
    bool unique = true; 
    //checks if the admin ID is unique or not
    do
    {
        unique = false;
        aID = rand() % 9000 + 1000;
        for (int i = 0; i < max_admin; i++)
        {
            if (adminArr[i] != NULL && adminArr[i]->getAdminID() == aID)
            {
                unique = true;
                break;
            }
        }

    } while (unique);

    string uName = "";
    for (int i = 0; i < fn.length(); i++)
    {
        uName += tolower(fn[i]);
    }
    uName += to_string(aID);

    int randNo = rand() % 9000 + 1000;
    string pwd = "";
    for (int i = 0; i < ln.length(); i++)
    {
        pwd += tolower(ln[i]);
    }
    pwd += to_string(randNo);
    Admin newAdmin(aID, fn, ln, uName, pwd);
    cout << "The admin is registered successfully! \nThe credentials are as follows:" << endl;
    cout << "Admin ID, Username, Password: " << aID << ", " << uName << ", " << pwd << endl;
    return newAdmin;
}

//Takes the details about the Fitness Class 
FitnessClass addFitnessClass(FitnessClass **classArr)
{
    int id, cap, rno;
    string cn, cd, ct;
    cout << "Please provide the following:" << endl;
    cout << "Class ID:" << endl;
    cin >> id;
    cout << "Class Name:" << endl;
    cin >> cn;
    cout << "Class Date:" << endl;
    cin >> cd;
    cout << "Class Time:" << endl;
    cin >> ct;
    cout << "Maximum Capacity:" << endl;
    cin >> cap;
    cout << "Room Number:" << endl;
    cin >> rno;
    FitnessClass newFitnessClass(id, cn, cd, ct, cap, rno);
    cout << "Fitness Class Added Successfully!" << endl;
    return newFitnessClass;
}
//Checks if fitness class is present or not
int findClassByID(FitnessClass **classArr, int id)
{
    int i(0);
    while (classArr[i] != NULL)
    {
        if (id == classArr[i]->getClassID())
        {
            return i;
        }
        i++;
    }
    return -1;
}

//Deletes Fitness Class
void deleteFitnessClass(FitnessClass **classArr, int id)
{
    int index = findClassByID(classArr, id);
    if (index != -1)
    {
        delete classArr[index]; //deletes the class
        classArr[index] = NULL; //makes it point to NULL
        cout << "Class Deleted!" << endl;
    }
    else
    {
        cout << "Class Not Found!" << endl;
    }
}

//Updates class details
void updateClassDetails(FitnessClass **classArr, int id)
{
    int index = findClassByID(classArr, id);
    if (index != -1)
    {
        cout << "What do you want to update?" << endl;
        cout << "1. Class Name \n2. Class Capacity \n3. Class Room Number \n4. Class Date \n5. Class Time" << endl;
        cout << "Enter the number of the required action: [1-5]" << endl;
        char o;
        cin >> o;

        switch (o)
        {
        case '1':
        {
            string cn;
            cout << "Enter the new class name:" << endl;
            cin >> cn;
            classArr[index]->setClassName(cn);
            cout << "Name Updated!" << endl;
            break;
        }
        case '2':
        {
            int cap;
            cout << "Enter the new class capacity:" << endl;
            cin >> cap;
            classArr[index]->setClassCap(cap);
            cout << "Capacity Updated!" << endl;
            break;
        }
        case '3':
        {
            int rno;
            cout << "Enter the new class room number" << endl;
            cin >> rno;
            classArr[index]->setClassRoom(rno);
            cout << "Room number updated!" << endl;
            break;
        }
        case '4':
        {
            string cd;
            cout << "Enter the new class date" << endl;
            cin >> cd;
            classArr[index]->setClassDate(cd);
            cout << "Class date updated!" << endl;
            break;
        }
        case '5':
        {
            string ct;
            cout << "Enter the new class time" << endl;
            cin >> ct;
            classArr[index]->setClassTime(ct);
            cout << "Class time updated!" << endl;
            break;
        }
        default:
            cout << "Invalid Selection!" << endl;
            break;
        }
    }
    else
    {
        cout << "Class Not Found!" << endl;
    }
}

//Books a class
void bookAClass(FitnessClass **classArr, int id, int mID)
{
    int index = findClassByID(classArr, id);
    if (index != -1)
    {
        if (classArr[index]->getCurrCap() < classArr[index]->getMaxCap()) //checks if there is space in class
        {
            classArr[index]->addMemberToClass(mID);
            cout << "Class Booked" << endl;
        }
    }
    else
    {
        cout << "Class Not Found" << endl;
    }
}

//Prints details about classes with vacancies
void viewClassesWithVacancies(FitnessClass **classArr)
{
    for (int i = 0; i < max_class; i++)
    {

        if (classArr[i] != NULL)
        {
            if (classArr[i]->getCurrCap() < classArr[i]->getMaxCap()) //Checls if there is space in the calss
            {
                classArr[i]->printClassInfo();
            }
        }
    }
}

//Cancels booking of member
void cancelBooking(FitnessClass **classArr, int id, int mID)
{
    int index = findClassByID(classArr, id);
    if (index != -1)
    {
        classArr[index]->removeMemberFromClass(mID);
        cout << "Booking cancelled" << endl;
    }
    else
    {
        cout << "Class Not Found" << endl;
    }
}

//Saves all the details in separate files and exits the program
void quitProgram(Admin **adminArr, Member **memberArr, FitnessClass **classArr)
{

    ofstream classFile;
    classFile.open("FitnessClassesTable.txt", ios::out);
    if (classFile.fail())
    {
        cout << "Error Opening File" << endl;
        exit(1);
    }
    ofstream adminFile;
    adminFile.open("AdminsTable.txt", ios::out);
    if (adminFile.fail())
    {
        cout << "Error Opening File" << endl;
        exit(1);
    }
    ofstream memberFile;
    memberFile.open("MembersTable.txt", ios::out);
    if (memberFile.fail())
    {
        cout << "Error Opening File" << endl;
        exit(1);
    }
    int i(0);
    while (adminArr[i] != NULL)
    {
        adminFile << adminArr[i]->getAdminID() << "," << adminArr[i]->getAdminFN() << "," << adminArr[i]->getAdminLN() << "," << adminArr[i]->getAdminUsername() << "," << adminArr[i]->getAdminPass() << endl;
        delete adminArr[i];
        i++;
    }
    i = 0;
    while (memberArr[i] != NULL)
    {
        memberFile << memberArr[i]->getMemberID() << "," << memberArr[i]->getMemberFN() << "," << memberArr[i]->getmemberLN() << "," << memberArr[i]->getMemberUsername() << "," << memberArr[i]->getMemberPass() << endl;
        delete memberArr[i];
        i++;
    }

    for (int i = 0; i < max_class; i++)
    {
        if (classArr[i] != NULL)
        {
            classFile << classArr[i]->getClassID() << "," << classArr[i]->getClassName() << "," << classArr[i]->getClassDate() << "," << classArr[i]->getClassTime() << "," << classArr[i]->getMaxCap() << "," << classArr[i]->getClassRno() << endl;
            delete classArr[i];
        }
    }
    cout << "Thank you Exited!" << endl;
    adminFile.close();
    memberFile.close();
    classFile.close();
    exit(0);
}
