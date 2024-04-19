#include "EmployeeSelector.h"
#include <string_view>
#include <vector>

std::vector<std::string_view>
EmployeeSelector::select(const std::vector<std::string_view>& fields) const {
  if (fields.size() < 5) return {};
  return {fields[0], fields[1], fields[2], fields[3], fields[4]};
}