#pragma once
#include "Device.h"

class Tablet : public Device {
public:
    bool hasStylus;
    string resolution;
    string os;
    double brightness;
    bool cellular;
    double screenSize;

    Tablet(string b, string m, double p, double w, bool stylus, string res, string system, double bright, bool cell, double screen)
        : Device(b, m, p, w), hasStylus(stylus), resolution(res), os(system), brightness(bright), cellular(cell), screenSize(screen) {
    }

    bool isForDesigners() const { return hasStylus && brightness > 400; }

    string getTabletCategory() {
        if (screenSize < 9.0) return "Compact tablet (e-reader/mobi)";
        if (screenSize >= 9.0 && screenSize <= 12.0) return "Standard multimedia tablet";
        if (screenSize > 12.0 && (os == "Windows 11" || hasStylus)) {
            return "Graphics tablet / Professional workstation";
        }
        return "Large home tablet";
    }

    void printSpecs() const {
        printBase();
        cout << "Specs: Res: " << resolution << ", OS: " << os
            << ", Stylus: " << (hasStylus ? "Yes" : "No")
            << ", Brightness: " << brightness << " nits, Cellular: "
            << cellular << ", Screen: " << screenSize << "\"" << endl;
    }
};