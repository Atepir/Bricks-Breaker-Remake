#include "gui/UiElement.hpp"

UiElement::UiElement()
    : x(0), y(0), width(0), height(0), _offsetX(0), _offsetY(0),
      _centerX(false), _centerY(false), XPosSystem(Absolute),
      YPosSystem(Absolute), dirty(false)
{
}

UiElement::UiElement(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height), _offsetX(0), _offsetY(0),
      _centerX(false), _centerY(false), XPosSystem(Absolute),
      YPosSystem(Absolute), dirty(false)
{
}

int UiElement::getX() const
{
    return x;
}

int UiElement::getY() const
{
    return y;
}

int UiElement::getWidth() const
{
    return width;
}

int UiElement::getHeight() const
{
    return height;
}

void UiElement::setWidth(int width)
{
    this->width = width;
    dirty = true;
}

void UiElement::setHeight(int height)
{
    this->height = height;
    dirty = true;
}

std::shared_ptr<UiElement> UiElement::center()
{
    return centerX()->centerY();
}

std::shared_ptr<UiElement> UiElement::centerX()
{
    _centerX = true;
    XPosSystem = Relative;
    dirty = true;

    return std::shared_ptr<UiElement>(this);
}

std::shared_ptr<UiElement> UiElement::centerY()
{
    _centerY = true;
    YPosSystem = Relative;
    dirty = true;

    return std::shared_ptr<UiElement>(this);
}

std::shared_ptr<UiElement> UiElement::offset(int x, int y)
{
    return offsetX(x)->offsetY(y);
}

std::shared_ptr<UiElement> UiElement::offsetX(int x)
{
    _offsetX = x;
    XPosSystem = Relative;
    dirty = true;

    return std::shared_ptr<UiElement>(this);
}

std::shared_ptr<UiElement> UiElement::offsetY(int y)
{
    _offsetY = y;
    YPosSystem = Relative;
    dirty = true;

    return std::shared_ptr<UiElement>(this);
}

std::shared_ptr<UiElement> UiElement::absolute(int x, int y)
{
    absoluteX(x);
    absoluteY(y);
    return std::shared_ptr<UiElement>(this);
}

std::shared_ptr<UiElement> UiElement::absoluteX(int x)
{
    this->x = x;
    XPosSystem = Absolute;
    dirty = true;

    return std::shared_ptr<UiElement>(this);
}

std::shared_ptr<UiElement> UiElement::absoluteY(int y)
{
    this->y = y;
    YPosSystem = Absolute;
    dirty = true;

    return std::shared_ptr<UiElement>(this);
}

void UiElement::calculateCoordinate(int width, int height)
{
    if (XPosSystem == Relative)
    {
        if (_centerX)
        {
            x = width / 2 - getWidth() / 2 + _offsetX;
        }
        else
        {
            x = _offsetX;
        }
    }
    if (YPosSystem == Relative)
    {
        if (_centerY)
        {
            y = height / 2 - getHeight() / 2 + _offsetY;
        }
        else
        {
            y = _offsetY;
        }
    }
}

void UiElement::resize(int width, int height)
{
    calculateCoordinate(width, height);
}

void UiElement::update(double delta)
{
    if (dirty)
    {
        dirty = false;
    }
}

UiElement::~UiElement()
{
}