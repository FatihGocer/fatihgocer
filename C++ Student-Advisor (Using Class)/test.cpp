#include <iostream>
#include "Student.h"
#include "Advisor.h"
#include <fstream> 
#include <cstdlib>
#include <windows.h>
#include <conio.h>

using namespace std;
void recordAdvisor (string,string,string, int, int);
void recordStudent (string,string,string, int, float, string);
int assignStudentToAdvisor();

int main()
{
	system("COLOR F0");
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //Fullscreen
	int option;
	Student student;
	Advisor advisor;
	
	while (1)
	{
	
	system("CLS");	
	while (1)
	{
	cout <<"\n\n\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB Main Menu \xDB\xDB\xDB\xDB\xDB";
	cout <<"\n\t\t\t\t------------------------------------";
	cout <<"\n\n\t\t\t\t1) Add a Student";
	cout <<"\n\n\t\t\t\t2) Add a advisor";
	cout <<"\n\n\t\t\t\t3) Show students Details";
	cout <<"\n\n\t\t\t\t4) Show student Details (According to ID)";
	cout <<"\n\n\t\t\t\t5) Assign a Student";
	cout <<"\n\n\t\t\t\t6) Exit";
	
	option = getch();
	
	if (option == '1'){
		system("CLS");
		student.createStudent();}
	if (option == '2'){
		system("CLS");
		advisor.createAdvisor();}
	if (option == '3'){
		system("CLS");
		student.showStudentsDetails ();	}
	if (option == '4'){
		system("CLS");
		student.showStudentDetails (); }
	if (option == '5'){
		system("CLS");
		assignStudentToAdvisor ();}
	if (option == '6'){
	}
		return 0;
	}
	}
	return 0;
}
	
void recordAdvisor (string name, string surname, string id, int numberofStudentsAssigned, int allowedStudentCount)
{
	ofstream AdvisorFile;
	
	AdvisorFile.open("AdvisorInfo.txt", ios::app);
	
	AdvisorFile << id << " " 
	<< name << " " 
	<< surname << " "
    << numberofStudentsAssigned << " " 
	<< allowedStudentCount << " "<< endl;
	
    AdvisorFile.close();	
	
}

void recordStudent (string name, string surname, string id, int year, float gpa,string assignedFlag)
{
	ofstream StudentFile;
	
	StudentFile.open("StudentInfo.txt", ios::app);
	
	StudentFile << id << " " 
	<< name << " " 
	<< surname << " "
    << year << " " 
	<< gpa << " "
	<< assignedFlag << endl;
	
    StudentFile.close();	
	
}

int assignStudentToAdvisor()
{
	ifstream StudentInfo;
	ifstream AdvisorInfo;
	string Id, id;
	string name, surname;
	int assignedFlag;
	int numberofStudentsAssigned, allowedStudentCount;
	string choosen_advisor, iter_id_advisor;
	int iter_assign_advisor;
	
	
	int year;
	float gpa;
	
	cout << "Which student do you want to Assign ? : "; cin >> Id ;
	
	StudentInfo.open("StudentInfo.txt", ios::in);
    while ( !StudentInfo.eof() == 1 )
    {
    	StudentInfo >> id;
    	if (Id == id) break;    
    }
    if (Id!= id){
    	cout << "\nThis ID cannot found ! ! !";
    	return 0;
	}
    
	StudentInfo >>name >> surname >> year >> gpa >> assignedFlag;
	if (assignedFlag != 0 )
	{
		cout << "\nThe student has a Advisor ***";
		return 0;
	}
	StudentInfo.close();
	
	cout <<"\n\t\t\t\t~~~~~Advisor List~~~~~\n\n";
	cout <<"\tIdentification Number\t\tName\t\tSurname\t\tCapacity of Assigned\n"
	"___________________________________________________________________________________________________\n\n";
	
	AdvisorInfo.open("AdvisorInfo.txt", ios::in);
        for (int numbers = 1; !AdvisorInfo.eof() == 1; numbers++)
        {
        	AdvisorInfo >> id >> name >> surname >> numberofStudentsAssigned >> allowedStudentCount;
            if (AdvisorInfo.eof()) break;
            
        cout<<numbers <<")\t  "<<id<<"\t\t\t"<<name<<"\t\t"<<surname<<"\t\t" <<numberofStudentsAssigned<<"/"<< allowedStudentCount<<endl;
     	}
     	cout <<"Choose an Advisor and Enter the ID of advisor :  "; cin >> choosen_advisor;
    while ( !AdvisorInfo.eof() == 1 )
    {
    	AdvisorInfo >> iter_id_advisor;
    	if (choosen_advisor == iter_id_advisor) break;    
    }
    
    AdvisorInfo>> name >> surname >> iter_assign_advisor;
    
    if (iter_assign_advisor >= 3)
    {
    	cout << "ERROR: Cannot assign more students to advisor ADVISOR ID: " << choosen_advisor;
    	return 0;
	}
	
	
    
     	
     	
     	
     	
     	
   	AdvisorInfo.close();
	
	
	
}

