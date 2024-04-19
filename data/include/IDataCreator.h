#ifndef IDATACREATOR_H
#define IDATACREATOR_H

#include <memory>
#include <string>
#include "IData.h"

class IDataCreator {
 public:
  virtual ~IDataCreator() = default;

  virtual std::unique_ptr<IData> create(const std::string& rawData) = 0;
};

#endif // IDATACREATOR_H