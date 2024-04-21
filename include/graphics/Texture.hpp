#ifndef __TEXTURE_HPP
#define __TEXTURE_HPP

#include <SDL.h>
#include <string>
#include <iostream>

namespace Graphics
{
	class Texture
	{
	private:
		int mWidth, mHeight;
		std::string mName;
		SDL_Texture *mTexture;

	public:
		Texture();
		Texture(SDL_Texture *pTexture, int pWidth, int pHeight, std::string pName);
		~Texture();

		void setTexture(SDL_Texture *pTexture);
		SDL_Texture *getTexture();

		int getWidth() const { return mWidth; }
		int getHeight() const { return mHeight; }
		std::string getName() const { return mName; }

		// overload the ostream operator
		friend std::ostream &operator<<(std::ostream &os, Texture texture)
		{
			os << "Texture: " << texture.getName() << " Width: " << texture.getWidth() << " Height: " << texture.getHeight() << " SDL Texture: " << texture.getTexture();
			return os;
		};
	};
}

#endif