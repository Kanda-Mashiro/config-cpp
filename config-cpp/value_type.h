// Copyright (c) 2021, Kanda-Mashiro. All rights reserved.
//
// Use of this code is governed by a MIT-style license
// that can be found in the LICENSE file.


#ifndef __CONFIG_CPP_VALUE_TYPE_H__
#define __CONFIG_CPP_VALUE_TYPE_H__


#include <cstdint>
#include <iostream>

#include "config-cpp/utils.h"


namespace cc
{


// 值的枚举类型：
// 1. 整数类型；
// 2. 空类型；
// 3. 浮点数类型；
// 4. 布尔类型；
// 5. 字符串类型；
// 6. 列表类型；
// 7. 字典类型。
enum class ValueType : std::uint8_t
{
  UNDEFINE = 0,
  EMPTY,
  INTEGER,
  FLOAT,
  BOOLEAN,
  STRING,
  LIST,
  DICT,
};

// 每一种值类型都有对应的字符串进行表示
// 可以通过字符串或数字（不推荐）生成相应的对象
ValueType GenValueTypeFrom(const std::string& str);
ValueType GenValueTypeFrom(std::uint8_t num);

std::ostream& operator<<(std::ostream& stream, const ValueType& value_type);


} // namespace cc


#endif // __CONFIG_CPP_VALUE_TYPE_H__
