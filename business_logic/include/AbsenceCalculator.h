#ifndef ABSENCECALCULATOR_H
#define ABSENCECALCULATOR_H

#include <map>
#include <memory>
#include <tuple>
#include <vector>
#include "Absence.h"
#include "Employee.h"
#include "ICalculationStrategy.h"
#include "IStrategyFactory.h"
#include "Output.h"

class AbsenceCalculator {
 private:
  std::shared_ptr<Employee> _employee;
  std::set<std::shared_ptr<Absence>> _absences;
  std::unique_ptr<ICalculationStrategy> _strategy;

 public:
  AbsenceCalculator(
      std::shared_ptr<Employee> emp, std::set<std::shared_ptr<Absence>> abs,
      std::unique_ptr<IStrategyFactory> factory)
      : _employee(emp),
        _absences(abs),
        _strategy(factory->createStrategy(emp)) {}

  std::shared_ptr<Output> calculate() {
    auto [total, sick, benefit] = _strategy->calculate(_employee, _absences);
    return std::make_shared<Output>(_employee, total, sick, benefit);
  }
};

#endif // ABSENCECALCULATOR_H