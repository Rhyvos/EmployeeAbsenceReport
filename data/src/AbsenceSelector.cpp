#include "AbsenceSelector.h"
#include <string_view>
#include <vector>

std::vector<std::string_view>
AbsenceSelector::select(const std::vector<std::string_view>& fields) const {
  if (fields.size() < 7) return {};
  return {fields[2], fields[5], fields[6]};
}