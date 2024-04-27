#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL.h>

#include "graphics/Renderer.hpp"
#include "graphics/Texture.hpp"

namespace Graphics
{
    class IDrawable
    {
    private:
        bool visible;

    protected:
        IDrawable();
        Texture texture;

    public:
        virtual ~IDrawable();
        virtual void update() = 0;
        virtual void render(Renderer &renderer) = 0;
        // virtual void resize(int width, int height) = 0;
        virtual void setVisible(bool visible);
        virtual bool isVisible();
    };
}

#endif