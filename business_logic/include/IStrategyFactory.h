#ifndef ISTRATEGYFACTORY_H
#define ISTRATEGYFACTORY_H

#include <memory>
#include "Employee.h"
#include "ICalculationStrategy.h"

class IStrategyFactory {
 public:
  virtual std::unique_ptr<ICalculationStrategy>
  createStrategy(std::shared_ptr<Employee> employee) = 0;
  virtual ~IStrategyFactory() = default;
};

#endif // ISTRATEGYFACTORY_H