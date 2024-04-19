#include "BasicReportGenerator.h"

BasicReportGenerator::BasicReportGenerator() {}

void BasicReportGenerator::addData(std::shared_ptr<IOutput> data) {
  _data.insert(data);
}

void BasicReportGenerator::addData(
    std::set<std::shared_ptr<IOutput>> new_data) {
  _data.merge(new_data);
}