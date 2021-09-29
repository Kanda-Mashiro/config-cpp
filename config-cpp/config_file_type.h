// Copyright (c) 2021, Kanda-Mashiro. All rights reserved.
//
// Use of this code is governed by a MIT-style license
// that can be found in the LICENSE file.


#ifndef __CONFIG_CPP_CONFIG_FILE_TYPE_H__
#define __CONFIG_CPP_CONFIG_FILE_TYPE_H__


#include <cstdint>
#include <iostream>
#include <string>

#include "config-cpp/utils.h"


namespace cc
{


// 配置文件类型的枚举类，支持以下 4 种类型：
// 1. INI 文件格式；
// 2. XML 文件格式；
// 3. JSON 文件格式；
// 4. YAML 文件格式。
enum class ConfigFileType : std::uint8_t 
{
  UNKNOWN = 0,
  INI,
  XML,
  JSON,
  YAML,
};


// 每一种配置文件类型都有对应的字符串进行表示
// 可以通过字符串或数字（不推荐）生成相应的对象
ConfigFileType GenConfigFileTypeFrom(const std::string& str);
ConfigFileType GenConfigFileTypeFrom(std::uint8_t num);

std::ostream& operator<<(std::ostream& stream, const ConfigFileType& file_type);


} // namespace cc


#endif // __CONFIG_CPP_CONFIG_FILE_TYPE_H__
