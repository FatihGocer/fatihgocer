#include <iostream>
#include "Advisor.h"
#include <conio.h>

using namespace std;
void recordAdvisor (string,string,string, int, int);
		
Advisor::Advisor ()
{
	
}
void Advisor::createAdvisor ()
{
	cout << "************** \nCREATE ADVISOR \n **************" << endl;
	cout << "Please enter the first name of the advisor:"; cin >> firstName;
	cout << "Please enter the last name of the advisor:"; cin >> lastName;
	cout << "Please enter the ID of the advisor:"; cin >> advisorId;
	
	numberOfStudentsAssigned = 0;
    allowedStudentCount = 3;
    
	recordAdvisor(firstName, lastName, advisorId, numberOfStudentsAssigned, allowedStudentCount);
	cout <<"\n\nPress any key to Main Menu . .";
	getch();
	
	

	
}
