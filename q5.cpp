#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double monthlySalary;
    double taxPercentage;

public:
    void get_data() {
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter monthly salary: ";
        cin >> monthlySalary;
        taxPercentage = 2;  
        cout << "Starting tax is set at " << taxPercentage << "%" << endl;
    }

    double Salary_after_tax() {
        double taxAmount = (taxPercentage / 100) * monthlySalary;
        return monthlySalary - taxAmount;
    }

    void update_tax_percentage(double newTax) {
        cout << "Updating tax from " << taxPercentage << "% to " << newTax << "%..." << endl;
        taxPercentage = newTax;
        cout << "Salary after new tax: " << Salary_after_tax() << endl;
    }

    void display() {
        cout << "\nEmployee: " << name << endl;
        cout << "Monthly Salary: Rs. " << monthlySalary << endl;
        cout << "Current Tax Percentage: " << taxPercentage << "%" << endl;
        cout << "Salary after tax: Rs. " << Salary_after_tax() << endl;
    }
};

int main() {
    Employee emp;

    emp.get_data();
    emp.display();
    emp.update_tax_percentage(3);

    return 0;
}
