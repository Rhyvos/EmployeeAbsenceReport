#ifndef IDATASELECTOR_H
#define IDATASELECTOR_H

#include <string_view>
#include <vector>

class IDataSelector {
 public:
  virtual ~IDataSelector() = default;

  virtual std::vector<std::string_view>
  select(const std::vector<std::string_view>& fields) const = 0;
};

#endif // IDATASELECTOR_H