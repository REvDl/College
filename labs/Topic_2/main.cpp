#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void task_3() {
    ofstream create_f("f.txt");
    create_f << "some_text 123 tsn 45 abc 7 999_xyz 0" << endl;
    create_f.close();
    ifstream file_f("f.txt");
    ofstream file_q("q.txt");
    if (!file_f.is_open() || !file_q.is_open()) {
        cout << "Error working with files in task 3!" << endl;
        return;
    }
    cout << "Content of f.txt: some_text 123 tsn 45 abc 7 999_xyz 0" << endl;
    string slovo;
    while (file_f >> slovo) {
        bool ce_chyslo = true;
        for (int i = 0; i < slovo.length(); i++) {
            if (slovo[i] < '0' || slovo[i] > '9') {
                ce_chyslo = false;
                break;
            }
        }
        if (ce_chyslo) {
            file_q << slovo << " ";
            cout << "Found number: " << slovo << endl;
        }
    }
    file_f.close();
    file_q.close();
}

void task_12() {
    string p = "program";
    ofstream create_f("f.txt");
    create_f << "pro gram ram proog book map programm" << endl;
    create_f.close();

    ifstream file_f("f.txt");
    if (!file_f.is_open()) {
        cout << "Error opening file in task 4!" << endl;
        return;
    }
    cout << "\n>>> Task 4 started:" << endl;
    cout << "Word p: " << p << endl;
    cout << "Content of f.txt: pro gram ram proog book map programm" << endl;
    cout << "Words that can be made from '" << p << "':" << endl;
    string slovo;
    while (file_f >> slovo) {
        string temp_p = p;
        bool mozhna_sklasty = true;
        for (int i = 0; i < slovo.length(); i++) {
            char litera = slovo[i];
            size_t found_pos = temp_p.find(litera);

            if (found_pos != string::npos) {
                temp_p[found_pos] = ' ';
            }
            else {
                mozhna_sklasty = false;
                break;
            }
        }

        if (mozhna_sklasty) {
            cout << " -> " << slovo << endl;
        }
    }

    file_f.close();
}

int main() {
    task_3();
    task_12();

    return 0;
}