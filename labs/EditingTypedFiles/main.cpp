#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
struct Athlete {
  std::string first_name;
  std::string gender;
  int birth_year{};
  int height{};
};

void insert_employees_file(std::string_view filename,
                           std::vector<Athlete> athletes) {
  std::ofstream file{std::string(filename)};
  if (!file.is_open()) {
    throw std::runtime_error("Error opening file");
  }
  for (auto &ath : athletes) {
    file << ath.first_name << '\t' << ath.gender << '\t' << ath.birth_year
         << '\t' << ath.height << '\n';
  }
  file.close();
}

const int CURRENT_YEAR = 2026;
void tallest_athlete(std::string_view filename,
                     std::string_view file_to_write) {
  std::ifstream file{std::string(filename)};
  std::ofstream file_write{std::string(file_to_write)};
  if (!file.is_open() || !file_write.is_open()) {
    throw std::runtime_error("Error opening file");
  }
  Athlete temp, tallest;
  tallest.height = 0;
  while (file >> temp.first_name >> temp.gender >> temp.birth_year >>
         temp.height) {
    if (temp.height > tallest.height) {
      tallest = temp;
    }
  }
  std::stringstream ss;
  ss << "Tallest athlete: " << tallest.first_name << '\t'
     << CURRENT_YEAR - tallest.birth_year << '\t' << tallest.height << '\n';

  std::string tallest_info = ss.str();
  file_write << tallest_info;
  std::cout << tallest_info << std::endl;
}

int main() {
  try {
    std::vector<Athlete> test_athletes = {{"Ivanov", "Football", 2005, 185},
                                          {"Petrov", "Basketball", 2002, 201},
                                          {"Sidorov", "Boxing", 2007, 178}};

    std::string_view input_file = "athletes_database.txt";
    std::string_view output_file = "tallest_result.txt";

    insert_employees_file(input_file, test_athletes);
    tallest_athlete(input_file, output_file);

  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << '\n';
    return 1;
  }
  return 0;
}
