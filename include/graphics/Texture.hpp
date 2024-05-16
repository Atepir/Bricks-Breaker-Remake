#ifndef __TEXTURE_HPP
#define __TEXTURE_HPP

#include <SDL.h>
#include <string>
#include <iostream>

namespace Graphics
{
	using Type_SDL_Texture = SDL_Texture *;

	/**
	 * @brief Represents a texture
	 */
	class Texture
	{
	private:
		int mWidth, mHeight;
		std::string mName;
		Type_SDL_Texture mTexture;

	public:
		Texture() : mTexture(nullptr) {}
		Texture(Type_SDL_Texture pTexture, int pWidth, int pHeight, std::string pName)
			: mTexture(pTexture), mWidth(pWidth), mHeight(pHeight), mName(pName) {}
		~Texture() { SDL_DestroyTexture(getTexture()); }

		inline void setTexture(Type_SDL_Texture pTexture) { mTexture = pTexture; }
		inline Type_SDL_Texture getTexture() const { return mTexture; }

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