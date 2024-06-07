#include "Manager.h"

Manager::Manager()
{
    percent = 3;
    sales = 0;
}

Manager::Manager(string name, float salary, int percent, float sales)
    :Employee(name, salary)
{
    this->percent = percent;
    this->sales = sales;
}

void Manager::setPercent(int percent){ this->percent = percent; }
void Manager::setSale(float sales) { this->sales = sales; }

int Manager::getPercent() const{    return percent;}
float Manager::getSales() const{    return sales;}

void Manager::showInfo() const{
    Employee::showInfo();
    cout << "Percent: " << percent << "%\n";
    cout << "Sales: " << sales << "UAH\n";
}

float Manager::calcSalary() const{
    return (salary + sales * percent / 100) * 0.85;
}
