// Copyright (c) 2021, Kanda-Mashiro. All rights reserved.
//
// Use of this code is governed by a MIT-style license
// that can be found in the LICENSE file.


#include "config-cpp/utils.h"


namespace cc
{
namespace utils
{
namespace str
{


std::string to_upper(const std::string& str)
{
  std::string ret;
  ret.resize(str.size());
  std::transform(str.cbegin(), str.cend(), ret.begin(), std::toupper);
  return ret;
}

std::string to_lower(const std::string& str)
{
  std::string ret;
  ret.resize(str.size());
  std::transform(str.cbegin(), str.cend(), ret.begin(), std::tolower);
  return ret;
}


} // namespace str
} // namespace utils
} // namespace cc
