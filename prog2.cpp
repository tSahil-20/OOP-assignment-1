#include<iostream>
#include<string>
using namespace std;

class Employee{
    protected:
    string name;
    int empid;
    float salary;

    public:
    Employee(){}
    Employee(string name, int empid, float salary){
        this->name = name;
        this->empid = empid;
        this->salary = salary;
    }
    void displayDetails(){
        cout<< "Employee ID: "<<empid<<endl<<"Employee Name: "<<name<<endl<<"Employee Salary: "<<salary<<endl;
    }
};
class Manager:public Employee{
    string dept;
    public:
    Manager(){}
    Manager(string name, int empid, float salary, string dept):Employee(name, empid, salary){
        this->dept = dept;
    }
    void displayDetails(){
        cout<< "Manager ID: "<<empid<<endl<<"Manager Name: "<<name<<endl<<"Manager Salary: "<<salary<<endl<<"Manager Department :"<<dept<<endl<<endl;
    }
};
class Engineer:public Employee{
    string specialization;
    public:
    Engineer(){}
    Engineer(string name, int empid, float salary, string specialization):Employee(name, empid, salary){
        this->specialization = specialization;
    }
    void displayDetails(){
        cout<< "Engineer ID: "<<empid<<endl<<"Engineer Name: "<<name<<endl<<"Engineer Salary: "<<salary<<endl<<"Engineer Specialization :"<<specialization<<endl<<endl;
    }
};
class Technician:public Employee{
    string experience;
    public:
    Technician(){}
    Technician(string name, int empid, float salary, string experience):Employee(name, empid, salary){
        this->experience = experience;
    }
    void displayDetails(){
        cout<< "Technician ID: "<<empid<<endl<<"Technician Name: "<<name<<endl<<"Technician Salary: "<<salary<<endl<<"Technician experience :"<<experience<<endl<<endl;
    }
};

int main(){
    Manager m("Nikhil Nair", 5013, 5000, "Sales");
    Engineer e("Dhananjay Rajput", 5014, 6000, "AI");
    Technician t("Shubh Joshi", 5015, 4000, "10 years");
    m.displayDetails();
    e.displayDetails();
    t.displayDetails();

    cout << '\n';
    return 0;
}