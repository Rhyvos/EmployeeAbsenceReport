#ifndef IREPORTGENERATOR_H
#define IREPORTGENERATOR_H

#include <memory>
#include <vector>
#include "IOutput.h"

class IReportGenerator {
 public:
  virtual ~IReportGenerator() = default;
  virtual void addData(std::shared_ptr<IOutput> data) = 0;
  virtual void generateReport() const = 0;
};

#endif // IREPORTGENERATOR_H