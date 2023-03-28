#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream infile("numbers.txt");

  if (!infile.is_open()) {
    std::cout << "Error opening file!" << std::endl;
    return 1;
  }

  std::vector<int> data;
  std::string line;
  while (std::getline(infile, line)) {
    std::string delimiter = ",";
    size_t pos = 0;
    while ((pos = line.find(delimiter)) != std::string::npos) {
      std::string token = line.substr(0, pos);
      data.push_back(std::stoi(token));
      line.erase(0, pos + delimiter.length());
    }
    data.push_back(std::stoi(line));
  }

  if (infile.bad()) {
    std::cout << "Error reading data from file!" << std::endl;
    return 1;
  }

  infile.close();

  std::cout << "File is open" << std::endl;
  std::cout << "There are " << data.size() << " numbers in the file | ";

  if (data.size() == 0) {
    std::cout << "No data found in file!" << std::endl;
    return 1;
  }

  std::sort(data.begin(), data.end());

  int median;
  if (data.size() % 2 == 0) {
    median = (data[data.size() / 2] + data[data.size() / 2]) / 2;
  } else {
    median = data[data.size() / 2];
  }

  std::cout << "The median is: " << median << std::endl;

  return 0;
}