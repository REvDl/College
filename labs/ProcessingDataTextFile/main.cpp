#include <fstream>
#include <iomanip>
#include <iostream>
#include <string_view>
#include <unordered_map>

void file_write_letter(std::string_view filename, std::string_view file_write) {
  std::ifstream file(filename.data());
  std::ofstream file_to_write(file_write.data());
  if (!file.is_open() || !file_to_write.is_open()) {
    std::cerr << "File opening error" << std::endl;
    return;
  }
  std::unordered_map<char, int> letter_count;
  char ch;
  while (file.get(ch)) {
    if (std::isalpha(static_cast<unsigned char>(ch))) {
      char lowercaseCh = std::tolower(static_cast<unsigned char>(ch));
      letter_count[lowercaseCh]++;
    }
  }
  file.close();
  file_to_write << "====================\n";
  file_to_write << "| Letter | count |\n";
  file_to_write << "====================\n";
  for (const auto &pair : letter_count) {
    file_to_write << "|   " << pair.first << "   |    " << std::setw(5)
                  << std::left << pair.second << " |\n";
  }
  file_to_write << "====================\n";
  file_to_write.close();
}

int main() {
  file_write_letter("input.txt", "output.txt");

  std::cout << "Done! Check output.txt" << std::endl;
  return 0;
}
