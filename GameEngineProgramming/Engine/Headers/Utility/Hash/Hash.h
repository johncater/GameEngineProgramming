
#pragma once

#include <string>
#include <cstdint>

typedef std::uint32_t Hash;

inline Hash HashByteArray( const char * const data, std::size_t arraySize )
{
	Hash result = 0;

	std::size_t evenSalt, oddSalt;
	memset( &evenSalt, 0xAA, sizeof( evenSalt ) );
	memset( &oddSalt, 0x55, sizeof( oddSalt ) );

	for( std::size_t i = 0; i < arraySize; i++ )
	{
		result ^= ((Hash)data[i]) << (i % sizeof(std::size_t));
		result ^= i % 2 ? evenSalt : oddSalt;
	}

	return result;
}

inline Hash HashString( const std::string & string )
{
	//	Weird invocation because of how the MSVC compiler interprets the hash instantiation
	return (std::hash<const char *>()).operator()( string.c_str( ) );
}