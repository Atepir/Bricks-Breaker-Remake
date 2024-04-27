#ifndef __LABEL_HPP
#define __LABEL_HPP

#include "gui/UiElement.hpp"
#include "graphics/Renderer.hpp"
#include "graphics/Font.hpp"

namespace Gui
{
    class Label : public UiElement
    {
    private:
        int id;
        std::string text;
        Graphics::Font font;

    public:
        Label(std::string text, Point position, int width, int height);

        std::shared_ptr<Label> setText(std::string text);

        virtual void render(Graphics::Renderer &renderer);
        void update() override{};
    };
}

#endif