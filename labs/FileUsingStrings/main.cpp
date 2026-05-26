#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>

void clean_file_from_garbage(std::string_view filename,
                             std::string_view file_to_write) {
  std::ifstream file_read{std::string(filename)};
  std::ofstream file_write{std::string(file_to_write)};
  std::string line;
  if (!file_read.is_open() || !file_write.is_open()) {
    throw std::runtime_error("Error opening file");
  }
  while (std::getline(file_read, line)) {
    std::stringstream ss(line);
    std::string clean_line, word;
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

bool is_constructible_from_letters(const std::string &word,
                                   const std::unordered_map<char, int> &freq) {
  auto temp = freq;
  for (char c : word) {
    if (temp[c] == 0) {
      return false;
    }
    temp[c]--;
  }
  return true;
}

void check_word_from_file(std::string_view filename,
                          std::string_view file_to_write,
                          const std::string &source) {
  std::ifstream file_read{std::string(filename)};
  std::ofstream file_write{std::string(file_to_write)};
  if (!file_read.is_open() || !file_write.is_open()) {
    throw std::runtime_error("Error opening file");
  }
  std::unordered_map<char, int> freq;
  for (char c : source) {
    freq[c]++;
  }

  std::string line;
  while (std::getline(file_read, line)) {
    std::stringstream ss(line);
    std::string word, clean_line;
    while (ss >> word) {
      if (is_constructible_from_letters(word, freq)) {
        clean_line += word + " ";
      }
    }
    if (!clean_line.empty()) {
      clean_line.pop_back();
      file_write << clean_line << '\n';
    }
  }
  file_read.close();
  file_write.close();
}

int main() {
  try {
    clean_file_from_garbage("database.txt", "clean_database.txt");
    check_word_from_file("words.txt", "result_words.txt", "коромисло");
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << '\n';
    return 1;
  }
  return 0;
}
