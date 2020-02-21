/*
 * employee.h
 * This class implements each record of employees.dat
 *
 *  Created on: Feb 21, 2020
 *      Author: somayeghahari
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string>
#include <cstring>
#include <iostream>


/**
 *
 */
struct employee {
public:
	employee();
	virtual ~employee();
	int getEmployeeId() const;
	void setEmployeeId(int employeeId);
	const std::string& getEmployeeFName() const;
	void setEmployeeFName(const std::string& employeeName);
	const std::string& getEmployeeLName() const;
	void setEmployeeLName(const std::string& employeeName);
	bool parseLine(std::string& line);
	bool operator< (const employee & other) const ;
	friend bool compareId (const employee & obj1, const employee & obj2)  ;
	friend std::ostream& operator<<(std::ostream&, const employee&);

private:
	int employeeId;
	std::string employeeFName;
	std::string employeeLName;
};

#endif /* EMPLOYEE_H_ */
