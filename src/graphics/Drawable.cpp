#include "graphics/Drawable.hpp"

using namespace Graphics;

IDrawable::IDrawable() : visible(true)
{
}

IDrawable::~IDrawable()
{
}

void IDrawable::setVisible(bool visible)
{
    this->visible = visible;
}

bool IDrawable::isVisible()
{
    return visible;
}