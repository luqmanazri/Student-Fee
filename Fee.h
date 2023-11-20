#ifndef FEE_H
#define FEE_H

#include<iostream>
#include<string>

using namespace std;

//*****************************************************
// Fee class declaration.  							  *
// BaseClass										  *	
//*****************************************************
class Fee
{
	private:
		string name;  		// Course's Name
		double courseFee;   // Course Fee
	
	public:
		// Overloading Constructor
		// Constructors
		Fee();		// Default constructor
		Fee(string, double);	
		~Fee();		// Destructor
		
		
		// Mutator functions
		void setName(string);
		void setCourseFee(double);
		

		// Accessor functions
		string getName()const;
		double getCourseFee()const;

};




//*******************************************************************
// Constructor #1 initializes name to empty string and 				*
// courseFee to 0.0.												*
//*******************************************************************

// Constructor #1 (Default Constructor) 

Fee::Fee()
{
	name = ""; //initialize name to empty string
	courseFee = 0.0; // initialize courseFee to 0
}


//*******************************************************************
// Constructor #2 assign values to name and courseFee 				*			
//*******************************************************************

// Constructor #2 
Fee::Fee(string n, double cf)
{
	this->name = n;
	this->courseFee = cf;
}


//*******************************************************************
// Constructor #3 set values to name and courseFee			 		*
// when object is destroyed.										*				
//*******************************************************************

// Constructor #3 (Destructor)
Fee::~Fee()
{
	name = "";  
	courseFee = 0.0;	
}


// Mutator functions
		
//*******************************************************************
// setName assigns a value to the name member.                      *
//*******************************************************************
void Fee::setName(string n)
{ 
	this->name  = n; 
}

//*******************************************************************
// setCourseFee assigns a value to the courseFee member.            *
//*******************************************************************
void Fee::setCourseFee(double cf)
{
	this-> courseFee = cf;
}



// Accessor functions

//*******************************************************************
// getName returns the value in the name member.    				*
//*******************************************************************
string Fee::getName()const
{
	return name;
}

//*******************************************************************
// getCourseFee returns the value in the courseFee member.    		*
//*******************************************************************
double Fee::getCourseFee()const
{
	return courseFee;
}



#endif


