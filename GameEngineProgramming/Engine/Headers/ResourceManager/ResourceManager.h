
#pragma once

/*
 * todo: Should the ResourceManager also act as a factory so that all resources are registered
 *	with it from the beginning? (Probably, will refactor later)
 *
 */

#include <Utility/Hash/STL.h>
#include <Patterns/Observer.h>
#include <Utility/Dictionary.h>
#include "Resource.h"
#include "ResourcePackage.h"


enum MemType
{
	System,	//	Regular memory
	Video	//	Video memory
};

enum PackageDomain
{
	Static,	//	Static resources stay in the game at all times
	Dynamic	//	Dynamic resources get flushed at each package load
};


#define OBSERVE_RESOURCE_SIZE_CHANGED 3001

class ResourceManager
	: public Observer
{
public:

	static ResourceManager * Instance( );

	ResourceManager( );

	/* Assets are loaded into the dynamic domain */
	void AutoLoadRequestedAssets( bool shouldAutoLoad );

	/* A package consists of number of assets in a ZIP, all packages loaded
	 *	are automatically placed in the dynamic domain. */
	void LoadPackage( ResourcePackage * package );

	template <typename T>
	T * GetResource( const std::string & resourceTag );

	void AddResource( PackageDomain domain, Resource * newResource );
	void RemoveResource( Resource * resource );

	void SetMemoryBudget( MemType memoryType, std::size_t byteCount );
	std::size_t GetMemoryBudget( MemType memoryType );

	std::size_t GetMemoryUsage( MemType memoryType );

	ResourcePackage * GetPackage( PackageDomain domain );
};

#include "ResourceManager.inl"
