#ifndef IDATA_H
#define IDATA_H

#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include "IOutput.h"

class IData : IOutput {
 public:
  virtual ~IData() = default;
  virtual void print() const = 0;
  virtual bool isValid() const = 0;
  virtual size_t fieldCount() const = 0;
  virtual bool fill(const std::vector<std::string_view>& fields) = 0;
  virtual std::string getId() const = 0;
};

struct CompareDataPtr {
  bool operator()(
      const std::shared_ptr<IData>& lhs,
      const std::shared_ptr<IData>& rhs) const {
    return lhs->getId() < rhs->getId();
  }
};

#endif // IDATA_H