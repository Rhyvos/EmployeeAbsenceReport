#ifndef CSVDATALOADER_H
#define CSVDATALOADER_H

#include <fstream>
#include <memory>
#include <set>
#include <string>
#include "IData.h"
#include "IDataCreator.h"
#include "IDataLoader.h"

template <typename Comparator = std::less<std::shared_ptr<IData>>>
class CSVDataLoader : public IDataLoader<Comparator> {
 private:
  std::string _filePath;
  std::unique_ptr<IDataCreator> _dataCreator;
  std::set<std::shared_ptr<IData>, Comparator> _data;

 public:
  CSVDataLoader(const std::string& path, std::unique_ptr<IDataCreator> creator)
      : _filePath(path), _dataCreator(std::move(creator)) {}

  void loadData() override {
    std::ifstream file(_filePath);
    if (!file.is_open()) {
      throw std::runtime_error("Failed to open file: " + _filePath);
    }

    std::string line;
    while (std::getline(file, line)) {
      auto instance = _dataCreator->create(line);
      if (instance) {
        _data.insert(std::move(instance));
      }
    }
  }

  std::set<std::shared_ptr<IData>, Comparator> getData() override {
    return _data;
  }
};

#endif // CSVDATALOADER_H