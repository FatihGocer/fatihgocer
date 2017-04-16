#ifndef ADVISOR_H
#define ADVISOR_H

using namespace std;

class Advisor {
	private:
		
		string firstName;
		string lastName;
		string advisorId;
		int numberOfStudentsAssigned;
		int allowedStudentCount;
		int flag ;
		
		
	public:
		Advisor ();
		void createAdvisor();
		
};

#endif
