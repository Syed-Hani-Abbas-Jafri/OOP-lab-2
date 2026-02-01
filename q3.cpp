#include <iostream>
#include <string>

using namespace std;

class WaterBottle {
private:
    string company;
    string color;
    int capacityML;
    double capacityL;

public:
    void setCompany(string c) {
        company = c;
    }

    void setColor(string c) {
        color = c;
    }

    void setCapacity(int ml) {
        capacityML = ml;
        capacityL = ml / 1000.0;
    }

    string getCompany() {
        return company;
    }

    string getColor() {
        return color;
    }

    int getCapacityML() {
        return capacityML;
    }

    double getCapacityL() {
        return capacityL;
    }

    void drinkWater() {
        int drank;
        cout << "Enter amount of water drank (ml): ";
        cin >> drank;

        if (drank <= capacityML) {
            capacityML -= drank;
            capacityL = capacityML / 1000.0;
            cout << "Water updated." << endl;
        } else {
            cout << "Not enough water in bottle." << endl;
        }
    }
};

int main() {
    WaterBottle bottle;

    bottle.setCompany("HydroFlask");
    bottle.setColor("Blue");
    bottle.setCapacity(1500);

    cout << "Company: " << bottle.getCompany() << endl;
    cout << "Color: " << bottle.getColor() << endl;
    cout << "Water: " << bottle.getCapacityML() << " ml (" << bottle.getCapacityL() << " L)" << endl;

    bottle.drinkWater();

    cout << "Updated Water: " << bottle.getCapacityML() << " ml (" 
         << bottle.getCapacityL() << " L)" << endl;

    return 0;
}
