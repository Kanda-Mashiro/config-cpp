// Copyright (c) 2021, Kanda-Mashiro. All rights reserved.
//
// Use of this code is governed by a MIT-style license
// that can be found in the LICENSE file.


#include "config-cpp/config_file_type.h"


namespace cc
{


ConfigFileType GenConfigFileTypeFrom(const std::string& str)
{
  std::string upper = utils::str::to_upper(str); 
#define XX(from, to) \
  if (upper == from) \
    return ConfigFileType::to;
  XX("INI", INI)
  XX("XML", XML)
  XX("JSON", JSON)
  XX("YAML", YAML)
#undef XX
  return ConfigFileType::UNKNOWN;
}

ConfigFileType GenConfigFileTypeFrom(std::uint8_t num)
{
#define XX(from, to) \
  if (num == from) \
    return ConfigFileType::to;
  XX(1, INI)
  XX(2, XML)
  XX(3, JSON)
  XX(4, YAML)
#undef XX
  return ConfigFileType::UNKNOWN;
}

std::ostream& operator<<(std::ostream& stream, const ConfigFileType& file_type)
{
  switch (file_type)
  {
#define XX(from, to) \
    case ConfigFileType::from: \
      return stream << to;
    XX(INI, "INI")
    XX(XML, "XML")
    XX(JSON, "JSON")
    XX(YAML, "YAML")
#undef XX
    default:
      return stream << "UNKNOWN";
  }
  return stream << "UNKNOWN";
}


} // namespace cc
