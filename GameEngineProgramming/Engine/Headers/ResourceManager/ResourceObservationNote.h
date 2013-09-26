
#pragma once

#include <Patterns/Observer.h>
#include <Tests/TDK/InterfaceAPI.h>
#include "Resource.h"

class ResourceObservedNote :
	public ObservedNote
{
public:
	Resource * Resource;

	std::size_t CurrentSize;
	std::size_t SizeDifference;
};