/*
	* This program is developed to manage the system of university fee for four courses
	* Program: University Billing System
	* Developer:	FATIN SHAHIRAH BINTI SHARIFUDDIN 
					LUQMAN AZRI BIN AZMAN 
					NURULAIN BINTI HAMZAH 
*/


#include <iostream>
#include <fstream>
#include <string>
#include "UniversityCost.h"
using namespace std;


//*******************************************************************
// Function main   													*
//*******************************************************************

int main()
{
	// Variable and Constant Declaration
	const int NUM_COURSE = 4;	// to hold the number of courses
	string name,    	// to hold students' name
		   course, 		// to hold course name
		   gender;  	// to hold gender
	const string courseArr[NUM_COURSE] = {"COMPUTER SCIENCE", "EDUCATION STUDIES", "MEDICAL SCIENCES", "CIVIL ENGINEERING"}; //array for courses name
	int matricNumber, 	// to hold matric number
		semester, 		// to hold semester
		numStudents[NUM_COURSE] = {0, 0, 0, 0},  // array for initialize number of students for each course
		index[NUM_COURSE] = {0, 0, 0, 0};  		// array for initialize number of courses
		

	double registerFee,  	// to hold registeration fee
		facilityFee,  		// to hold facilities fee
		desasiswaFee,    	// to hold room fee
		graduationFee,  	// to hold graduation fee
		totalFee,   		// to hold total fee
	    total;				//to hold total for total fee in R university
	const double fee[NUM_COURSE] = {660.0, 550.0, 850.0, 700.0}; // array for course fee (tuition fee)
	bool paidFee;  			// to hold paid fee status
	bool validity = true;  	// to hold validity
	
	
	ifstream myFile;  // declare myFile
	myFile.open("studentFile.txt");  // to open file
	
	if(myFile) // to check availability of file
	{
		
		while (myFile)  
		{
			// read file
			getline(myFile, name, '\t');
			getline(myFile, gender, '\t');
			myFile >> matricNumber;
			myFile.ignore();
			getline(myFile, course, '\t');
	    	myFile >> semester;
	    	myFile >> registerFee;
	    	myFile >> facilityFee;
	    	myFile >> desasiswaFee;
	    	myFile >> graduationFee;
	    	myFile >> paidFee;
			myFile.ignore();
			
			
		   	// check validity for numerical data in the student file 	
			if(matricNumber < 0 || (semester < 0 ||semester> 8 )|| (registerFee < 0.0 || registerFee > 1.0 )|| (facilityFee < 0.0 || facilityFee > 1.0) ||
		   		(desasiswaFee < 0.0 || desasiswaFee > 1.0) || ( graduationFee < 0.0 || graduationFee > 1.0) || (paidFee < 0.0 || paidFee >1.0 ) )
			{
				validity = false;
			}
		    
		    // to  determine number of student in Computer Science course 
			if(course == courseArr[0])
			{
				numStudents[0]++;
				
			}
		    
		    // to  determine number of student in Education Studies course
			else if(course == courseArr[1])
			{
				numStudents[1]++;
			}
		    
		    // to  determine number of student in Medical Sciences course
			else if(course == courseArr[2])
			{
				numStudents[2]++;
			}
		    
		    // to  determine number of student in Civil Engineering course
			else if(course == courseArr[3])
			{
				numStudents[3]++;
			}
		    
		
			else // for course  that not include in the file
			{
				validity = false;
			}
	
		}
	
		if(validity) // condition when file is valid
		{
			// to store number of student in each course
			UniversityCost studentObj[NUM_COURSE] = {numStudents[0], numStudents[1], numStudents[2], numStudents[3]};
		    
		    // loop for course name & course fee
			for(int i = 0; i < NUM_COURSE; i++)
			{
				studentObj[i].setName(courseArr[i]);  
				studentObj[i].setCourseFee(fee[i]);
			}
	
		    // read the file from the beginning
			myFile.clear();
			myFile.seekg(0, ios::beg);
		
		
			while (myFile)
			{
				//read file
				getline(myFile, name, '\t');
				getline(myFile, gender, '\t');
				myFile >> matricNumber;
				myFile.ignore();
				getline(myFile, course, '\t');
		    	myFile >> semester;
		    	myFile >> registerFee;
		    	myFile >> facilityFee;
		    	myFile >> desasiswaFee;
		    	myFile >> graduationFee;
		    	myFile >> paidFee;
				myFile.ignore();
			
			    // loop to determine student fee
				for(int i = 0; i < NUM_COURSE; i++)
				{
					if(course == courseArr[i])
					{
						//array to store name, gender, matricNumber, course, semester, registerFee, 
                        // facilityFee,  desasiswaFee, graduationFee, totalFee, paidFee for each student
                    	studentObj[i].setStudentInfo(index[i]++,name,gender,  matricNumber,  course, semester, registerFee, 
                                      facilityFee,  desasiswaFee,  graduationFee, paidFee);  // function from class UniversityCost
                    
                    
					}
				}
			
			}
			
			// display header of students' fee record
			cout << " ----------------------------------------------------" << endl<<endl;
			cout << " R UNIVERSITY STUDENTS' FEE RECORD FOR SESSION 2022" << endl << endl;
			cout << " ----------------------------------------------------" << endl<< endl;
			
			cout << " Student information of 4 courses in this university: " << endl << endl;
			
			
			// loop to display student information for each course
			for(int i = 0; i < NUM_COURSE ; i++)
			{
				studentObj[i].displayStudentInfo(); // function from class Student
			}
			
			// loop to display total fees for each course 
			for(int i = 0; i < NUM_COURSE ; i++)
			{
				
				cout << " The total fees for " << studentObj[i].getName() << " : RM " << studentObj[i].getTotalStudentFee() << endl;
				total += studentObj[i].getTotalStudentFee();
			}
			
			
			// loop to display total fees accrued for the 2022 session at R University
			cout <<"----------------------------------------------------------------------" << endl;
			cout << " Total fees accrued for the 2022 session at R University: RM " << total << endl; 
			cout <<"----------------------------------------------------------------------" << endl;
			cout << endl << endl;
		

		}
	
		else // display message if information on file not valid
		{
			cout << "Error! Data in the file are not valid. " << endl;
		}
		
		myFile.clear();
	}
	
	else  // display message if the file is failed to open
	{
		cout << "Error! Failed to open the file. " << endl;
	}
		

	
	myFile.close(); // to close file
	
	return 0;		
}
