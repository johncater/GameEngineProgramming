
#pragma once

#include <Utility/Hash/STL.h>
#include <unordered_map>

template <typename ValueType>
class Dictionary :
	public std::unordered_map< std::string, ValueType >
{
};