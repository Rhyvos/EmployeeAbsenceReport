#ifndef ABSENCESELECTOR_H
#define ABSENCESELECTOR_H

#include "IDataSelector.h"

class AbsenceSelector : public IDataSelector {
 public:
  std::vector<std::string_view>
  select(const std::vector<std::string_view>& fields) const override;
};

#endif // ABSENCESELECTOR_H