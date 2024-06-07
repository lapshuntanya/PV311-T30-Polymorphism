#include "Teacher.h"

Teacher::Teacher()
{
    hours = 0;
    price = 0;
}

Teacher::Teacher(string name, float salary, int hours, float price)
    :Employee(name, salary)
{
    this->hours = hours;
    this->price = price;
}

void Teacher::setHours(int hours){ this->hours = hours;  }
void Teacher::setPrice(float price){ this->price = price; }
int Teacher::getHours() const{    return hours;}
float Teacher::getPrice() const{    return price;}

void Teacher::showInfo() const{
    Employee::showInfo();
    cout << "Hours: " << hours << endl;
    cout << "Price: " << price  << "UAH" << endl;
    cout << "TOTAL salary: " << calcSalary() << " UAH\n";
}

float Teacher::calcSalary() const{
    return (salary + hours * price) * 0.85;
}
