//MLLCAL002
//Calvin Mills
//Assignment 1
//Due: 10 March 2014

#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H
#include "counter.h"
#include <iostream>

using namespace std;

namespace MLLCAL002 {

    class StudentRecord : public sjp::counter<StudentRecord>
    {
    public:
    

		string get_name(void);

		string get_surname(void);

		string get_student_number(void);
		string get_class_record(void);
		void set_token (int);
		int get_token (void);
	


        // 6 Special Member Functions
        StudentRecord(string name, string surname, string studentnumber, string classRecord, int token);//constructor    
		friend ostream& operator<<( ostream & os, const StudentRecord & studentrecord);//overload output
		friend istream& operator>>( istream& is, StudentRecord& studentrecord);//overload input
        StudentRecord(void);//default constructor  
        StudentRecord(StudentRecord && rhs);//move constructor
        StudentRecord(const StudentRecord & rhs);//copy constructor     
        StudentRecord &operator =(StudentRecord && rhs);//move assignment operator  
        StudentRecord &operator =(const StudentRecord &rhs);//copy assignment operator       
        ~StudentRecord();//destructor



    private:
		int token;
        string Name;
        string Surname;
        string StudentNumber;
        string ClassRecord;
        
        
    };
}
#endif // STUDENTRECORD_H
