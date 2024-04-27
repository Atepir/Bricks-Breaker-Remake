#ifndef __TEXTURE_HPP
#define __TEXTURE_HPP

#include <SDL.h>
#include <string>
#include <iostream>

namespace Graphics
{
	using Type_SDL_Texture = SDL_Texture *;

	class Texture
	{
	private:
		int mWidth, mHeight;
		std::string mName;
		Type_SDL_Texture mTexture;

	public:
		Texture();
		Texture(Type_SDL_Texture pTexture, int pWidth, int pHeight, std::string pName);
		~Texture();

		void setTexture(Type_SDL_Texture pTexture);
		Type_SDL_Texture getTexture();

		int getWidth() const { return mWidth; }
		int getHeight() const { return mHeight; }
		std::string getName() const { return mName; }

		friend std::ostream &operator<<(std::ostream &os, Texture texture)
		{
			os << "Texture: " << texture.getName() << " Width: " << texture.getWidth() << " Height: " << texture.getHeight() << " SDL Texture: " << texture.getTexture();
			return os;
		};
	};
}

#endif