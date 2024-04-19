#ifndef BASICREPORTGENERATOR_H
#define BASICREPORTGENERATOR_H

#include <set>
#include <string>
#include "IOutput.h"
#include "IReportGenerator.h"

class BasicReportGenerator : public IReportGenerator {
 protected:
  std::set<std::shared_ptr<IOutput>> _data;

 public:
  BasicReportGenerator();
  void addData(std::shared_ptr<IOutput> data) override;

  void addData(std::set<std::shared_ptr<IOutput>> new_data);
};

#endif // BASICREPORTGENERATOR_H