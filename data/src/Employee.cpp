#include "Employee.h"
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>

Employee::Employee()
    : _firstName(""),
      _lastName(""),
      _employeeId(""),
      _birth(""),
      _gender(' '),
      _valid(false) {}

void Employee::print() const {
  std::cout << toString() << std::endl;
}

size_t Employee::fieldCount() const {
  return 5;
}

bool Employee::fill(const std::vector<std::string_view>& fields) {
  if (fields.size() != fieldCount()) return false;

  _firstName = std::string(fields[0]);
  _lastName = std::string(fields[1]);
  _employeeId = std::string(fields[2]);
  _birth = std::string(fields[3]);
  _gender = fields[4][0];
  _valid = true;
  return _valid;
}

bool Employee::isValid() const {
  return _valid;
}

std::string Employee::toString(std::string separator) const {
  std::vector<std::string> data = {
      _lastName, _employeeId, _birth, std::string(1, _gender)};
  return std::accumulate(
      data.begin(), data.end(), _firstName,
      [&separator](const std::string& a, const std::string& b) -> std::string {
        return a + separator + b;
      });
}

std::string Employee::getId() const {
  return _employeeId;
}

/**
 * Calculates the age of an Employee based on their date of birth.
 *
 * The implementation involves some "magic" due to the manipulation of date and
 * time formats, and conversion between different time types. A more readable
 * and modern approach could be achieved using the `std::chrono` library, which
 * provides a safer and more intuitive interface for time calculations,
 * available since C++11.
 *
 * @return The age of the Employee as an integer. Returns 0 if the birth date is
 * invalid.
 */
int Employee::getAge() const {
  std::string dateFormat = "%d.%m.%Y";
  struct std::tm birth_tm = {};
  std::istringstream birth_ss(_birth);
  birth_ss >> std::get_time(&birth_tm, dateFormat.c_str());
  if (birth_tm.tm_year != -1) {
    time_t birth_time = std::mktime(&birth_tm);
    time_t current_time = std::time(nullptr);
    if (birth_time != -1 && current_time != -1) {
      double seconds = difftime(current_time, birth_time);
      int years = seconds / 31536000;
      return years;
    } else {
      return 0;
    }
  }
  return 0;
}