/*
 * employee.cpp
 *
 *  Created on: Feb 21, 2020
 *      Author: somayeghahari
 */

#include "employee.h"

employee::employee() {
	employeeId = 0;
	employeeFName = " ";
	employeeLName = " ";
}

employee::~employee() {
	// TODO Auto-generated destructor stub
}

int employee::getEmployeeId() const {
	return employeeId;
}

void employee::setEmployeeId(int employeeId) {
	this->employeeId = employeeId;
}

const std::string& employee::getEmployeeFName() const {
	return employeeFName;
}

void employee::setEmployeeFName(const std::string& employeeFName) {
	this->employeeFName = employeeFName;
}

const std::string& employee::getEmployeeLName() const {
	return employeeLName;
}

void employee::setEmployeeLName(const std::string& employeeLName) {
	this->employeeLName = employeeLName;
}

bool employee::parseLine( std::string& line) {
	char  cLine[line.size()+1];
	bool result = false;
	strcpy(cLine, line.c_str());
	char * tokenPtr = NULL;
	//get id
	tokenPtr = strtok (cLine,",");
	if (tokenPtr != NULL){
		employeeId = atoi(tokenPtr);
		//get fname
		tokenPtr = strtok (NULL, " ");
		if (tokenPtr != NULL){
			employeeFName = tokenPtr;
			//get lname
			tokenPtr = strtok (NULL, " ");
			if (tokenPtr != NULL){
				employeeLName = tokenPtr;
				result = true;
			}
		}
	}
	return result;
}


bool employee::operator< (const employee & other) const {
	return (employeeLName.compare(other.employeeLName)<0)?1:0;
}

std::ostream& operator<<(std::ostream &strm, const employee &obj) {
  return strm << obj.employeeId <<","<< obj.employeeFName<<" "<<obj.employeeLName;
}

 bool compareId (const employee & obj1, const employee & obj2)  {
	return obj1.getEmployeeId() < obj2.getEmployeeId();

}
