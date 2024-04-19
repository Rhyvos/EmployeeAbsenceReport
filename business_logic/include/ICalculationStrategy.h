#ifndef ICALCULATIONSTRATEGY_H
#define ICALCULATIONSTRATEGY_H

#include <set>
#include <tuple>
#include <utility>
#include "Absence.h"
#include "Employee.h"

class ICalculationStrategy {
 public:
  virtual std::tuple<int, int, int> calculate(
      std::shared_ptr<Employee> employee,
      const std::set<std::shared_ptr<Absence>>& absences) = 0;
  virtual ~ICalculationStrategy() = default;
};

#endif // ICALCULATIONSTRATEGY_H