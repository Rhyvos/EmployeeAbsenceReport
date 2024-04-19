#ifndef CONSOLEREPORTGENERATOR_H
#define CONSOLEREPORTGENERATOR_H

#include <set>
#include <string>
#include "BasicReportGenerator.h"
#include "IOutput.h"

class ConsoleReportGenerator : public BasicReportGenerator {
 public:
  ConsoleReportGenerator();
  void generateReport() const override;
};

#endif // CONSOLEREPORTGENERATOR_H