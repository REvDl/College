#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Проста структура спортсмена
struct Sportsman {
    string prizvyshe;
    int nomer;
    int ochky;
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    ofstream create_file("sportsmen.txt");
    if (!create_file.is_open()) {
        cout << "Error creating file!" << endl;
        return 1;
    }
    create_file << "Ivanov " << 10 << " " << 85 << endl;
    create_file << "Petrov " << 22 << " " << 90 << endl;
    create_file << "Sydorov " << 7 << " " << 64 << endl;
    create_file << "Smirnov " << 13 << " " << 73 << endl;
    create_file.close();
    cout << "=== Початковий файл створено (Ivanov перший, Petrov другий) ===" << endl;

    ifstream read_file("sportsmen.txt");
    if (!read_file.is_open()) {
        cout << "Error opening file for reading" << endl;
        return 1;
    }

    vector<Sportsman> spysok;
    Sportsman s;

    while (read_file >> s.prizvyshe >> s.nomer >> s.ochky) {
        spysok.push_back(s);
    }
    read_file.close();


    if (spysok.size() >= 2) {
        Sportsman temp = spysok[0];
        spysok[0] = spysok[1];
        spysok[1] = temp;
        cout << "\n>>> Поміняли місцями перших двох спортсменів у пам'яті!" << endl;
    }
    else {
        cout << "\nУ файлі замало спортсменів для обміну!" << endl;
        return 0;
    }
    ofstream write_file("sportsmen.txt");
    if (!write_file.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }
    for (int i = 0; i < spysok.size(); i++) {
        write_file << spysok[i].prizvyshe << " "
            << spysok[i].nomer << " "
            << spysok[i].ochky << endl;
    }
    write_file.close();
    cout << endl;
    cout << "=== Оновлений вміст файлу sportsmen.txt ===" << endl;
    ifstream check_file("sportsmen.txt");
    while (check_file >> s.prizvyshe >> s.nomer >> s.ochky) {
        cout << "Name: " << s.prizvyshe << " | Number: " << s.nomer << " | Points: " << s.ochky << endl;
    }
    check_file.close();
    return 0;
}