#include <config-cpp/config_file_type.h>
#include <gtest/gtest.h>


TEST(test_config_file_type, GenConfigFileTypeFromString)
{
  using namespace cc;
  ASSERT_TRUE(GenConfigFileTypeFrom("UNKNOWN") == ConfigFileType::UNKNOWN);
  ASSERT_TRUE(GenConfigFileTypeFrom("INI") == ConfigFileType::INI);
  ASSERT_TRUE(GenConfigFileTypeFrom("XML") == ConfigFileType::XML);
  ASSERT_TRUE(GenConfigFileTypeFrom("JSON") == ConfigFileType::JSON);
  ASSERT_TRUE(GenConfigFileTypeFrom("YAML") == ConfigFileType::YAML);
  ASSERT_TRUE(GenConfigFileTypeFrom("") == ConfigFileType::UNKNOWN);
}

TEST(test_config_file_type, GenConfigFileTypeFromNumber)
{
  using namespace cc;
  ASSERT_TRUE(GenConfigFileTypeFrom(0) == ConfigFileType::UNKNOWN);
  ASSERT_TRUE(GenConfigFileTypeFrom(1) == ConfigFileType::INI);
  ASSERT_TRUE(GenConfigFileTypeFrom(2) == ConfigFileType::XML);
  ASSERT_TRUE(GenConfigFileTypeFrom(3) == ConfigFileType::JSON);
  ASSERT_TRUE(GenConfigFileTypeFrom(4) == ConfigFileType::YAML);
  ASSERT_TRUE(GenConfigFileTypeFrom(255) == ConfigFileType::UNKNOWN);
}

TEST(test_config_file_type, PrintConfigFileType)
{
  using namespace cc;
  {
    std::stringstream stream;
    stream << ConfigFileType::UNKNOWN;
    ASSERT_TRUE(stream.str() == "UNKNOWN");
  }
  {
    std::stringstream stream;
    stream << ConfigFileType::INI;
    ASSERT_TRUE(stream.str() == "INI");
  }
  {
    std::stringstream stream;
    stream << ConfigFileType::XML;
    ASSERT_TRUE(stream.str() == "XML");
  }
  {
    std::stringstream stream;
    stream << ConfigFileType::JSON;
    ASSERT_TRUE(stream.str() == "JSON");
  }
  {
    std::stringstream stream;
    stream << ConfigFileType::YAML;
    ASSERT_TRUE(stream.str() == "YAML");
  }
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
