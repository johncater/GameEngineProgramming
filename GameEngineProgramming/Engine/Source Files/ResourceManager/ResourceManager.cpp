
#include <ResourceManager\ResourceManager.h>

ResourceManager * ResourceManager::Instance()
{
	throw nullptr;
}

ResourceManager::ResourceManager()
{
	throw nullptr;
}

void ResourceManager::AutoLoadRequestedAssets( bool shouldAutoLoad )
{
	throw nullptr;
}

void ResourceManager::LoadPackage( ResourcePackage * package )
{
	throw nullptr;
}

void ResourceManager::AddResource( PackageDomain domain, Resource * newResource )
{
	throw nullptr;
}

void ResourceManager::RemoveResource( Resource * resource )
{
	throw nullptr;
}

void ResourceManager::SetMemoryBudget( MemType memoryType, std::size_t byteCount )
{
	throw nullptr;
}

std::size_t ResourceManager::GetMemoryBudget( MemType memoryType )
{
	throw nullptr;
}

std::size_t ResourceManager::GetMemoryUsage( MemType memoryType )
{
	throw nullptr;
}

ResourcePackage * ResourceManager::GetPackage( PackageDomain domain )
{
	throw nullptr;
}
