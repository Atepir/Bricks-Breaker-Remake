#include "graphics/Texture.hpp"

using namespace Graphics;

Texture::Texture()
{
	mTexture = nullptr;
}

Texture::Texture(SDL_Texture *pTexture, int pWidth, int pHeight, std::string pName)
{
	mTexture = pTexture;
	mWidth = pWidth;
	mHeight = pHeight;
	mName = pName;
}

Texture::~Texture()
{
	SDL_DestroyTexture(getTexture());
}

void Texture::setTexture(SDL_Texture *pTexture)
{
	mTexture = pTexture;
}

SDL_Texture *Texture::getTexture()
{
	return mTexture;
}