// Copyright (c) 2021, Kanda-Mashiro. All rights reserved.
//
// Use of this code is governed by a MIT-style license
// that can be found in the LICENSE file.


#include "config-cpp/value_type.h"


namespace cc
{


ValueType GenValueTypeFrom(const std::string& str)
{
  std::string upper = utils::str::to_upper(str);
#define XX(from, to) \
  if (upper == from) \
    return ValueType::to;
  XX("EMPTY", EMPTY)
  XX("INTEGER", INTEGER)
  XX("FLOAT", FLOAT)
  XX("BOOLEAN", BOOLEAN)
  XX("STRING", STRING)
  XX("LIST", LIST)
  XX("DICT", DICT)
#undef XX
  return ValueType::UNDEFINE;
}

ValueType GenValueTypeFrom(std::uint8_t num)
{
#define XX(from, to) \
  if (num == from) \
    return ValueType::to;
  XX(1, EMPTY)
  XX(2, INTEGER)
  XX(3, FLOAT)
  XX(4, BOOLEAN)
  XX(5, STRING)
  XX(6, LIST)
  XX(7, DICT)
#undef XX
  return ValueType::UNDEFINE;
}

std::ostream& operator<<(std::ostream& stream, const ValueType& value_type)
{
  switch (value_type)
  {
#define XX(from, to) \
    case ValueType::from: \
      return stream << to;
    XX(EMPTY, "EMPTY")
    XX(INTEGER, "INTEGER")
    XX(FLOAT, "FLOAT")
    XX(BOOLEAN, "BOOLEAN")
    XX(STRING, "STRING")
    XX(LIST, "LIST")
    XX(DICT, "DICT")
#undef XX
    default:
      return stream << "UNDEFINE";
  }
  return stream << "UNDEFINE";
}


} // namespace cc
