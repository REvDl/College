#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Device {
protected:
    string brand;
    string model;
    double price;
    double weight;
    int warranty;

public:
    Device(string b = "", string m = "", double p = 0.0, double w = 0.0, int war = 12)
        : brand(b), model(m), price(p), weight(w), warranty(war) {
    }

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    double getPrice() const { return price; }
    double getWeight() const { return weight; }
    int getWarranty() const { return warranty; }

    bool setBrand(string brand) {
        if (brand.empty()) return false;
        this->brand = brand;
        return true;
    }
    bool setModel(string model) {
        if (model.empty()) return false;
        this->model = model;
        return true;
    }
    bool setPrice(double price) {
        if (price <= 0.0) return false;
        this->price = price;
        return true;
    }
    bool setWeight(double weight) {
        if (weight <= 0.0) return false;
        this->weight = weight;
        return true;
    }
    bool setWarranty(int warranty) {
        if (warranty < 0) return false;
        this->warranty = warranty;
        return true;
    }

    void printBase() const {
        cout << "Brand: " << brand << " | Model: " << model << " | Price: $" << price << " | Weight: " << weight << "kg" << " | Warranty: " << warranty << " months" << endl;
    }
};

class Smartphone : public Device {
public:
    double display;
    string processor;
    double camera;
    int battery;
    string network;
    int RAM;
    int storage;

    Smartphone(string b, string m, double p, double w, double d, string proc, double cam, int batt, string net, int r, int s)
        : Device(b, m, p, w), display(d), processor(proc), camera(cam), battery(batt), network(net), RAM(r), storage(s) {
    }

    int getTotalMemory() const { return RAM + storage; }

    void printSpecs() const {
        printBase();
        cout << "Specs: Display: " << display << "\", CPU: " << processor
            << ", Camera: " << camera << "MP, Battery: " << battery
            << "mAh, RAM: " << RAM << "GB, Storage: " << storage << "GB" << endl;
    }

};


class Laptop : public Device {
public:
    string keyboardType;
    double screenSize;
    string videoCard;
    string processor;
    int batteryCapacity;


    Laptop(string b, string m, double p, double w, string key, double screen, string gpu, string proc, int batt)
        : Device(b, m, p, w), keyboardType(key), screenSize(screen), videoCard(gpu), processor(proc), batteryCapacity(batt){
    }

    bool isUltrabook() const { return weight < 1.5; }

    void printSpecs() const {
        printBase();
        cout << "Specs: Screen: " << screenSize << "\", GPU: " 
            << videoCard << ", Keyboard: " 
            << keyboardType << ", CPU: " 
            << processor << ", Battery: " 
            << batteryCapacity << endl;
    }


    double getScreenPowerConsumption() {
        const double powerPerInch = 0.4;
        return screenSize * powerPerInch;
    }

    double getScreenOnlyBatteryLife() {
        if (screenSize <= 0) return 0;
        return batteryCapacity / getScreenPowerConsumption();
    }

};




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
        if (screenSize < 9.0) return "Компактний планшет (e-reader/mobi)";
        if (screenSize >= 9.0 && screenSize <= 12.0) return "Стандартний мультимедійний планшет";
        if (screenSize > 12.0 && (os == "Windows 11" || hasStylus)) {
            return "Графічний планшет / Професійне робоче місце";
        }
        return "Великий домашній планшет";
    }



    void printSpecs() const {
        printBase();
        cout << "Specs: Res: " << resolution << ", OS: " << os
            << ", Stylus: " << (hasStylus ? "Yes" : "No") 
            << ", Brightness: " << brightness << " nits, Cellular: " 
            << cellular << ", Screen: " << screenSize << "\"" << endl;
    }
};