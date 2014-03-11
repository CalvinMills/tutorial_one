//MLLCAL002
//Calvin Mills
//Assignment 1
//Due: 10 March 2014

#ifndef DATABASE_H
#define DATABASE_H
#include <fstream>
#include <iostream>
#include <sstream>
#include "studentrecord.h"
#include "tokenlib.h"
#include <list>
#include <iterator>
#include <string>
#include <vector>

namespace MLLCAL002 {
using namespace std;
using namespace tokenlib;
    class DataBase
    {
    public:
		//Method definitions
		void add_student(StudentRecord);
		void display_student(string);
		void delete_student(string);
        void save_data(void);
        void read_data(void);
        list<StudentRecord>::iterator find_student( string );
        void grade_student(string);
        void display_all_students(void);
        void find_winning_student(void);

        // 6 Special Member Functions
        DataBase(string file_name);        			//constructor
        DataBase(void);        						//default constructor
        DataBase(DataBase && rhs);					//move constructor
        DataBase(const DataBase & rhs);				//copy constructor
        DataBase &operator =(DataBase && rhs);		//move assignment operator
        DataBase &operator =(const DataBase &rhs);	//copy assignment operator
        ~DataBase();								//destructor
        
    private:
    //VARIABLES
        string fileName;
        list<StudentRecord> Students;
        list<StudentRecord>::iterator i;
    };
}
#endif // DATABASE_H
