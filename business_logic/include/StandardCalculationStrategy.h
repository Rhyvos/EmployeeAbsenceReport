#ifndef STANDARDCALCULATIONSTRATEGY_H
#define STANDARDCALCULATIONSTRATEGY_H

#include "ICalculationStrategy.h"

#include <algorithm>
#include <numeric>
#include <ranges>
#include <tuple>
#include <vector>

class StandardCalculationStrategy : public ICalculationStrategy {
 private:
  std::string _from;
  std::string _to;

 public:
  StandardCalculationStrategy(std::string from, std::string to)
      : _from(from), _to(to) {}

  std::tuple<int, int, int> calculate(
      std::shared_ptr<Employee> employee,
      const std::set<std::shared_ptr<Absence>>& absences) override {
    auto filteredAbsences =
        absences |
        std::views::filter(
            [employee, this](const std::shared_ptr<Absence>& absence) {
              return absence->getId() == employee->getId() &&
                     absence->isBetween(_from, _to);
            });

    std::vector<std::shared_ptr<Absence>> relevantAbsences(
        filteredAbsences.begin(), filteredAbsences.end());

    int totalDays = std::accumulate(
        relevantAbsences.begin(), relevantAbsences.end(), 0,
        [this](int sum, const std::shared_ptr<Absence>& a) {
          return sum + a->getDuration(_from, _to);
        });

    int sickLeaveLimit = 33;
    int sickDays = std::min(totalDays, sickLeaveLimit);
    int benefitDays = std::max(0, totalDays - sickLeaveLimit);

    return {totalDays, sickDays, benefitDays};
  }
};

#endif // STANDARDCALCULATIONSTRATEGY_H