#include "Output.h"
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>

Output::Output(std::shared_ptr<Employee> emp, int total, int sick, int benefit)
    : _employee(emp),
      _totalLeaves(total),
      _sickLeaves(sick),
      _benefit(benefit) {}

std::string Output::toString(std::string separator) const {
  std::stringstream ss;
  ss << _employee->toString(separator) << separator << _employee->getAge()
     << separator << _totalLeaves << separator << _sickLeaves << separator
     << _benefit;
  return ss.str();
}
