//MLLCAL002
//Calvin Mills
//Assignment 1
//Due: 10 March 2014

#include <iostream>
#include <fstream>
#include "cmdline_parser.h"
#include "studentrecord.h"
#include "database.h"
#include "tokenlib.h"


using namespace MLLCAL002;

void add_student(DataBase &db)
{
    string name;
    string surname;
    string studentID;
    string classRecord;
    cout << "Enter Name" << endl;
    cin >> name;
    cout << "Enter Surname" << endl;
    cin >> surname;
    cout << "Enter Student ID" << endl;
    cin >> studentID;
    cout << "Enter Class Record(_ _ _)" << endl;
    getline(cin, classRecord);
    getline(cin, classRecord);
    StudentRecord newStudent(name, surname, studentID, classRecord, tokenlib::acquire_token());
    db.add_student(newStudent);
}

void delete_student(DataBase &db)
{
    string studentID;
    cout << "Enter Student ID" << endl;
    cin >> studentID;
    db.delete_student(studentID);

}

void read_data(DataBase &db)
{
    db.read_data();
    
}

void save_data(DataBase &db)
{
    db.save_data();
    
}

void display_student(DataBase &db)
{
    cout << "Enter student number" << endl;
    string stdNum;
    cin >> stdNum;
    db.display_student(stdNum);
    
}

void grade_student(DataBase &db)
{
    cout << "Enter student number" << endl;
    string stdNum;
    cin >> stdNum;
    db.grade_student(stdNum);

}

void display_all_students(DataBase &db)
{
    db.display_all_students();
    
}

void find_winning_student(DataBase &db)
{
    db.find_winning_student();
    
}

void display_menu()
{
	cout << "0:\tAdd Student" << endl;
	cout << "1:\tDelete Student" << endl;
	cout << "2:\tRead Database" << endl;
	cout << "3:\tSave Database" << endl;
	cout << "4:\tDisplay Given Student Data" << endl;
	cout << "5:\tGrade Student"<< endl;
	cout << "6:\tDisplay all Student Data" << endl;
	cout << "7:\tFind Winning Student" << endl;
	cout << "..." << endl;
	cout << "q:\tQuit" << endl;
	cout << "Enter a number (or q to quit) and press return..." << endl;
	
}


int main(int argc, char* argv[])
{
    using namespace std;
        {
        cmdline_parser parser;

        if(!parser.process_cmdline(argc, argv))
        {
            std::cerr << "Couldn't process command line arguments" << endl;
            return 1;
        }
        if(parser.should_print_help())
            { parser.print_help(std::cout);	}
        string file_name = parser.get_filename();
        cout << "Using file located at "+ file_name << endl;
        cout << "-----------------------------------------" << endl;
        DataBase db(file_name);

        for(;;)
        {
            cout << "--------------------------------------" << endl;
            display_menu();
            char selection;
            cin >> selection;
            
            if(selection == '0')
				add_student(db);
			else if(selection == '1')
				delete_student(db);
			else if(selection == '2')
				read_data(db);
			else if(selection == '3')
				save_data(db);
			else if(selection == '4')
				display_student(db);
			else if(selection == '5')
				grade_student(db);
			else if(selection == '6')
				display_all_students(db);
			else if(selection == '7')
				find_winning_student(db);
			else if(selection == 'q')
				break;				

                cout << endl;

        }
    }
    StudentRecord::print_counts(std::cout, "StudentRecord");
    tokenlib::final_token_check();
    return 0;
}
