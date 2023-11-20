#ifndef UNIVERSITYCOST_H
#define UNIVERSITYCOST_H

#include "Student.h"
#include "Fee.h"

#include <iostream>
#include <string>
using namespace std;


//*****************************************************
// UniversityCost class declaration.  				  *
// Derived Class.									  *	
// Inheritance to Fee class.						  *
//*****************************************************
class UniversityCost : public Fee
{
	private:
		Student *studentObj;  
		int numStudents;		// Number of students
		double *registerFee;	// Points to array of Registeration Fee (for Semester 1 : New Students)
		double *facilityFee;	// Points to array of Facilities Fee
		double *desasiswaFee;	// Points to array of Desasiswa Fee (Students' Accommodation)
		double *graduationFee;	// Points to array of Graduation Fee (for Semester 8 : Last Semester)
		double *totalFee;		// Points to array of Total University Fees need to pay
		double totalStudentFee;
		bool *paidFee;			// Points to array of Payment Status (paid or unpaid)
	
	public:
		// Overloading Constructor
		// Constructors
		UniversityCost();		// Default constructor
		UniversityCost(int);	
		~UniversityCost();		// Destructor
		
		
		// Mutator functions
		void setStudentInfo(int, string, string, int, string, int, double, double, double, double, bool);
		void setPaidFee(int, bool);
		
		
		// Accessor functions
		int getNumStudents()const;
		bool getPaidFee(int)const;
		double getTotalStudentFee()const;
		
		
        // Function Prototype
		void calcRegisterFee(int); 		// to calculate register fee
		void calcFacilityFee(int);  	// to calculate facility fee
		void calcDesasiswaFee(int);     // to calculate room fee
		void calcGraduationFee(int); 	// to calculate graduation fee
		void calcTotalFee(int);      	// to calculate total fee
		void displayStudentInfo()const;	// to display student information
		
		
		// friend function of operator overloading
		friend double operator *(int, UniversityCost&);
};




//*******************************************************************
// Constructor #1 initializes name, gender, course to empty string	*
// and matricNumber and semester to 0.								*
//*******************************************************************

// Constructor #1 (Default Constructor) 
UniversityCost::UniversityCost()
{
	numStudents = 1;
	
	studentObj = new Student[numStudents];
	registerFee = new double[numStudents];
	facilityFee = new double[numStudents];
	desasiswaFee = new double[numStudents];
	graduationFee = new double[numStudents];
	totalFee = new double[numStudents];
	paidFee = new bool[numStudents];
	
	//initialize value
	registerFee[0] = 0.0; 
	facilityFee[0] = 0.0;
	desasiswaFee[0] = 0.0;
	graduationFee[0] = 0.0;
	totalFee[0] = 0.0;
	paidFee[0] = true; 
	
	totalStudentFee = 0.0;
}

//*******************************************************************
// Constructor #2 assign values to name, gender, matricNumber, 		*
// course and semester.												*				
//*******************************************************************

// Constructor #2  
UniversityCost::UniversityCost(int numStudents)
{
	
	this->numStudents = numStudents;
	studentObj = new Student[numStudents];
	registerFee = new double[numStudents];
	facilityFee = new double[numStudents];
	desasiswaFee = new double[numStudents];
	graduationFee = new double[numStudents];
	totalFee = new double[numStudents];
	paidFee = new bool[numStudents];
    
    //loop for get university fee
	for (int i = 0; i < numStudents; i++)
	{
		//initialize value
		registerFee[i] = 0.0;
		facilityFee[i] = 0.0;
		desasiswaFee[i] = 0.0;
		graduationFee[i] = 0.0;
		totalFee[i] = 0.0;
		paidFee[i] = true;
	}
	
	totalStudentFee = 0.0;
}

//*******************************************************************
// Constructor #3 set values to name, gender, matricNumber, 		*
// course and semester when object is destroyed.					*				
//*******************************************************************

// Constructor #3 (Destructor)  
UniversityCost::~UniversityCost()
{
	//total for get university fee
	for (int i = 0; i < numStudents; i++)
	{
		//set value when object destroyed
		registerFee[i] = 0.0;
		facilityFee[i] = 0.0;
		desasiswaFee[i] = 0.0;
		graduationFee[i] = 0.0;
		totalFee[i] = 0.0;
		paidFee[i] = true;
	}
	
	numStudents = 0;
	totalStudentFee = 0.0;
	
	// Deallocate array
	delete [] studentObj;
	delete [] registerFee;
	delete [] facilityFee;
	delete [] desasiswaFee;
	delete [] graduationFee;
	delete [] totalFee;
	delete [] paidFee;
	
}



// Mutator functions

//*******************************************************************
// setStudentInfo to set the student's information.                 *
//*******************************************************************
void UniversityCost::setStudentInfo(int index, string name, string gender, int matricNumber, string course, int semester, double registerFee, 
                                     double facilityFee, double desasiswaFee, double graduationFee, bool paidFee)
{
	// Set Value for variable
	studentObj[index].setName(name); 
	studentObj[index].setGender(gender);
	studentObj[index].setMatricNumber(matricNumber);
	studentObj[index].setCourse(course);
	studentObj[index].setSemester(semester);
	
	this->paidFee[index] = paidFee;
	this->registerFee[index] = registerFee;
	this->facilityFee[index] = facilityFee;
	this->desasiswaFee[index] = desasiswaFee;
	this->graduationFee[index] = graduationFee;

	// Function call to Calculate Fees
	calcRegisterFee (index);  
	calcFacilityFee (index);
	calcDesasiswaFee (index);
	calcGraduationFee (index);
	calcTotalFee(index);
	
	totalStudentFee =  totalFee[index] + totalStudentFee;
}

//*******************************************************************
// setPaidFee to set the fee paid.                      *
//*******************************************************************
void UniversityCost::setPaidFee(int index, bool paidFee)
{
	this->paidFee[index] = paidFee;
}


// Accessor functions

//*******************************************************************
// getNumStudents to get number of students.    					*
//*******************************************************************
int UniversityCost::getNumStudents()const
{
	return numStudents;  // to return value to getNumStudents
}

//*******************************************************************
// getPaidFee to get fee paid status.    							*
//*******************************************************************
bool UniversityCost::getPaidFee(int index)const
{
	return paidFee[index];   // to return value to getPaidFee
}

//*******************************************************************
// getTotalStudentFee to get total students' fee for each course.	*
//*******************************************************************
double UniversityCost::getTotalStudentFee()const

{
	return totalStudentFee;
}



//function for register fee
void UniversityCost::calcRegisterFee(int index)
{
     registerFee[index] = registerFee[index] * 750;
	
}


//function for calculate Facility fee
void UniversityCost::calcFacilityFee(int index)
{
	 facilityFee[index] = facilityFee[index] * 550;
}

//function for calculate Desiswa fee
void UniversityCost::calcDesasiswaFee(int index)
{
	 desasiswaFee[index] = desasiswaFee[index] * 600;
}

//function for calculate Graduation fee
void  UniversityCost::calcGraduationFee(int index)
{
    graduationFee[index] = graduationFee[index] * 50;
}

//funtion for calculate Total fee
void UniversityCost::calcTotalFee(int index)
{
	 totalFee[index] = getCourseFee() + registerFee[index] + facilityFee[index] + desasiswaFee[index] + graduationFee[index];
}


//************************************************************
// Function displayStudentInfo.                          	 *
// Displays all the student information with it fees.  	 	 *
//************************************************************
void UniversityCost::displayStudentInfo()const
{
	cout << fixed;
	cout << setprecision(2);  // set for two decimal places
	
	cout << "-----------------------------------------------------" << endl;
	cout << "\t\t" << getName() << endl; // get name for the course
	cout << "-----------------------------------------------------" << endl;
	
	//loop to display student information
	for(int i = 0; i < numStudents ; i++)
	{
		studentObj[i].displayStudentInfo();
		
	
        cout << "\n  List of fee for semester registered" << endl;
        cout << "  ------------------------------------" << endl << endl;
        cout << setw(30) << " Course Fee: " << "RM " << getCourseFee() << endl;
		cout << setw(30) << " Registeration Fee :" << "RM "<< registerFee[i] <<endl;
		cout << setw(30) << " Facility Fee :" << "RM "<< facilityFee[i] <<endl;
		cout << setw(30) << " Desasiswa Fee :" << "RM "<< desasiswaFee[i] <<endl;
		cout << setw(30) << " Graduation Fee :" << "RM "<< graduationFee[i] <<endl;
		
		cout << "-----------------------------------------" << endl;
		cout << setw(30) << " Total Fee: " << "RM" << totalFee[i]<< endl;
		cout << "-----------------------------------------" << endl;
		
		cout << setw(30) << " Status of University Fee :" ;
		
		//loop for the status of fee (paid/unpaid)
		if(paidFee[i] == true)
		{
			cout << "Paid" << endl;	
		}
		else
		{
			cout<< "Unpaid" << endl;
		}
		cout << endl;
		cout << "****************************************************" << endl << endl;

	}
}

// friend function
double operator *(int num, UniversityCost& ob)
{
	return(num *ob.getTotalStudentFee());
}



#endif
