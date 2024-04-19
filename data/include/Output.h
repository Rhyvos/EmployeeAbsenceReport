#ifndef OUTPUT_H
#define OUTPUT_H

#include <memory>
#include <string>
#include "Employee.h"
#include "IOutput.h"

class Output : public IOutput {
 public:
  std::shared_ptr<Employee> _employee;
  int _totalLeaves;
  int _sickLeaves;
  int _benefit;

  Output(std::shared_ptr<Employee> emp, int total, int sick, int benefit);
  std::string toString(std::string separator = " ") const override;
};

#endif // OUTPUT_H