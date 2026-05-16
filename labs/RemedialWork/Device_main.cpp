#include <iostream>
#include "Smartphone.h"
#include "Laptop.h"
#include "Tablet.h"
#include <limits>
using namespace std;



void showMenu() {
    cout << "================ MENU ================\n";
    cout << "1. Show characteristics Smartphone\n";
    cout << "2. Show characteristics Laptop\n";
    cout << "3. Show characteristics Table\n";
    cout << "4. Show everything\n";
    cout << "0. Exit\n";
    cout << "======================================\n";
    cout << "Select item: ";
}




int main() {
    int choice = -1;
    Smartphone myPhone("Apple", "iPhone 15 Pro", 999.99, 0.187, 6.1, "A17 Pro", 48.0, 3274, "5G", 8, 256);
    Laptop myLaptop("ASUS", "ROG Zephyrus", 1899.00, 1.65, "Membrane RGB", 14.0, "RTX 4060", "Ryzen 9", 76000);
    Tablet myTablet("Samsung", "Galaxy Tab S9", 799.00, 0.498, true, "2560x1600", "Android 13", 500.0, false, 11.0);

    while (choice != 0) {
        showMenu();
        if (!(cin >> choice)) {
            cout << "\n[ќшибка] ¬ведите корректное число!\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cout << "\n";
        switch (choice) {
            case 1:
                cout << "--- Information about Smartphone ---\n";
                myPhone.printSpecs();
                cout << "Total Memory: " << myPhone.getTotalMemory() << "GB\n";
                break;

            case 2:
                cout << "--- Information about Laptop ---\n";
                myLaptop.printSpecs();
                cout << "Ultrabook? " << (myLaptop.isUltrabook() ? "Yes" : "No") << "\n\n";
                break;

            case 3:
                cout << "--- Information about Tablet ---\n";
                myTablet.printSpecs();
                cout << "Category: " << myTablet.getTabletCategory() << "\n";
                break;

            case 4:
                cout << "--- Everything ---\n";
                myPhone.printSpecs();
                cout << "------------------------\n";
                myLaptop.printSpecs();
                cout << "------------------------\n";
                myTablet.printSpecs();
                break;
                
            case 0:
                cout << "Exit. Bye\n";
                break;

            default:
                cout << "Invalid menu item. Please try again\n";
                break;


        }
    }
    return 0;
}