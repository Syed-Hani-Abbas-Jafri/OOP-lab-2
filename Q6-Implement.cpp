#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    Employee emp1, emp2, emp3;

    emp1.get_data();
    emp2.get_data();
    emp3.get_data();

    cout << "\n--- Employee 1 ---" << endl;
    emp1.display();
    emp1.update_tax_percentage();

    cout << "\n--- Employee 2 ---" << endl;
    emp2.display();
    emp2.update_tax_percentage();

    cout << "\n--- Employee 3 ---" << endl;
    emp3.display();
    emp3.update_tax_percentage();

    return 0;
}
