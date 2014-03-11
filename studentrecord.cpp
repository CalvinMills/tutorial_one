//MLLCAL002
//Calvin Mills
//Assignment 1
//Due: 10 March 2014

#include "studentrecord.h"


namespace MLLCAL002 {

	//overload output
	ostream& operator<<(ostream& os, const StudentRecord& studentrecord)
	{
		os << studentrecord.Name << "," << studentrecord.Surname << "," <<  studentrecord.StudentNumber << "," << studentrecord.ClassRecord << endl;
		return os;
	}
	//overload input
	istream& operator>>(istream & is, StudentRecord & studentrecord)
	{
		string r;
		getline(is,r,',');
		studentrecord.Name = r;
		getline(is,r,',');
		studentrecord.Surname = r;
		getline(is,r,',');
		studentrecord.StudentNumber = r;
		getline(is,r,'\n');
		studentrecord.ClassRecord = r;
	
		return is;
	}

   //constructor
    StudentRecord::StudentRecord(string name, string surname, string studentnumber, string classRecord, int(token)) : Name (name), Surname (surname), StudentNumber (studentnumber), ClassRecord (classRecord), token(token){}   
    StudentRecord::StudentRecord( void ): Name("Name"), Surname("Surname"), StudentNumber("Student Number"), ClassRecord("Class Record"){}//default constructor	
	//move constructor
    StudentRecord::StudentRecord(StudentRecord && rhs): Name (move(rhs.Name)), Surname (move(rhs.Surname)), StudentNumber (move(rhs.StudentNumber)), ClassRecord(move(rhs.ClassRecord)), token(move(rhs.token)){}
    //copy constructor
    StudentRecord::StudentRecord(const StudentRecord &rhs): Name (rhs.Name), Surname (rhs.Surname), StudentNumber (rhs.StudentNumber), ClassRecord(rhs.ClassRecord), token(rhs.token){}

    StudentRecord &StudentRecord::operator =(StudentRecord && rhs)	//move assignment operator
    {
        if(this != &rhs)
        {
            Name = move(rhs.Name);
            Surname = move(rhs.Surname);
            StudentNumber = move(rhs.StudentNumber);
            ClassRecord = move(rhs.ClassRecord);
            token = move(rhs.token);
        }
        return *this;
    }
    
    
    
    StudentRecord &StudentRecord::operator =(const StudentRecord & rhs)//copy assignment operator
    {
        if(this != &rhs)
        {
            Name = rhs.Name;
            Surname = rhs.Surname;
            StudentNumber = rhs.StudentNumber;
            ClassRecord = rhs.ClassRecord;
            token = rhs.token;
        }
        return *this;
    }


    
    StudentRecord::~StudentRecord(){}//destructor

	void StudentRecord::set_token (int tkn)
    {
		token = tkn;
	}
	
    int StudentRecord::get_token(void)
    {
        return token;
    }
    
    string StudentRecord::get_name(void)
    {
        return Name;
    }


    string StudentRecord::get_student_number(void)
    {
        return StudentNumber;
    }
    
	string StudentRecord::get_surname(void)
    {
        return Surname;
    }


    string StudentRecord::get_class_record(void)
    {
        return ClassRecord;
    }

    


}
