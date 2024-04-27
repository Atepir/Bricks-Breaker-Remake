#ifndef __UI_ELEMENT_HPP
#define __UI_ELEMENT_HPP

#include "graphics/Drawable.hpp"
#include "gui/EventListener.hpp"

namespace Gui
{
    using Type_SDL_MouseButtonEvent = SDL_MouseButtonEvent *;

    enum PosSystem
    {
        Absolute,
        Relative
    };

    class UiElement : public Graphics::IDrawable, public Gui::EventListener
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

        void resize(int width, int height);
        void update(double delta);

        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;

        void setWidth(int width);
        void setHeight(int height);

        std::shared_ptr<UiElement> center();
        std::shared_ptr<UiElement> centerX();
        std::shared_ptr<UiElement> centerY();
        std::shared_ptr<UiElement> offset(int x, int y);
        std::shared_ptr<UiElement> offsetX(int x);
        std::shared_ptr<UiElement> offsetY(int y);
        std::shared_ptr<UiElement> absolute(int x, int y);
        std::shared_ptr<UiElement> absoluteX(int x);
        std::shared_ptr<UiElement> absoluteY(int y);
    };
}
#endif