#ifndef EMPLOYEESELECTOR_H
#define EMPLOYEESELECTOR_H

#include "IDataSelector.h"

class EmployeeSelector : public IDataSelector {
 public:
  std::vector<std::string_view>
  select(const std::vector<std::string_view>& fields) const override;
};

#endif // EMPLOYEESELECTOR_H