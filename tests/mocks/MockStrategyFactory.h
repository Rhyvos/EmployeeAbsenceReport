#ifndef MOCK_STRATEGY_FACTORY_H
#define MOCK_STRATEGY_FACTORY_H

#include <gmock/gmock.h>
#include "IStrategyFactory.h"

class MockStrategyFactory : public IStrategyFactory {
 public:
  MOCK_METHOD(
      std::unique_ptr<ICalculationStrategy>, createStrategy,
      (std::shared_ptr<Employee> employee), (override));
};

#endif // MOCK_STRATEGY_FACTORY_H