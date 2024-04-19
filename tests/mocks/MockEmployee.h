#ifndef MOCK_EMPLOYEE_H
#define MOCK_EMPLOYEE_H

#include "Employee.h"
#include "gmock/gmock.h"

class MockEmployee : public Employee {
 public:
  MOCK_METHOD(void, print, (), (const, override));
  MOCK_METHOD(size_t, fieldCount, (), (const, override));
  MOCK_METHOD(
      bool, fill, (const std::vector<std::string_view>& fields), (override));
  MOCK_METHOD(bool, isValid, (), (const, override));
  MOCK_METHOD(
      std::string, toString, (std::string separator), (const, override));
  MOCK_METHOD(std::string, getId, (), (const, override));
  MOCK_METHOD(int, getAge, (), (const));
};

#endif // MOCK_EMPLOYEE_H
