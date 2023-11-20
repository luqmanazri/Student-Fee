#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

// Student class declaration.
class Student
{
	private:
		string name;        // The Student's Name
		string gender;		// Gender
		int matricNumber;   // Matric Number
		string course;  	// Course Name
		int semester;    	// Semester 


	public:
		// Overloading Constructor
		// Constructors
		Student();		// Default constructor
		Student(string, string, int, string, int);	
		~Student();		// Destructor


		// Mutator functions
   		void setName(string);
   		void setGender(string);
   		void setMatricNumber(int);
   		void setCourse(string);
   		void setSemester(int);


		// Accessor functions
		string getName()const;
		string getGender()const;
		int getMatricNumber()const;
		string getCourse()const;
		int getSemester()const;
	
	
		// Function Prototype to display student information
		void displayStudentInfo()const;
		
};




//*******************************************************************
// Constructor #1 initializes name, gender, course to empty string	*
// and matricNumber and semester to 0.								*
//*******************************************************************

// Constructor #1 (Default Constructor) 
Student::Student()
{
	name = "";
	gender = "";
	matricNumber = 0;
	course = "";
	semester = 0;
}


//*******************************************************************
// Constructor #2 assign values to name, gender, matricNumber, 		*
// course and semester.												*				
//*******************************************************************

// Constructor #2 
Student::Student(string n, string g, int m, string c, int s)
{
	this->name = n;
	this->gender = g;
	this->matricNumber = m;
	this->course = c;
	this->semester = s;
}


//*******************************************************************
// Constructor #3 set values to name, gender, matricNumber, 		*
// course and semester when object is destroyed.					*				
//*******************************************************************

// Constructor #3 (Destructor) 
Student::~Student()
{
	//set value when object destroyed
	name = "";
	gender = "";
	matricNumber = 0;
	course = "";
	semester = 0;
	
}


// Mutator functions
		
//*******************************************************************
// setName assigns a value to the name member.                      *
//*******************************************************************
void Student::setName(string n)
{ 
	this->name  = n; 
}
      	
//*******************************************************************
// setGender assigns a value to the gender member.				    *
//*******************************************************************
void Student::setGender(string g)
{ 
	this->gender = g; 
}
      
//*******************************************************************
// setMatricNumber assigns a value to the matricNumber member.      *
//*******************************************************************
void Student::setMatricNumber(int m)
{
	this->matricNumber = m; 
}
      
//*******************************************************************
// setCourse assigns a value to the course member.      			*
//*******************************************************************
void Student::setCourse(string c)
{
	this->course  = c; 
}
      
//*******************************************************************
// setSemester assigns a value to the semester member.      		*
//*******************************************************************
void Student::setSemester(int s)
{
	this-> semester = s; 
}


		
// Accessor functions
		
//*******************************************************************
// getName returns the value in the name member.      				*
//*******************************************************************
string Student::getName()const
{
	return name; 
}
      
//*******************************************************************
// getGender returns the value in the gender member.      			*
//*******************************************************************
string Student::getGender()const
{
	return gender; 
}
      
//*******************************************************************
// getMatricNumber returns the value in the matricNumber member.    *
//*******************************************************************
int Student::getMatricNumber()const
{
	return matricNumber; 
}

//*******************************************************************
// getCourse returns the value in the course member.   				*
//*******************************************************************
string Student::getCourse()const
{ 
	return course; 
}
      
//*******************************************************************
// getSemester returns the value in the semester member.    		*
//*******************************************************************
int Student::getSemester()const
{
	return semester; 
}



//********************************************************
// Function displayStudentInfo.                          *
// Displays all the student information.         		 *
//********************************************************

void Student::displayStudentInfo()const
{
	cout<< left;
	cout<< setw(25) << " Name :" << getName() <<endl;
	cout<< setw(25) << " Gender :" << getGender() <<endl;
	cout<< setw(25) << " Matric Number :" << getMatricNumber() <<endl;
	cout<< setw(25) << " Student's School :" << getCourse() <<endl;
	cout<< setw(25) << " Semester Registered :" << getSemester() <<endl;
	
}

#endif
