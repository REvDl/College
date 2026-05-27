#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream create_text("text.txt");
    if (!create_text.is_open()) {
        cout << "Error creating text.txt!" << endl;
        return 1;
    }
    create_text << "Hello, world! Hello... Is anyone here? Yes, is cool; right?" << endl;
    create_text.close();

    cout << "=== Test file text.txt created ===" << endl;
    char znaky[8] = { '.', ',', '!', '?', ';', ':', '-', '"' };
    int lichilnyky[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    ifstream read_text("text.txt");
    if (!read_text.is_open()) {
        cout << "Error opening text.txt!" << endl;
        return 1;
    }

    char symvol;
    while (read_text.get(symvol)) {
        for (int i = 0; i < 8; i++) {
            if (symvol == znaky[i]) {
                lichilnyky[i]++;
                break;
            }
        }
    }
    read_text.close();
    ofstream report_file("punctuation_report.txt");
    if (!report_file.is_open()) {
        cout << "Error creating report file!" << endl;
        return 1;
    }

    report_file << " Znak | Kilkist" << endl;
    report_file << "------|---------" << endl;

    for (int i = 0; i < 8; i++) {
        if (lichilnyky[i] > 0) {
            report_file << "  " << znaky[i] << "   |    " << lichilnyky[i] << endl;
        }
    }
    report_file.close();

    cout << "\n>>> Results successfully saved to punctuation_report.txt!" << endl;
    cout << "\n--- Table Content: ---" << endl;
    cout << " Znak | Kilkist" << endl;
    cout << "------|---------" << endl;
    for (int i = 0; i < 8; i++) {
        if (lichilnyky[i] > 0) {
            cout << "  " << znaky[i] << "   |    " << lichilnyky[i] << endl;
        }
    }

    return 0;
}