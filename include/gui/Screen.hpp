#ifndef __SCREEN_HPP
#define __SCREEN_HPP

#include "graphics/Drawable.hpp"
#include "graphics/Renderer.hpp"
#include "gui/Button.hpp"
#include "gui/Image.hpp"
#include "gui/Label.hpp"
#include <vector>

#include <SDL.h>

#include "graphics/Renderer.hpp"
#include "gameobjects/GameObject.hpp"
#include "gameobjects/Ball.hpp"
#include "gameobjects/Paddle.hpp"
#include "gameobjects/Board.hpp"
#include "factories/BallFactory.hpp"
#include "resources/Enums.hpp"

using namespace GameObjects;
using namespace Factories;
using namespace Graphics;

namespace Core
{
    class App;
    class Player;
};

namespace Gui
{
    class Screen : public IDrawable
    {
    private:
        std::vector<std::shared_ptr<UiElement>> children;

    public:
        Screen();
        virtual ~Screen();
        virtual void init();
        virtual void render(Renderer &renderer);
        virtual void update(double delta);
        virtual void resize(int width, int height);

        // virtual void keyUp(std::shared_ptr<SDL_KeyboardEvent> event);
        // virtual void keyDown(std::shared_ptr<SDL_KeyboardEvent> event);
        // virtual void buttonPressed(std::shared_ptr<SDL_MouseButtonEvent> event);
        // virtual void buttonReleased(std::shared_ptr<SDL_MouseButtonEvent> event);

        virtual void handleMouseDown(Type_SDL_MouseButtonEvent event);
        virtual void handleMouseUp(Type_SDL_MouseButtonEvent event);

        std::shared_ptr<UiElement> add(std::shared_ptr<UiElement> element);
        void remove(std::shared_ptr<UiElement> element);
    };

    class GameScreen : public Screen
    {
    private:
        std::shared_ptr<Texture> mBackground;
        std::shared_ptr<Board<MAP_TYPE>> mBoard;
        std::shared_ptr<Paddle<MAP_TYPE>> mPaddle;
        std::shared_ptr<Ball> mBall;
        std::shared_ptr<Renderer> mRenderer;
        std::shared_ptr<Core::Player> mPlayer;
        std::vector<std::shared_ptr<Image>> mHearts;
        std::shared_ptr<Label> mScoreLabel;

    public:
        GameScreen();
        virtual ~GameScreen();
        virtual void init();
        virtual void keyUp(std::shared_ptr<SDL_KeyboardEvent> event);
        virtual void update(double delta);
        virtual void render(Renderer &renderer);
        virtual void keyDown(std::shared_ptr<SDL_KeyboardEvent> event);

        void update() override{};
    };

    class MainMenuScreen : public Screen
    {
    private:
        std::shared_ptr<Texture> background;

    public:
        MainMenuScreen();
        virtual ~MainMenuScreen();
        virtual void render(Renderer &renderer);
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
        virtual void render(Renderer &renderer);
        virtual void init();

        void update() override{};
    };
}

#include "core/App.hpp"
#include "core/Player.hpp"

#endif