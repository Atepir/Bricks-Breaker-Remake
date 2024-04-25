#ifndef __SCREEN_HPP
#define __SCREEN_HPP

#include "graphics/Drawable.hpp"
#include "graphics/GraphicsManager.hpp"
#include "gui/Button.hpp"
#include <vector>

using namespace Graphics;

namespace Core
{
    class App;
};

namespace Gui
{
    class Screen : public IDrawable
    {
    private:
        std::vector<UiElement *> children;

    public:
        Screen();
        virtual ~Screen();
        virtual void init();
        virtual void render(GraphicsManager &renderer);
        virtual void update(double delta);
        virtual void resize(int width, int height);

        // virtual void keyUp(std::shared_ptr<SDL_KeyboardEvent> event);
        // virtual void keyDown(std::shared_ptr<SDL_KeyboardEvent> event);
        // virtual void buttonPressed(std::shared_ptr<SDL_MouseButtonEvent> event);
        // virtual void buttonReleased(std::shared_ptr<SDL_MouseButtonEvent> event);

        virtual void handleMouseDown(SDL_MouseButtonEvent *event);
        virtual void handleMouseUp(SDL_MouseButtonEvent *event);

        UiElement *add(UiElement *element);
    };

    class GameScreen : public Screen
    {
    private:
        std::shared_ptr<Texture> background;

    public:
        GameScreen();
        virtual ~GameScreen();
        virtual void init();
        virtual void keyUp(std::shared_ptr<SDL_KeyboardEvent> event);
        virtual void update(double delta);
        virtual void render(GraphicsManager &renderer);
        virtual void keyDown(std::shared_ptr<SDL_KeyboardEvent> event);

        void update() override{};
    };

    class MainMenuScreen : public Screen
    {
    private:
        Texture *background;

    public:
        MainMenuScreen();
        virtual ~MainMenuScreen();
        virtual void render(GraphicsManager &renderer);
        virtual void init();

        void update() override{};
    };

    class GameOverScreen : public Screen
    {
    private:
        std::shared_ptr<Texture> background;
        int score;

    public:
        GameOverScreen(int score);
        virtual ~GameOverScreen();
        virtual void render(GraphicsManager &renderer);
        virtual void init();

        void update() override{};
    };
}

#include "core/App.hpp"

#endif