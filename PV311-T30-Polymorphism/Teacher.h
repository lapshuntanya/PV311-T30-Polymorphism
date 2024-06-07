#pragma once
#include "Employee.h"
class Teacher :   public Employee
{
protected:
	int hours;
	float price;
public:
	Teacher();
	Teacher(string name, float salary, int hours, float price);

	void setHours(int hours);
	void setPrice(float price);

	int getHours()const;
	float getPrice()const;

	void showInfo()const override;
	float calcSalary()const override;
};

