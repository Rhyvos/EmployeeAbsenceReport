#ifndef STRATEGYFACTORY_H
#define STRATEGYFACTORY_H

#include <memory>
#include "Employee.h"
#include "ICalculationStrategy.h"
#include "IStrategyFactory.h"
#include "SeniorCalculationStrategy.h"
#include "StandardCalculationStrategy.h"

class StrategyFactory : public IStrategyFactory {
 private:
  std::string _from;
  std::string _to;

 public:
  StrategyFactory(std::string from, std::string to) : _from(from), _to(to) {}

  std::unique_ptr<ICalculationStrategy>
  createStrategy(std::shared_ptr<Employee> employee) override {
    int age = employee->getAge();
    if (age >= 50) {
      return std::make_unique<SeniorCalculationStrategy>(_from, _to);
    } else {
      return std::make_unique<StandardCalculationStrategy>(_from, _to);
    }
  }
};

#endif // STRATEGYFACTORY_H