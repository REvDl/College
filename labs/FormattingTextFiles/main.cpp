#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string_view>
#include <vector>

std::vector<double> identity_trig_function(double a, double b, double h) {
  std::vector<double> result;
  size_t steps = static_cast<size_t>((b - a) / h) + 1;
  result.reserve(steps);
  for (double x = a; x <= b; x += h) {
    double y = std::sqrt(std::sin(x) * std::sin(x) + std::cos(x) * std::cos(x));
    result.push_back(y);
  }
  return result;
}

void saveToFile(std::string_view filename, const std::vector<double> &data,
                double a, double h) {
  std::ofstream file(filename.data());
  if (!file.is_open()) {
    std::cerr << "File opening error" << std::endl;
    return;
  }
  file << "      x f(x)      " << '\n'
       << "----------------------------------" << '\n';
  std::cout << "      x f(x)      " << '\n'
            << "----------------------------------" << '\n';
  int current_x = a;
  double min = data[0], max = data[0];
  for (const auto &value : data) {
    if (value > max)
      max = value;
    if (value < min)
      min = value;
    file << "    " << std::fixed << std::setprecision(1) << current_x
         << "       " << std::setprecision(4) << value << '\n';

    std::cout << "    " << std::fixed << std::setprecision(1) << current_x
              << "       " << std::setprecision(4) << value << '\n';

    current_x += h;
  }
  file << "----------------------------------" << '\n';
  file << "Max - " << max << "     " << "Min - " << min << '\n';
  std::cout << "Max - " << max << "     " << "Min - " << min << '\n';
}

int main() {
  std::vector<double> data = identity_trig_function(300.0, 600.0, 20.0);
  saveToFile("result_file.txt", data, 300.0, 20.0);
}
