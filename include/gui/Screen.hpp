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
#include "factories/PowerFactory.hpp"
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
    using Type_SDL_MouseButtonEvent = SDL_MouseButtonEvent *;

    class Screen : public IDrawable
    {
    private:
        std::vector<std::shared_ptr<UiElement>> children;
        std::vector<std::shared_ptr<IMouseMoveListener>> mMouseMoveListeners;

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

        virtual void handleMouseMoveX(bool right);

        std::shared_ptr<UiElement> add(std::shared_ptr<UiElement> element);
        void addMouseMoveListener(std::shared_ptr<IMouseMoveListener> listener);
        void remove(std::shared_ptr<UiElement> element);
    };

    class GameScreen : public Screen
    {
    private:
        std::shared_ptr<Texture> mBackground;
        std::shared_ptr<Board<MAP_TYPE>> mBoard;
        std::shared_ptr<Paddle<MAP_TYPE>> mPaddle;
        std::shared_ptr<Renderer> mRenderer;
        std::shared_ptr<Core::Player> mPlayer;
        std::vector<std::shared_ptr<Image>> mHearts;
        std::shared_ptr<Label> mScoreLabel;
        std::shared_ptr<PowerFactory> mPowerFactory;
        std::shared_ptr<BallFactory> mBallFactory;

    public:
        GameScreen();
        virtual ~GameScreen();
        virtual void init();
        virtual void keyUp(std::shared_ptr<SDL_KeyboardEvent> event);
        virtual void update(double delta);
        virtual void render(Renderer &renderer);
        virtual void keyDown(std::shared_ptr<SDL_KeyboardEvent> event);

        void update() override {};
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

        void update() override {};
    };

    class GameOverScreen : public Screen
    {
    private:
        std::shared_ptr<Texture> mBackground;
        int mScore;

    public:
        GameOverScreen(int score);
        virtual ~GameOverScreen();
        virtual void render(Renderer &renderer);
        virtual void init();

        void update() override {};
    };

    class LevelCompleteScreen : public Screen
    {
    private:
        std::shared_ptr<Texture> mBackground;
        int mScore;

    public:
        LevelCompleteScreen(int score);
        virtual ~LevelCompleteScreen();
        virtual void render(Renderer &renderer);
        virtual void init();

        void update() override {};
    };
}

#include "core/App.hpp"
#include "core/Player.hpp"

#endif