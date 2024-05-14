#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL.h>

#include "graphics/Renderer.hpp"
#include "graphics/Texture.hpp"

namespace Graphics
{
    /**
     * @brief Interface for drawable objects
     */
    class IDrawable
    {
    protected:
        IDrawable() = default;
        std::shared_ptr<Texture> texture;

    public:
        virtual ~IDrawable() = default;
        virtual void render(Renderer &renderer) = 0;
    };
}

#endif