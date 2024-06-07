#include "Employee.h"

Employee::Employee()
{
    name = "undefined";
    salary = 0;
}

Employee::Employee(string name, float salary){
    this->name = name;
    this->salary = salary;
}

void Employee::setName(string name){ this->name = name; }
void Employee::setSalary(float salary){   this->salary = salary;}

string Employee::getName() const{    return name;}
float Employee::getSalary() const{    return salary;}

void Employee::showInfo() const{
    cout << "Name: " << name << endl;
    cout << "Salary: " << salary << " UAH\n";
}

float Employee::calcSalary() const{
    return salary * 0.85;
}
