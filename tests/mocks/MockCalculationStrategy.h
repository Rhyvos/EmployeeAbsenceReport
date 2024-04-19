#ifndef MOCK_CALCULATION_STRATEGY_H
#define MOCK_CALCULATION_STRATEGY_H

#include <gmock/gmock.h>
#include "ICalculationStrategy.h"

class MockCalculationStrategy : public ICalculationStrategy {
 public:
  MOCK_METHOD(
      (std::tuple<int, int, int>), calculate,
      (std::shared_ptr<Employee> employee,
       const std::set<std::shared_ptr<Absence>>& absences),
      (override));
};

#endif // MOCK_CALCULATION_STRATEGY_H
