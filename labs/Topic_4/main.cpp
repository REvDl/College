#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


void task_1_5() {
    double a = 3.75;
    double b = 5.5;
    double h = 0.25;

    ofstream file("function_results.txt");
    if (!file.is_open()) {
        cout << "Error creating file for Task 1!" << endl;
        return;
    }
    cout << "   x      f(x)" << endl;
    cout << "-----------------------" << endl;

    file << "   x      f(x)" << endl;
    file << "-----------------------" << endl;
    double max_val = -999999.0;
    double min_val = 999999.0;
    for (double x = a; x <= b + h / 2; x += h) {
        double fx = pow(x, 2) + log(pow(x, 2) - 4);
        cout << x << "   " << fx << endl;
        file << x << "   " << fx << endl;
        if (fx > max_val) {
            max_val = fx;
        }
        if (fx < min_val) {
            min_val = fx;
        }
    }
    cout << "-----------------------" << endl;
    cout << "Maximum - " << max_val << "   Minimum - " << min_val << endl;

    file << "-----------------------" << endl;
    file << "Maximum - " << max_val << "   Minimum - " << min_val << endl;

    file.close();
}

void task_2_5() {
    ofstream create_dict("dict.txt");
    create_dict << "apple yabluko" << endl;
    create_dict << "cat kit" << endl;
    create_dict << "program programa" << endl;
    create_dict << "book knyga" << endl;
    create_dict.close();

    ifstream file("dict.txt");
    if (!file.is_open()) {
        cout << "Error opening dict.txt!" << endl;
        return;
    }
    string search_word = "cat";

    cout << "Searching translation for English word: '" << search_word << "'" << endl;

    string eng, ukr;
    bool znaydeno = false;
    while (file >> eng >> ukr) {
        if (eng == search_word) {
            cout << "Translation: " << ukr << endl;
            znaydeno = true;
            break;
        }
    }
    file.close();

    if (!znaydeno) {
        cout << "Word not found in dictionary." << endl;
    }
}

int main() {
    task_1_5();
    task_2_5();
    return 0;
}