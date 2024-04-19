#ifndef CSVREPORTGENERATOR_H
#define CSVREPORTGENERATOR_H

#include <set>
#include <string>
#include "BasicReportGenerator.h"
#include "IOutput.h"

class CSVReportGenerator : public BasicReportGenerator {
 private:
  std::string _path;
  std::string _separator;

 public:
  CSVReportGenerator(std::string path, std::string separator);
  void generateReport() const override;
};

#endif // CSVREPORTGENERATOR_H