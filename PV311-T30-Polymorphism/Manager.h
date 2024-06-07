#pragma once
#include "Employee.h"
class Manager :  public Employee
{
protected:
	int percent;
	float sales;
public:
	Manager();
	Manager(string name, float salary, int percent,	float sales);

	void setPercent(int percent);
	void setSale(float sales);

	int getPercent()const;
	float getSales()const;

	void showInfo()const;
	float calcSalary()const;
};

