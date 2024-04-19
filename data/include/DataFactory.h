#ifndef DATAFACTORY_H
#define DATAFACTORY_H

#include "IDataCreator.h"
#include "IDataSelector.h"

#include <algorithm>
#include <iostream>
#include <memory>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

template <typename T>
class DataFactory : public IDataCreator {
  std::unique_ptr<IDataSelector> _selector;

 public:
  explicit DataFactory(std::unique_ptr<IDataSelector> sel)
      : _selector(std::move(sel)) {}
  std::unique_ptr<IData> create(const std::string& rawData) override {
    std::vector<std::string_view> values;
    std::string_view delimiter(";");
    std::ranges::for_each(
        rawData | std::views::split(delimiter), [&values](auto&& value) {
          values.push_back(std::string_view(value));
        });

    auto selectedFields = _selector->select(values);
    auto instance = std::make_unique<T>();
    if (instance->fill(selectedFields) && instance->isValid()) {
      return instance;
    } else {
      std::cerr << "Failed to create a valid object due to incorrect data."
                << std::endl;
      return nullptr;
    }
  }
};

#endif // DATAFACTORY_H