//============================================================================
// Name        : MySort.cpp
// Author      : SomayeGhahari
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
//#include <windows.h>
#include "employee.h"
using namespace std;

 bool compareId (const employee & obj1, const employee & obj2)  ;

int main(int argc, char* argv[]) {
//	SetConsoleTitle("EReport");
	string fileName;
	ifstream datFile;
	vector<employee> empList;
	vector<employee>::iterator iter;
	if(argc == 2){
		fileName = argv[1];
		if(fileName!=""){
			datFile.open(fileName);
			while(!datFile.eof())
			{
				string tStr;
				employee emp;
				getline(datFile, tStr);
				if(tStr.size()>1 && tStr.at(0)!='#'){
	//				cout << tStr ;
					emp.parseLine(tStr);
					empList.push_back(emp);
				}

			 }
			datFile.close();

			cout << "\nProcessing by employee number...\n";
			sort(empList.begin(), empList.end(), compareId);

			iter = empList.begin();

			for ( ; iter !=  empList.end(); iter++) {
				cout <<(*iter);
			}
			cout << "\nProcessing by last(family) name...\n";

			sort(empList.begin(), empList.end());
			iter = empList.begin();

			for ( ; iter !=  empList.end(); iter++) {
				cout <<(*iter);
			}

		}

	}

	return 0;
}
