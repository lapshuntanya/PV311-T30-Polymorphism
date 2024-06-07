#include "Employee.h"
#include "Manager.h"
#include "Teacher.h"
#include <vector>

int main()
{
    Employee obj1("Бердник Даніїл", 9'000);
    Manager obj2("Білецький Віталій", 10'000, 10, 200'000);
    Teacher obj3("Будянський Данило", 15'000, 10, 500);

    vector<Employee*> company{
        &obj1, &obj2, &obj3,
        new Manager("Дехтяренко Олег", 10'000, 15, 150'000),
        new Teacher("Левченко Ярослав", 20'000, 20, 550),
        new Manager("Місенко Артур", 15'000, 25, 100'000)
    };

    for (int i = 0; i < company.size(); i++)
    {
        company[i]->showInfo(); cout << endl;
    }


    return 0;
}

