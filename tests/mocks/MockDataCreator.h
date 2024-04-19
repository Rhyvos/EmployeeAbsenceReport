#ifndef MOCK_DATA_CREATOR_H
#define MOCK_DATA_CREATOR_H

#include <gmock/gmock.h>
#include "IDataCreator.h"

class MockDataCreator : public IDataCreator {
 public:
  MOCK_METHOD(
      std::unique_ptr<IData>, create, (const std::string& rawData), (override));
};

#endif // MOCK_DATA_CREATOR_H
