#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL.h>
#include "graphics/GraphicsManager.hpp"

class Drawable
{
private:
    bool visible;

protected:
    Drawable();
    SDL_Texture *pTexture = nullptr;

public:
    virtual ~Drawable();
    virtual void update() = 0;
    virtual void render(GraphicsManager &renderer) = 0;
    // virtual void resize(int width, int height) = 0;
    virtual void setVisible(bool visible);
    virtual bool isVisible();
};

#endif