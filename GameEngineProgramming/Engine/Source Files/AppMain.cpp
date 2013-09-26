
#include <Tests/Tests.h>

void RunTests( )
{
#ifdef TESTS_ENABLED
	TestManager::AutoCatchExceptions( true );
	TestManager::UseSmartDebugOnAssert( false );
	TestManager::RunTests( );
#endif
}

#ifdef main
#undef  main
#endif
int main( )
{
	RunTests( );

	return 0;
}