#pragma once
#include <string>
#include <iostream>
using namespace std;

class Employee
{
protected:
	string name;
	float salary;
public:
	Employee();
	Employee(string name, float salary);

	void setName(string name);
	void setSalary(float salary);
	string getName()const;
	float getSalary()const;

	void showInfo()const;
	float calcSalary()const;
};

