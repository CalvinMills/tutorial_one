//MLLCAL002
//Calvin Mills
//Assignment 1
//Due: 10 March 2014

#include "database.h"

namespace MLLCAL002 {

    void DataBase::add_student(StudentRecord NewStudent)
    {
		StudentRecord newstudent(NewStudent);
        Students.push_back(newstudent);
        
    }
    
	void DataBase::delete_student(string studentnumber)
    {
        list<StudentRecord>::iterator i = find_student(studentnumber);
        if ((i != Students.end())){
			release_token(i->get_token());
            Students.erase(i);
            cout << "Student with student number " << studentnumber << " has been removed";
        } else
        {
            cout << "Student with student number " << studentnumber << " not found";
        }
        cout << endl;
    }
    
    
    void DataBase::save_data( void )
    {
		ofstream file(fileName.c_str());
		list<StudentRecord>::iterator stuIt = Students.begin();
        while(stuIt != Students.end())
        {
            file << *stuIt;
            stuIt++;
        }
        file.close();
    }

    void DataBase::read_data( void )
    {
		ifstream file(fileName);
		istream& stream = file;
		while (stream.good())
		{
			StudentRecord studentrecord;
			stream >> studentrecord;
			if (studentrecord.get_name() != "" && studentrecord.get_surname() != "" && studentrecord.get_student_number() != "" && studentrecord.get_class_record()!= "")
			{
				studentrecord.set_token(tokenlib::acquire_token());
				add_student(studentrecord);
			}
			
		}
		file.close();
    }



    list<StudentRecord>::iterator DataBase::find_student(string studentNumber)
    {
        list<StudentRecord>::iterator stuIt = Students.begin();
        while(stuIt != Students.end())
        {
           if (stuIt->get_student_number() == studentNumber)
           {
                return stuIt;
           }
            stuIt++;
        }
        return stuIt;
    }

    void DataBase::display_student(string studentNumber)
    {
        cout  << endl;
        list<StudentRecord>::iterator stuIt = find_student(studentNumber);
        cout << endl;
        if (stuIt != Students.end())
        {
            StudentRecord student = *stuIt;
            cout << student.get_name() << "\t" << student.get_surname() << "\t" << student.get_student_number() << "\t" << student.get_class_record() << endl;
        }else
        {
            cout << "Student not found";
        }
    }

    void DataBase::grade_student(string stdNum)
    {
        cout << endl;
        list<StudentRecord>::iterator stuIt = find_student(stdNum);
        cout << endl;
        if (stuIt != Students.end())
        {
            string grades = stuIt->get_class_record();
            istringstream buf(grades);

            istream_iterator<string> beg(buf), end;

            vector<string> tokens(beg, end); // done!
            float tot = 0;
            for(auto& s: tokens)
                tot+=stoi(s);
            cout << tot/tokens.size();

        }else
        {
            cout << "Student not found";
        }
    }

    void DataBase::display_all_students( void )
    {
        list<StudentRecord>::iterator stu = Students.begin();
        while(stu != Students.end())
        {
            cout << stu->get_name() << "\t" << stu->get_surname() << "\t" << stu->get_student_number() << "\t" << stu->get_class_record()  << endl;
            stu++;
        }
    }

    void DataBase::find_winning_student( void )
    {
        list<StudentRecord>::iterator i = Students.begin();
        StudentRecord winner;
        float highestGrade = 0;
        while(i != Students.end())
        {
            string allGrades = i->get_class_record();
            istringstream buf(allGrades);

            istream_iterator<string> beg(buf), end;

            vector<string> grades(beg, end); 
            float total = 0;
            for(auto& s: grades)
                total  = total + stoi(s);
            total = total/grades.size();
            if (total > highestGrade)
            {
                highestGrade = total;
                winner = *i;
            }
            i++;
        }
        
        cout << "The student with the highest average grade was: " << endl;
        cout << winner.get_name() << "\t"<< winner.get_surname() << "\t" << winner.get_student_number() << "\t" << winner.get_class_record() << endl;
        cout << "with an average grade of: " << highestGrade << endl;
       
    }

    DataBase::DataBase(string file_name) : fileName (file_name)  {
    }
    //default constructor
    DataBase::DataBase( void ): fileName ("string.txt"){}
	//move constructor
    DataBase::DataBase(DataBase && rhs)
        : fileName (move(rhs.fileName)), Students (move(rhs.Students)){}
    //copy constructor
    DataBase::DataBase(const DataBase &rhs)
        : fileName (rhs.fileName), Students (rhs.Students){}
        
    //move assignment operator
    DataBase &DataBase::operator =(DataBase && rhs)
    {
        if(this != &rhs)
        {
            fileName = move(rhs.fileName);
            Students = move(rhs.Students);
        }
        return *this;
    }
    //copy assignment operator
    DataBase &DataBase::operator =(const DataBase & rhs)
    {
        if(this != &rhs)
        {
            fileName = rhs.fileName;
            Students = rhs.Students;
        }
        return *this;
    }


    //destructor
    DataBase::~DataBase()
    {
		while (!Students.empty())
		{
			release_token(Students.back().get_token());
			Students.pop_back();
			
		}
	}


}
