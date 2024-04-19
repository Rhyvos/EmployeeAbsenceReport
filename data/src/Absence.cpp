#include "Absence.h"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>

Absence::Absence() : _startDate(""), _endDate(""), _employeeId("") {}

void Absence::print() const {
  std::cout << toString() << std::endl;
}

bool Absence::isValid() const {
  return !_startDate.empty() && !_endDate.empty() && _startDate <= _endDate;
}

std::string Absence::toString(std::string separator) const {
  std::vector<std::string> data = {_startDate, _endDate};
  return std::accumulate(
      data.begin(), data.end(), _employeeId,
      [&separator](const std::string& a, const std::string& b) -> std::string {
        return a + separator + b;
      });
}

int Absence::getDuration(std::string from, std::string to) const {
  std::string dateFormat = "%d.%m.%Y";
  std::tm start_tm = {}, end_tm = {}, from_tm = {}, to_tm = {};

  std::istringstream start_ss(_startDate);
  start_ss >> std::get_time(&start_tm, dateFormat.c_str());
  std::istringstream end_ss(_endDate);
  end_ss >> std::get_time(&end_tm, dateFormat.c_str());
  std::istringstream from_ss(from);
  from_ss >> std::get_time(&from_tm, dateFormat.c_str());
  std::istringstream to_ss(to);
  to_ss >> std::get_time(&to_tm, dateFormat.c_str());

  time_t start_time = std::mktime(&start_tm);
  time_t end_time = std::mktime(&end_tm);
  time_t from_time = std::mktime(&from_tm);
  time_t to_time = std::mktime(&to_tm);

  if (start_time != -1 && end_time != -1 && from_time != -1 && to_time != -1) {
    time_t start_max = std::max(start_time, from_time);
    time_t end_min = std::min(end_time, to_time);
    if (start_max <= end_min) {
      double seconds = difftime(end_min, start_max);
      int days = seconds / 86400 + 1;
      return days;
    }
  }
  return 0;
}

bool Absence::isBetween(std::string from, std::string to) const {
  std::string dateFormat = "%d.%m.%Y";
  std::tm tmStart = {};
  std::tm tmEnd = {};
  std::tm tmFrom = {};
  std::tm tmTo = {};

  std::istringstream ssStart(_startDate);
  std::istringstream ssEnd(_endDate);
  std::istringstream ssFrom(from);
  std::istringstream ssTo(to);

  ssStart >> std::get_time(&tmStart, dateFormat.c_str());
  ssEnd >> std::get_time(&tmEnd, dateFormat.c_str());
  ssFrom >> std::get_time(&tmFrom, dateFormat.c_str());
  ssTo >> std::get_time(&tmTo, dateFormat.c_str());

  if (ssStart.fail() || ssEnd.fail() || ssFrom.fail() || ssTo.fail()) {
    std::cerr << "Date parsing failed" << std::endl;
    return false;
  }

  std::time_t start = std::mktime(&tmStart);
  std::time_t end = std::mktime(&tmEnd);
  std::time_t fromTime = std::mktime(&tmFrom);
  std::time_t toTime = std::mktime(&tmTo);

  return (start <= toTime && end >= fromTime);
}

bool Absence::fill(const std::vector<std::string_view>& fields) {
  if (fields.size() != 3) return false;

  _employeeId = std::string(fields[0]);
  _startDate = std::string(fields[1]);
  _endDate = std::string(fields[2]);
  return true;
}

size_t Absence::fieldCount() const {
  return 3;
}

std::string Absence::getId() const {
  return _employeeId;
}