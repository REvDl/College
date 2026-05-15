#include <iostream>
#include "Device.h"


int main() {
    // Просто тест для проверки
    Smartphone myPhone("Apple", "iPhone 15 Pro", 999.99, 0.187, 6.1, "A17 Pro", 48.0, 3274, "5G", 8, 256);
    myPhone.printSpecs();
    std::cout << "Total Memory: " << myPhone.getTotalMemory() << "GB\n\n";

    Laptop myLaptop("ASUS", "ROG Zephyrus", 1899.00, 1.65, "Membrane RGB", 14.0, "RTX 4060", "Ryzen 9", 76000);
    myLaptop.printSpecs();
    std::cout << "Ultrabook? " << (myLaptop.isUltrabook() ? "Yes" : "No") << "\n\n";

    Tablet myTablet("Samsung", "Galaxy Tab S9", 799.00, 0.498, true, "2560x1600", "Android 13", 500.0, false, 11.0);
    myTablet.printSpecs();
    std::cout << "Category: " << myTablet.getTabletCategory() << "\n";

    return 0;
}