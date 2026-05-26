#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>
/*
Варіант 3
Задача А: Утворити файл, який містить інформацію про співробітників
університету. Структура містить: прізвище працюючого, назва відділу, рік
народження, стаж роботи, посада, оклад. Кількість записів довільна.



Задача В: Написати програму, яка видає дозволяє отримати наступну інформацію:
— список працівників пенсійного віку на сьогоднішній день з зазначенням стажу
роботи; — середній стаж працюючих у відділі X
*/

struct Employee {
  std::string last_name;
  std::string departament;
  int birth_year{};
  int experience{};
  std::string position;
  double salary{};
};

void insert_employees_file(std::string_view filename,
                           std::vector<Employee> employees) {
  std::ofstream file{std::string(filename)};
  if (!file.is_open()) {
    throw std::runtime_error("Error opening file");
  }
  for (auto &emp : employees) {
    std::replace(emp.departament.begin(), emp.departament.end(), ' ', '_');
    std::replace(emp.position.begin(), emp.position.end(), ' ', '_');
    file << emp.last_name << '\t' << emp.departament << '\t' << emp.birth_year
         << '\t' << emp.experience << '\t' << emp.position << '\t' << emp.salary
         << '\n';
  }
}

/*
Задача В: Написати програму, яка видає дозволяє отримати наступну інформацію:
— список працівників пенсійного віку на сьогоднішній день з зазначенням стажу
роботи; — середній стаж працюючих у відділі X
*/

const int CURRENT_YEAR = 2026;
void sorted_by_pension(std::string_view filename) {
  std::ifstream file{std::string(filename)};
  if (!file.is_open()) {
    throw std::runtime_error("Error opening file");
  }
  Employee temp;
  while (file >> temp.last_name >> temp.departament >> temp.birth_year >>
         temp.experience >> temp.position >> temp.salary) {
    int year_employe = CURRENT_YEAR - temp.birth_year;
    if (year_employe >= 60) {
      std::cout << temp.last_name << '\t' << temp.experience << '\n';
    }
  }
  file.close();
}

double average_experience_departament(std::string_view filename,
                                      std::string departament_name) {
  std::ifstream file{std::string(filename)};
  if (!file.is_open()) {
    throw std::runtime_error("Error opening file");
  }
  Employee temp;
  int all_year = 0, count_employe = 0;
  while (file >> temp.last_name >> temp.departament >> temp.birth_year >>
         temp.experience >> temp.position >> temp.salary) {
    std::replace(temp.departament.begin(), temp.departament.end(), '_', ' ');
    if (temp.departament == departament_name) {
      all_year += temp.experience;
      count_employe += 1;
    }
  }
  file.close();
  if (all_year > 0 && count_employe > 0) {
    return static_cast<double>(all_year) / count_employe;
  }
  return 0;
}

int main() {
  std::vector<Employee> list = {
      {"Shevchenko", "IT Departament", 1965, 20, "Senior Backend", 120000},
      {"Petrenko", "Marketing", 1990, 5, "Manager", 45000},
      {"Ivanenko", "IT Departament", 1960, 35, "Rector", 150000}};

  const std::string filename = "database.txt";

  try {
    insert_employees_file(filename, list);
    std::cout << "File has been successfully created and filled!\n\n";

    std::cout << "--- Workers of retirement age ---\n";
    sorted_by_pension(filename);
    std::cout << "-------------------------------------\n\n";

    std::string target_dep = "IT Departament";
    double avg_exp = average_experience_departament(filename, target_dep);
    std::cout << "Average experience \"" << target_dep << "\": " << avg_exp
              << " year.\n";

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << '\n';
  }

  return 0;
}
