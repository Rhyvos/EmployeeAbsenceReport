#include "ConsoleReportGenerator.h"
#include <iostream>
#include <sstream>

ConsoleReportGenerator::ConsoleReportGenerator() {}

void ConsoleReportGenerator::generateReport() const {
  std::stringstream report;

  for (const auto& data : _data) {
    report << data->toString() << std::endl;
  }

  std::cout << report.str() << std::endl;
}