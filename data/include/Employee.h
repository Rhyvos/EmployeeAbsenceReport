#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <string_view>
#include <vector>
#include "IData.h"

class Employee : public IData {
  std::string _firstName;
  std::string _lastName;
  std::string _employeeId;
  std::string _birth;
  char _gender;
  bool _valid;

 public:
  Employee();

  bool operator<(const Employee& other) const;

  void print() const override;
  size_t fieldCount() const override;
  bool fill(const std::vector<std::string_view>& fields) override;
  bool isValid() const override;
  std::string toString(std::string separator = " ") const override;
  std::string getId() const override;
  int getAge() const;
};

using CompareEmployeeDataPtr = CompareDataPtr;

#endif // EMPLOYEE_H