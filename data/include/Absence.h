#ifndef ABSENCE_H
#define ABSENCE_H

#include <ctime>
#include <string>
#include "IData.h"

class Absence : public IData {
 public:
  std::string _startDate;
  std::string _endDate;
  std::string _employeeId;

  Absence();

  bool operator<(const Absence& other) const;

  void print() const override;
  size_t fieldCount() const override;
  bool fill(const std::vector<std::string_view>& fields) override;
  bool isValid() const override;
  std::string toString(std::string separator = " ") const override;
  int getDuration(std::string from, std::string to) const;
  bool isBetween(std::string from, std::string to) const;
  std::string getId() const override;
};

#endif // ABSENCE_H