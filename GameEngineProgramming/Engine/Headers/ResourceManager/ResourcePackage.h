
#pragma once

#include <list>
#include <string>

#include "Resource.h"

class ResourcePackage
{
public:
	std::list<Resource *> Resources;

	void LoadPackage( const std::string & packageLocation );

	Resource * GetResource( const std::string & resourceName );
};