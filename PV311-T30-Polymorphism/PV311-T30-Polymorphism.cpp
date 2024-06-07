#include "Employee.h"
#include "Manager.h"
#include "Teacher.h"
#include <vector>
#include <typeinfo>
#include <algorithm>

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
    cout << "----------------------------------------------\n\n";
    //Всім викладачам збільшити ціну заняття на 100 грн
    for (int i = 0; i < company.size(); i++)
    {
        if (typeid(*company[i]) == typeid(Teacher))
        {
            cout << company[i]->getName() << endl;
           // ((Teacher*)company[i])->setPrice(1'000);
            Teacher* obj = dynamic_cast<Teacher*>(company[i]);
            if (obj != nullptr) {
                obj->setPrice(obj->getPrice() + 100);
                cout << "New Price: " << obj->getPrice() << endl;
            }
        }
    }
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
    //1. Порахувати кількість робітників, у яких сума продажів більша ніж 15000 та вивести інформацію про них
    int amount = 0;
    for (int i = 0; i < company.size(); i++)
    {
        Manager* obj = dynamic_cast<Manager*>(company[i]);
        if (obj != nullptr && obj->getSales() > 15'000)
        {
            amount++;
            obj->showInfo();
        }
    }
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

    //2. Відсортувати робітників по сумі з.п - calcSalary
    sort(company.begin(), company.end(), [](Employee* left, Employee* right) {
        return left->calcSalary() < right->calcSalary();
        });

    for_each(company.begin(), company.end(), [](Employee* obj) {
        obj->showInfo();
        });
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
    //3. Видалити викладачів, якщо у них кількість занять менша за 10 годин
    for (int i = 0; i < company.size(); i++)
    {
        Teacher* obj = dynamic_cast<Teacher*>(company[i]);
        if (obj != nullptr && obj->getHours() <  10)
        {
            company.erase(company.begin() + i);
            i--;
        }
    }
    for_each(company.begin(), company.end(), [](Employee* obj) {
        obj->showInfo();
        });
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
    //4. Збільшити відсоток продажів на К, якщо дано Ім'я робітника

    string name = "Місенко Артур";
    auto item = find_if(company.begin(), company.end(), [name](Employee* obj) {
        return obj->getName() == name;
        });
    Manager* obj = dynamic_cast<Manager*>(*item);
    if (obj != nullptr)
    {
        obj->setPercent(obj->getPercent() + 15);
    }
    for_each(company.begin(), company.end(), [](Employee* obj) {
        obj->showInfo();
        });

    return 0;
}

