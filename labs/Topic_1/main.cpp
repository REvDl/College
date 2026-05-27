#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Program {
    string name;
    int start_hour;
    int start_min;
    int end_hour;
    int end_min;
};


void task_A() {
    ofstream file("rozklad.txt");
    if (!file.is_open()) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }


    Program programm_data[4] = {
        {"Ranok_Z_Ukrainoyu", 6, 0, 9, 30},
        {"Televisyt", 12, 15, 13, 0},
        {"Kino_Na_Vechir", 15, 0, 17, 45},
        {"TSN_Novyny", 19, 30, 20, 15}
    };
    for (int i = 0; i < 4; i++) {
        file << programm_data[i].name << " "
            << programm_data[i].start_hour << " " << programm_data[i].start_min << " "
            << programm_data[i].end_hour << " " << programm_data[i].end_min << endl;
    }
    file.close();
    cout << ">>> Задача А: Файл розкладу успішно створено!" << endl;
}
void task_B() {
    ifstream file("rozklad.txt");
    if (!file.is_open()) {
        cout << "Файл rozklad.txt не знайдено!" << endl;
        return;
    }

    vector<Program> spysok;
    Program p;
    while (file >> p.name >> p.start_hour >> p.start_min >> p.end_hour >> p.end_min) {
        spysok.push_back(p);
    }
    file.close();

    if (spysok.empty()) {
        cout << "Файл порожній!" << endl;
        return;
    }
    cout << "\n--- УСЯ ПРОГРАМА ПЕРЕДАЧ НА ДЕНЬ ---" << endl;
    for (int i = 0; i < spysok.size(); i++) {
        cout << spysok[i].name << " | Початок: "
            << spysok[i].start_hour << ":" << spysok[i].start_min
            << " | Кінець: " << spysok[i].end_hour << ":" << spysok[i].end_min << endl;
    }
    cout << "------------------------------------" << endl;
    int vvedeno_god, vvedeno_min;
    cout << endl;
    cout << "Введіть час для пошуку програми (години і хвилини через пробіл, наприклад 15 30): ";
    cin >> vvedeno_god >> vvedeno_min;

    int vvedeno_vseoho_min = vvedeno_god * 60 + vvedeno_min;
    bool znaydeno = false;

    for (int i = 0; i < spysok.size(); i++) {
        int v_poch_min = spysok[i].start_hour * 60 + spysok[i].start_min;
        int v_kin_min = spysok[i].end_hour * 60 + spysok[i].end_min;
        if (vvedeno_vseoho_min >= v_poch_min && vvedeno_vseoho_min < v_kin_min) {
            cout << "В цей час транслюється: " << spysok[i].name << endl;
            znaydeno = true;
            break;
        }
    }
    if (!znaydeno) {
        cout << "В цей час нічого не транслюється або передачу не знайдено" << endl;
    }
    int index_max = 0;
    int index_min = 0;

    int t_poch = spysok[0].start_hour * 60 + spysok[0].start_min;
    int t_kin = spysok[0].end_hour * 60 + spysok[0].end_min;
    int max_tryvalist = t_kin - t_poch;
    int min_tryvalist = t_kin - t_poch;

    for (int i = 1; i < spysok.size(); i++) {
        int poch = spysok[i].start_hour * 60 + spysok[i].start_min;
        int kin = spysok[i].end_hour * 60 + spysok[i].end_min;
        int potochna_tryvalist = kin - poch;

        if (potochna_tryvalist > max_tryvalist) {
            max_tryvalist = potochna_tryvalist;
            index_max = i;
        }
        if (potochna_tryvalist < min_tryvalist) {
            min_tryvalist = potochna_tryvalist;
            index_min = i;
        }
    }
    cout << "\n--- аналіз ---" << endl;
    cout << "Сама довга телепрограма: " << spysok[index_max].name << " (" << max_tryvalist << " хв)" << endl;
    cout << "Сама коротка телепрограма: " << spysok[index_min].name << " (" << min_tryvalist << " хв)" << endl;
}


int main() {
    setlocale(LC_ALL, "Ukrainian");
    task_A();
    task_B();
    return 0;
}