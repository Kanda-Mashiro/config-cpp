// Copyright (c) 2021, Kanda-Mashiro. All rights reserved.
//
// Use of this code is governed by a MIT-style license
// that can be found in the LICENSE file.


#ifndef __CONFIG_CPP_UTILS_H__
#define __CONFIG_CPP_UTILS_H__


#include <string>


namespace cc
{
namespace utils
{
namespace str
{


// 将字符串内的全部英文字符转换为大写
std::string to_upper(const std::string& str);
// 将字符串内的全部英文字符转换为小写
std::string to_lower(const std::string& str);


} // namespace str
} // namespace utils
} // namespace cc


#endif // __CONFIG_CPP_UTILS_H__
