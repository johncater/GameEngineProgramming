
#pragma once

#include <Patterns/Observer.h>

class Resource :
	public Subject
{
public:
	virtual ~Resource( )
	{
		
	}

	virtual std::size_t GetSize( ) = 0;
};