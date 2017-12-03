# OS_Lab4
Lab 4 for Operating Systems CSC3453 - Disk Simulation Algorithms

Author: Gavin Atkin
Lab4 - CSCI 3453
Date: 11/22/2017

README:
* From CSE Grid terminal:
	-Extract the atk8013.tar.gz file.
	-Build source with: make makefile all
	-Run program with: ./disksim headstartposition headdirection inputfilename outputfilename
	Where:
	headstartposition is an integer value specifying the start position of the head (0-199 inclusive).
	headdirection is the direction the head is moving (0 - down, 1 - up).
	inputfilename is the file to read values from.
	outputfilename is the file to output results to.

* Output will be written to the outputfilename as well as to the console.