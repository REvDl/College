#pragma once
#include "Device.h"

class Laptop : public Device {
public:
    string keyboardType;
    double screenSize;
    string videoCard;
    string processor;
    int batteryCapacity;

    Laptop(string b, string m, double p, double w, string key, double screen, string gpu, string proc, int batt)
        : Device(b, m, p, w), keyboardType(key), screenSize(screen), videoCard(gpu), processor(proc), batteryCapacity(batt) {
    }

    bool isUltrabook() const { return weight < 1.5; }

    double getScreenPowerConsumption() const {
        const double powerPerInch = 0.4;
        return screenSize * powerPerInch;
    }

    double getScreenOnlyBatteryLife() const {
        if (screenSize <= 0) return 0;
        return batteryCapacity / getScreenPowerConsumption();
    }

    void printSpecs() const {
        printBase();
        cout << "Specs: Screen: " << screenSize << "\", GPU: "
            << videoCard << ", Keyboard: "
            << keyboardType << ", CPU: "
            << processor << ", Battery: "
            << batteryCapacity << endl;
    }
};