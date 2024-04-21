#ifndef __UI_ELEMENT_HPP
#define __UI_ELEMENT_HPP

#include "graphics/Drawable.hpp"

enum PosSystem
{
    Absolute,
    Relative
};

class UiElement : public Graphics::IDrawable
{
protected:
    int x, y, width, height;
    int _offsetX, _offsetY;
    bool _centerX, _centerY;
    bool dirty;
    PosSystem XPosSystem, YPosSystem;

public:
    UiElement();
    UiElement(int x, int y, int width, int height);
    virtual ~UiElement();

    void calculateCoordinate(int width, int height);

    virtual void resize(int width, int height);
    virtual void update(double delta);

    virtual int getX() const;
    virtual int getY() const;
    virtual int getWidth() const;
    virtual int getHeight() const;

    virtual void setWidth(int width);
    virtual void setHeight(int height);

    UiElement *center();
    UiElement *centerX();
    UiElement *centerY();
    UiElement *offset(int x, int y);
    UiElement *offsetX(int x);
    UiElement *offsetY(int y);
    UiElement *absolute(int x, int y);
    UiElement *absoluteX(int x);
    UiElement *absoluteY(int y);
};

#endif