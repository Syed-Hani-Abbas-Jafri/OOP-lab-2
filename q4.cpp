#include <iostream>
#include <string>
using namespace std;

class StationeryShop {
private:
    string items[100];
    double prices[100];
    int itemCount;

public:
    StationeryShop() {
        itemCount = 0;
    }

    void addItem() {
        if (itemCount >= 100) {
            cout << "Item limit reached." << endl;
            return;
        }

        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, items[itemCount]);

        cout << "Enter price: ";
        cin >> prices[itemCount];

        itemCount++;
        cout << "Item added successfully." << endl;
    }

    void displayItems() {
        if (itemCount == 0) {
            cout << "No items available." << endl;
            return;
        }

        cout << "\nItems List:" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i] << endl;
        }
    }

    void editPrice() {
        string name;
        cout << "Enter item name to edit: ";
        cin.ignore();
        getline(cin, name);

        for (int i = 0; i < itemCount; i++) {
            if (items[i] == name) {
                cout << "Enter new price: ";
                cin >> prices[i];
                cout << "Price updated." << endl;
                return;
            }
        }

        cout << "Item not found." << endl;
    }

    void viewAll() {
        if (itemCount == 0) {
            cout << "No items available." << endl;
            return;
        }

        cout << "\nAll Items and Prices:" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << items[i] << " - Rs. " << prices[i] << endl;
        }
    }

    void generateReceipt() {
        int purchaseCount;
        string boughtItem;
        int qty;
        double total = 0;

        cout << "How many different items purchased: ";
        cin >> purchaseCount;

        cout << "\n========== RECEIPT ==========" << endl;

        for (int i = 0; i < purchaseCount; i++) {
            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, boughtItem);

            cout << "Enter quantity: ";
            cin >> qty;

            bool found = false;

            for (int j = 0; j < itemCount; j++) {
                if (items[j] == boughtItem) {
                    double cost = prices[j] * qty;
                    cout << boughtItem << " x " << qty << " = Rs. " << cost << endl;
                    total += cost;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << boughtItem << " not found." << endl;
            }
        }

        cout << "----------------------------" << endl;
        cout << "Total: Rs. " << total << endl;
        cout << "============================" << endl;
    }
};

int main() {
    StationeryShop shop;
    int choice;

    do {
        cout << "\n1. Add Item" << endl;
        cout << "2. Display Items" << endl;
        cout << "3. Edit Price" << endl;
        cout << "4. View All Items with Prices" << endl;
        cout << "5. Generate Receipt" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            shop.addItem();
        else if (choice == 2)
            shop.displayItems();
        else if (choice == 3)
            shop.editPrice();
        else if (choice == 4)
            shop.viewAll();
        else if (choice == 5)
            shop.generateReceipt();
        else if (choice == 6)
            cout << "Exiting..." << endl;
        else
            cout << "Invalid choice." << endl;

    } while (choice != 6);

    return 0;
}
