#include <iostream>
#include "Student.h"
#include <fstream> 
#include <conio.h>

using namespace std;
void recordStudent (string,string,string, int, float, string);



Student::Student ()
{
	assignedFlag = "0";
}
void Student::createStudent ()
{	
	cout << "************** \nCREATE STUDENT \n**************" << endl;
	cout << "Please enter the first name of the student:"; cin >> firstName;
	cout << "Please enter the last name of the student:"; cin >> lastName;
	cout << "Please enter the ID of the student:"; cin >> studentId;
	cout << "Please enter the year of studying:"; cin >> year;
	
	while (year < 1 || year > 4)
	{
		cout << "**************************************\nERROR: Wrong year value for student:" << year << "\n**************************************\n\n";
		cout << "Please enter the year of studying:"; cin >> year;
	}
	
	cout << "Please enter the Grade Point Average:"; cin >> GPA;
	
	while (GPA <0 || GPA > 4)
	{
		cout << "**************************************\n"
				<<"ERROR: Wrong GPA value for student: "<< GPA
				<<"**************************************\n\n";
		cout << "Please enter the Grade Point Average:"; cin >> GPA;
	}
	recordStudent (firstName, lastName, studentId, year, GPA, assignedFlag);
	
	cout <<"\n\nA student is Created.. ";
	cout <<"\n\nPress any key to Main Menu . .";
	getch();
	
	
}

void Student::showStudentsDetails ()
{
	ifstream StudentInfo;
	string name, surname, id;
	int year;
	float gpa;
	 
	 cout <<"\t\t\t\t\t\t\t\t\t~~~~~Students List~~~~~\n\n\n\n";
	 cout <<"\tIdentification Number\t\tName\t\tSurname\t\tYear\t\tGrade Point Average\t\tAdvisor\n\n";
	 
		StudentInfo.open("StudentInfo.txt", ios::in);
        for (int numbers = 1; !StudentInfo.eof() == 1; numbers++)
        {
        	StudentInfo >> name >>surname >> id >> year >> gpa >> assignedFlag;
            if (StudentInfo.eof()) break;
            
        cout<<numbers <<")\t  "<<name<<"\t\t\t"<<surname<<"\t\t"<<id<<"\t\t" <<year<<"\t\t"<<gpa<< "\t\t\t\t"<<assignedFlag<<"\n"<<endl;
     	}
     	StudentInfo.close();
     	
    cout <<"\n\nPress any key to Main Menu . .";
	getch();
} 
void Student::showStudentDetails ()
{
	ifstream StudentInfo;
	string Id;
	string s_Id;
	string name, surname, id;
	int year;
	float gpa;
	
	cout <<"Enter the Student ID that You want to see Student's Details : " ; cin >> Id;
	cout << "\n\n";
	StudentInfo.open("StudentInfo.txt", ios::in);
    while ( !StudentInfo.eof() == 1 )
    {
    	StudentInfo >> id;
    	if (Id == id) break;    
    }
    for (int numbers = 1; !StudentInfo.eof() == 1 || numbers < 5; numbers++)
    {
        StudentInfo >>name >> surname >> year >> gpa >> assignedFlag;
        cout << "\n\n**************************************\n"
        "STUDENT NAME : " << name<<endl; 
        cout << "STUDENT LASTNAME : "<<surname<<endl; 
        cout << "STUDENT ID : "<<Id<<endl; 
        cout << "YEAR : "<<year<<endl; 
        cout << "GPA : " << gpa <<endl;
        if (assignedFlag == "0")
        {
        	cout << "ADVISOR : There is not an Advisor Yet"  <<endl;
		}
        currentStatus ();
        break;
        
    }
     	
    StudentInfo.close();
   	cout <<"\n\nPress any key to Main Menu . .";
	getch();
}
bool Student::isSuccessful ()
{
    if (GPA >= 2.5)
		return true;
    else 
		return false;
}

void Student::currentStatus ()
{
    if (isSuccessful() == true)
        cout << "STUDENT: " << firstName << " " << lastName << "SUCCESSFUL" << endl;
    else 
        cout << "STUDENT: " << firstName << " " << lastName << "NOT SUCCESSFUL" << endl;
        
    cout << "**************************************\n";
}
