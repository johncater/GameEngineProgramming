
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Resource.h"

class PixelMap :
	public Resource
{
public:

	PixelMap( ) :
		m_Surface( nullptr )
	{
	}

	PixelMap( int width, int height )
	{
	}

	~PixelMap( )
	{
		if( m_Surface )
			SDL_FreeSurface( m_Surface );

		m_Surface = nullptr;
	}

	void LoadFromMemory( std::size_t dataSize, const char * data )
	{
		throw;
	}

	void LoadFromFile( const std::string & file )
	{
		throw;
		m_Surface = IMG_Load( file.c_str( ) );
	}

	const SDL_Surface * GetSurface( )
	{
		return m_Surface;
	}

	virtual std::size_t GetSize( ) override
	{
		throw nullptr;
	}

private:
	SDL_Surface * m_Surface;
};