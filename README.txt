MLLCAL002
Assignment 1
Due March 10 2014

Description: Setting up and management of a students record database. 

Instructions: 
		1. Run Make in the folder
		2. Run "make run" in the folder
		3. The Menu works based on text input at run time, each command
		   0 through 7 as well as q runs a self explanatory function.
		4. if you wish to view records previously saved "read database" will 
		   have to be called prior to request. 
		5. If you wish for changes to remain after the program has ended run
		   the "save database" function.
		6. If you are complete run the quit or "q" command

File List: 
		-Driver.cpp - Handles the text interface and the all the function 			 calls.Driver uses methods from the Database class to manipulate data.

		-StudentRecord.h - contains method and variable definitions for the 			 StudentRecord.cpp file
		
		-StudentRecord.cpp - provides structure to manage the student record 			 information and produces an object of type Student record which will 			 house the student information. 	

		-Database.h - contains method and variable definitions for the 			 Database.cpp file

		-Database.cpp - Links to the text file containing the student records 			 and pulls and pushes data into or out of the file. Database stores 			 objects of type StudentRecord
		
		-tokenlib.cpp ; tokenlib.h ; tokenlib.so
		
		-cmdline_parser.cpp ; cmdline_parser.h

		-counter.h

		-Makefile - makes things

		-README.txt - this.
		
		-database.txt - Houses the records
		
		
