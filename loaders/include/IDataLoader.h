#ifndef IDATALOADER_H
#define IDATALOADER_H

#include <memory>
#include <set>
#include <string>
#include "IData.h"

template <typename Comparator = std::less<std::shared_ptr<IData>>>
class IDataLoader {
 public:
  virtual ~IDataLoader() = default;
  virtual void loadData() = 0;
  virtual std::set<std::shared_ptr<IData>, Comparator> getData() = 0;
};

#endif // IDATALOADER_H