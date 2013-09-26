
#pragma once

#include <list>

class TestInjector;

class TestManager
{
public:
	static void RunTests( );
	static bool AutoCatchExceptions( );
	static void AutoCatchExceptions( bool autoCatchExceptions );

#ifdef _MSC_VER
	static bool UseSmartDebugOnAssert( );
	static void UseSmartDebugOnAssert( bool smartDebug );
#endif

protected:
	static void AddInjector(TestInjector * newInjector);
	friend class TestInjector;

private:
	static void CheckInjectorList( );
	static std::list<TestInjector *> * m_Injectors;
	static bool m_AutoCatchExceptions;

#ifdef _MSC_VER
	static bool m_UseSmartDebugOnAssert;
#endif
};

struct TestResult
{
	int TimeMS;
	bool TestPassed;

	/* Empty if TestPassed == true */
	std::string ErrorMessage;
};

typedef void (* TestFunc) ( );


class TestInjector
{
public:
	TestInjector(TestFunc function, std::string testName);

	TestResult RunTest( bool autoCatchExceptions );
	bool TestPassed() const;
	const std::string & TestName() const;

protected:
	bool m_TestPassed;

private:
	TestFunc	m_TestFunc;
	std::string	m_TestName;
};

#define Test(TestName)												\
	void _##TestName( );											\
	TestInjector _##TestName##_Injector( _##TestName, #TestName );	\
	inline void _##TestName( )


#include "Assert.h"