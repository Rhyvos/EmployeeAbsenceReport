#include <iostream>

#include <cassert>
#include <fstream>
#include "Absence.h"
#include "AbsenceCalculator.h"
#include "AbsenceSelector.h"
#include "CSVDataLoader.h"
#include "CSVReportGenerator.h"
#include "ConsoleReportGenerator.h"
#include "DataFactory.h"
#include "Employee.h"
#include "EmployeeSelector.h"
#include "Output.h"
#include "StrategyFactory.h"

int main(int argc, char* argv[]) {
  if (argc < 5) {
    std::cerr << "Usage: " << argv[0]
              << " <inputPath> <outputPath> <fromDate> <toDate>" << std::endl;
    return 1;
  }

  std::string inputPath = argv[1];
  std::string outputPath = argv[2];
  std::string fromDate = argv[3];
  std::string toDate = argv[4];

  CSVDataLoader<CompareEmployeeDataPtr> employeeLoader(
      inputPath, std::make_unique<DataFactory<Employee>>(
                     std::make_unique<EmployeeSelector>()));
  CSVDataLoader absenceLoader(
      inputPath, std::make_unique<DataFactory<Absence>>(
                     std::make_unique<AbsenceSelector>()));

  employeeLoader.loadData();
  absenceLoader.loadData();
  auto employeeData = employeeLoader.getData();
  auto absenceData = absenceLoader.getData();
  std::set<std::shared_ptr<Employee>> employees;
  std::set<std::shared_ptr<Absence>> absences;
  std::vector<std::shared_ptr<Output>> output;

  std::transform(
      employeeData.begin(), employeeData.end(),
      std::inserter(employees, employees.end()),
      [](const std::shared_ptr<IData>& ptr) -> std::shared_ptr<Employee> {
        return std::dynamic_pointer_cast<Employee>(ptr);
      });

  std::transform(
      absenceData.begin(), absenceData.end(),
      std::inserter(absences, absences.end()),
      [](const std::shared_ptr<IData>& ptr) -> std::shared_ptr<Absence> {
        return std::dynamic_pointer_cast<Absence>(ptr);
      });

  for (const auto& employee : employees) {
    AbsenceCalculator calculator(
        employee, absences,
        std::make_unique<StrategyFactory>(fromDate, toDate));

    output.push_back(calculator.calculate());
  }

  ConsoleReportGenerator generator;
  generator.addData({output.begin(), output.end()});
  generator.generateReport();

  CSVReportGenerator csvGenerator(
      "/root/EmployeeAbsenceReport/application/test_data/output.csv", ";");
  csvGenerator.addData({output.begin(), output.end()});
  csvGenerator.generateReport();

  return 0;
}
