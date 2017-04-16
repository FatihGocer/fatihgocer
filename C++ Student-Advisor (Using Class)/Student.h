#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student {
	
	public:
		Student();
		void createStudent();
		void showStudentsDetails();
		void showStudentDetails();
		bool isSuccessful ();
		void currentStatus ();
		
		
	private:
		string firstName;
		string lastName;
		string studentId;
		int year;
		float GPA;
		string assignedFlag;
	
	
};

#endif
