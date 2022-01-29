#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class employeedata
{
private:
    int eid;
    string employeename;

public:
    employeedata(int eid1 = 0, string employeename1 = "null")
    {
        eid = eid1;
        employeename = employeename1;
    }
    int getEid();
    int setEid(int eid);
    string getEmployeename();
    string setEmployeename(string employeename);
};
class fulltime : protected employeedata
{
protected:
    int salary;

public:
    fulltime(int eid1 = 1111, string employeename = "null", int salary1 = 10000) : employeedata(eid1, employeename)

    {
        salary = salary1;
    }
    int getSalary();
    int setSalary(int salary);
};
class parttime : protected employeedata
{
protected:
    int wage;

public:
    parttime(int eid = 1111, string employname = "null", int wage = 2000)
    {
        this->wage = wage;
    }
    int getWage();
    int setWage(int wage);
};
class displaypt : public employeedata, public parttime
{
public:
    displaypt(int eid, string name, int wage) : parttime(eid, name, wage)
    {
        cout << "EID ->" << eid << endl;
        cout << "NAME->" << name << endl;
        cout << "WAGE->" << wage << endl;
    }
};
class displayft : public employeedata, public fulltime
{
public:
    displayft(int eid, string name, int salary) : fulltime(eid, name, salary)
    {
        cout << "EID ->" << eid << endl;
        cout << "NAME->" << name << endl;
        cout << "SALARY->" << salary << endl;
    }
};
int employeedata::getEid()
{
    return eid;
}
int employeedata::setEid(int eid)
{
    this->eid = eid;
}
string employeedata::getEmployeename()
{
    return employeename;
}
string employeedata::setEmployeename(string employeename)
{
    this->employeename = employeename;
}
int fulltime::getSalary()
{
    return salary;
}
int fulltime::setSalary(int salary)
{
    this->salary = salary;
}
int parttime::getWage()
{
    return wage;
}
int parttime::setWage(int wage)
{
    this->wage = wage;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    displayft(1234, "ansuman", 100000);
    displaypt(8898, "prateek", 500000);
    return 0;
}