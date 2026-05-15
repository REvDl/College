#pragma once
#include <iostream>
#include <string>
#include "Device.h"


using std::cout;
using std::endl;
using std::string;


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