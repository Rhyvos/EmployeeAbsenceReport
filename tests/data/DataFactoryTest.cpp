#include "DataFactory.h"
#include <gtest/gtest.h>
#include "Absence.h"
#include "IData.h"
#include "MockDataSelector.h"

using namespace testing;

TEST(DataFactoryTest, CreateValidData) {
  auto dataSelectorMockPtr = std::make_unique<MockDataSelector>();
  auto& dataSelectorMock = *(dataSelectorMockPtr.get());
  DataFactory<Absence> factory(std::move(dataSelectorMockPtr));

  std::string rawData = "field1;field2;field3";
  std::vector<std::string_view> fields = {"field1", "field2", "field3"};
  EXPECT_CALL(dataSelectorMock, select(_)).WillOnce(Return(fields));

  auto data = factory.create(rawData);
  EXPECT_TRUE(data != nullptr);
  EXPECT_TRUE(data->isValid());
  std::shared_ptr<IData> dataPtr{std::move(data)};
  auto absence = std::dynamic_pointer_cast<Absence>(dataPtr);
  EXPECT_EQ(absence->_employeeId, fields[0]);
  EXPECT_EQ(absence->_startDate, fields[1]);
  EXPECT_EQ(absence->_endDate, fields[2]);
}

TEST(DataFactoryTest, CreateInvalidData) {
  auto dataSelectorMockPtr = std::make_unique<MockDataSelector>();
  auto& dataSelectorMock = *(dataSelectorMockPtr.get());
  DataFactory<Absence> factory(std::move(dataSelectorMockPtr));

  std::string rawData = "field1;field2;field3";
  std::vector<std::string_view> fields = {"field1", "field2"};
  EXPECT_CALL(dataSelectorMock, select(_)).WillOnce(Return(fields));

  auto data = factory.create(rawData);
  EXPECT_TRUE(data == nullptr);
}