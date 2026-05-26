#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_set>

void clean_file_from_garbage(std::string_view filename,
                             std::string_view file_to_write) {
  std::ifstream file_read{std::string(filename)};
  std::ofstream file_write{std::string(file_to_write)};
  std::string line;
  while (std::getline(file_read, line)) {
    std::stringstream ss(line);
    std::string clean_line = "", word;
    while (ss >> word) {
      if (word.length() == 1)
        continue;
      clean_line += word + " ";
    }
    if (!clean_line.empty())
      clean_line.pop_back();
    file_write << clean_line << '\n';
  }
  file_read.close();
  file_write.close();
}

int main() {
  clean_file_from_garbage("database.txt", "clean_database.txt");
  return 0;
}
