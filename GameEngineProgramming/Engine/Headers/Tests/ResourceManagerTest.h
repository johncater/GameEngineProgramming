
#pragma once

#include <Tests/TDK/TDK.h>
#include <ResourceManager/ResourceManager.h>
#include <ResourceManager/PixelMap.h>

Test( ResourceManager_GetSetBudgets )
{
	std::size_t requestSize = 100;

	auto rm = ResourceManager::Instance( );

	rm->SetMemoryBudget( MemType::System, requestSize );
	rm->SetMemoryBudget( MemType::Video, requestSize );

	TestAssertIsTrue( requestSize == rm->GetMemoryBudget( MemType::System ) );
	TestAssertIsTrue( requestSize == rm->GetMemoryBudget( MemType::Video ) );
}

Test( ResourceManager_GetUsages )
{
	PixelMap texture( 10, 10 );

	auto rm = ResourceManager::Instance( );
	rm->AddResource( PackageDomain::Static, &texture );

	TestAssertIsTrue( texture.GetSize( ) == rm->GetMemoryUsage( MemType::Video ) );
}

Test( ResourceManager_GetPackage )
{
	auto rm = ResourceManager::Instance( );
	rm->GetPackage( PackageDomain::Static );
	rm->GetPackage( PackageDomain::Dynamic );

	TestFailMessage( "Needs to be updated, no testing actually done" );
}