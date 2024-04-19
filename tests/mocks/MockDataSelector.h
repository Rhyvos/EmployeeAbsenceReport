#ifndef MOCK_DATA_SELECTOR_H
#define MOCK_DATA_SELECTOR_H

#include <gmock/gmock.h>
#include "IDataSelector.h"

class MockDataSelector : public IDataSelector {
 public:
  MOCK_METHOD(
      std::vector<std::string_view>, select,
      (const std::vector<std::string_view>& fields), (const, override));
};

#endif // MOCK_DATA_SELECTOR_H
