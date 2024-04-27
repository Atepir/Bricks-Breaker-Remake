#ifndef __TEXTURE_HELPER_HPP
#define __TEXTURE_HELPER_HPP

#include <SDL.h>
#include <string>

#include "graphics/Texture.hpp"
#include "graphics/Renderer.hpp"

using namespace std;

namespace Graphics
{
    class TextureHelper
    {
    private:
        Type_SDL_Surface setSurface;

    public:
        /**
         * @brief Loads a tileset
         * @param pPath the path to the tileset
         */
        void loadTileset(string pPath)
        {
            setSurface = SDL_LoadBMP(pPath.c_str());
        }

        /**
         * @brief Loads a texture from the tileset
         * @param pName the name of the texture
         * @param pX  the x position of the texture in the tileset
         * @param pY the y position of the texture in the tileset
         * @param pWidth the width of the texture
         * @param pHeight the height of the texture
         * @param pDestX the x position of the texture in the window
         * @param pDestY  the y position of the texture in the window
         * @param pDestWidth the width of the texture in the window
         * @param pDestHeight the height of the texture in the window
         */
        inline std::shared_ptr<Texture> loadTexture(
            string pName,
            int pX,
            int pY,
            int pWidth,
            int pHeight,
            int pDestX,
            int pDestY,
            int pDestWidth,
            int pDestHeight)
        {
            SDL_Rect srcRect = {pX, pY, pWidth, pHeight};
            SDL_Rect destRect = {pDestX, pDestY, pDestWidth, pDestHeight};

            Type_SDL_Surface surface = SDL_CreateRGBSurface(0, pWidth + pDestX, pHeight + pDestY, 32, 0, 0, 0, 0);

            SDL_BlitScaled(setSurface, &srcRect, surface, &destRect);
            Type_SDL_Renderer renderer = Graphics::Renderer::getInstance()->getRenderer();
            Type_SDL_Texture texture = SDL_CreateTextureFromSurface(renderer, surface);
            return std::make_shared<Texture>(texture, pWidth, pHeight, pName);
        }

        /**
         * @brief Loads a texture from a file
         * @param path the path to the file
         * @param name the name of the texture
         */
        static inline std::shared_ptr<Texture> loadTexture(string path, string name)
        {
            Type_SDL_Surface surface = SDL_LoadBMP(path.c_str());
            Type_SDL_Renderer renderer = Graphics::Renderer::getInstance()->getRenderer();
            Type_SDL_Texture texture = SDL_CreateTextureFromSurface(renderer, surface);
            std::cout << "Load texture: " << texture << std::endl;

            return std::make_shared<Texture>(texture, surface->w, surface->h, name);
        }
    };
}

#endif