
#pragma once

#include <Patterns/Observer.h>

class Resource :
	public Subject
{
public:
	virtual ~Resource( )
	{
		
	}

	virtual void GetMemUsage( std::size_t & dynamicUsage, std::size_t & videoUsage ) = 0;
};