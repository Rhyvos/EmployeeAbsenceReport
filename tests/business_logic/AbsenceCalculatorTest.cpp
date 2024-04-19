#include "AbsenceCalculator.h"
#include <gtest/gtest.h>
#include "MockCalculationStrategy.h"
#include "MockEmployee.h"
#include "MockStrategyFactory.h"

using namespace testing;

TEST(AbsenceCalculatorTest, CalculateAbsences) {
  std::shared_ptr<MockEmployee> employee = std::make_shared<MockEmployee>();
  std::set<std::shared_ptr<Absence>> absences;
  auto strategyFactoryMockPtr = std::make_unique<MockStrategyFactory>();
  auto& strategyFactoryMock = *(strategyFactoryMockPtr.get());

  auto calculationStrategyMockPtr = std::make_unique<MockCalculationStrategy>();
  auto& calculationStrategyMock = *(calculationStrategyMockPtr.get());

  EXPECT_CALL(strategyFactoryMock, createStrategy(_))
      .Times(1)
      .WillOnce(Return(std::move(calculationStrategyMockPtr)));

  EXPECT_CALL(calculationStrategyMock, calculate(_, _))
      .Times(1)
      .WillOnce(Return(std::make_tuple(10, 5, 5)));

  AbsenceCalculator calculator(
      employee, absences, std::move(strategyFactoryMockPtr));
  auto result = calculator.calculate();
  EXPECT_EQ(result->_totalLeaves, 10);
  EXPECT_EQ(result->_sickLeaves, 5);
  EXPECT_EQ(result->_benefit, 5);
}
