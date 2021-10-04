#include <config-cpp/value_type.h>
#include <gtest/gtest.h>


TEST(test_value_type, GenValueTypeFromString)
{
  using namespace cc;
  ASSERT_TRUE(GenValueTypeFrom("UNDEFINE") == ValueType::UNDEFINE);
  ASSERT_TRUE(GenValueTypeFrom("EMPTY") == ValueType::EMPTY);
  ASSERT_TRUE(GenValueTypeFrom("INTEGER") == ValueType::INTEGER);
  ASSERT_TRUE(GenValueTypeFrom("FLOAT") == ValueType::FLOAT);
  ASSERT_TRUE(GenValueTypeFrom("BOOLEAN") == ValueType::BOOLEAN);
  ASSERT_TRUE(GenValueTypeFrom("STRING") == ValueType::STRING);
  ASSERT_TRUE(GenValueTypeFrom("LIST") == ValueType::LIST);
  ASSERT_TRUE(GenValueTypeFrom("DICT") == ValueType::DICT);
}

TEST(test_value_type, GenValueTypeFromNumber)
{
  using namespace cc;
  ASSERT_TRUE(GenValueTypeFrom(0) == ValueType::UNDEFINE);
  ASSERT_TRUE(GenValueTypeFrom(1) == ValueType::EMPTY);
  ASSERT_TRUE(GenValueTypeFrom(2) == ValueType::INTEGER);
  ASSERT_TRUE(GenValueTypeFrom(3) == ValueType::FLOAT);
  ASSERT_TRUE(GenValueTypeFrom(4) == ValueType::BOOLEAN);
  ASSERT_TRUE(GenValueTypeFrom(5) == ValueType::STRING);
  ASSERT_TRUE(GenValueTypeFrom(6) == ValueType::LIST);
  ASSERT_TRUE(GenValueTypeFrom(7) == ValueType::DICT);
}

TEST(test_value_type, PrintValueType)
{
  using namespace cc;
  {
    std::stringstream stream;
    stream << ValueType::UNDEFINE;
    ASSERT_TRUE(stream.str() == "UNDEFINE");
  }
  {
    std::stringstream stream;
    stream << ValueType::EMPTY;
    ASSERT_TRUE(stream.str() == "EMPTY");
  }
  {
    std::stringstream stream;
    stream << ValueType::INTEGER;
    ASSERT_TRUE(stream.str() == "INTEGER");
  }
  {
    std::stringstream stream;
    stream << ValueType::FLOAT;
    ASSERT_TRUE(stream.str() == "FLOAT");
  }
  {
    std::stringstream stream;
    stream << ValueType::BOOLEAN;
    ASSERT_TRUE(stream.str() == "BOOLEAN");
  }
  {
    std::stringstream stream;
    stream << ValueType::STRING;
    ASSERT_TRUE(stream.str() == "STRING");
  }
  {
    std::stringstream stream;
    stream << ValueType::LIST;
    ASSERT_TRUE(stream.str() == "LIST");
  }
  {
    std::stringstream stream;
    stream << ValueType::DICT;
    ASSERT_TRUE(stream.str() == "DICT");
  }
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
