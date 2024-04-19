#include "CSVReportGenerator.h"
#include <fstream>
#include <iostream>
#include <sstream>

CSVReportGenerator::CSVReportGenerator(std::string path, std::string separator)
    : _path(path), _separator(separator) {}

void CSVReportGenerator::generateReport() const {
  std::ofstream outputFile(_path);

  if (!outputFile) {
    std::cerr << "Failed to open file: " << _path << std::endl;
    return;
  }

  std::stringstream report;

  for (const auto& data : _data) {
    report << data->toString(_separator) << std::endl;
  }

  outputFile << report.str();
  outputFile.close();

  std::cout << "Report generated and saved to " << _path << std::endl;
}