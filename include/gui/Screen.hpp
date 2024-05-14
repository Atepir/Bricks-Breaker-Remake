#ifndef __SCREEN_HPP
#define __SCREEN_HPP

#include <vector>

#include "graphics/Drawable.hpp"
#include "graphics/Renderer.hpp"
#include "graphics/Renderer.hpp"

#include "gui/Button.hpp"
#include "gui/Image.hpp"
#include "gui/Label.hpp"

#include "gameobjects/GameObject.hpp"
#include "gameobjects/Ball.hpp"
#include "gameobjects/Paddle.hpp"
#include "gameobjects/Board.hpp"

#include "factories/BallFactory.hpp"
#include "factories/PowerFactory.hpp"

#include "resources/Enums.hpp"

using namespace Graphics;
using namespace GameObjects;
using namespace Factories;

namespace Core
{
    class App;
    class Player;
};

namespace Gui
{
    /**
     * @brief Base class for all screens
     * @details A screen is a collection of UI elements that are rendered on the screen
     */
    class Screen : public IDrawable
    {
    private:
        std::vector<std::shared_ptr<UiElement>> mChildren;
        std::vector<std::shared_ptr<IMoveListener>> mMoveListeners;

    public:
        Screen() = default;
        virtual ~Screen();
        virtual void init() = 0;
        virtual void render(Renderer &renderer);

        virtual void handleKeyDown(bool pRight);
        virtual void handleMouseDown(Point pClickPoint);
        virtual void handleMouseUp(Point pClickPoint);
        virtual void handleMouseMoveX(bool pRight);

        std::shared_ptr<UiElement> add(std::shared_ptr<UiElement> pElement);
        void addMoveListener(std::shared_ptr<IMoveListener> pListener);
        void remove(std::shared_ptr<UiElement> pElement);
    };

    /**
     * @brief The actual game screen
     * @details This screen is where the game is played
     */
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
        virtual ~GameScreen() = default;
        virtual void init();
        virtual void render(Renderer &renderer);
    };

    /**
     * @brief The main menu screen
     * @details This screen is displayed when the game is started
     */
    class MainMenuScreen : public Screen
    {
    private:
        std::shared_ptr<Texture> mBackground;

    public:
        MainMenuScreen() = default;
        virtual ~MainMenuScreen() = default;
        virtual void render(Renderer &renderer);
        virtual void init();
    };

    /**
     * @brief The game over screen
     * @details This screen is displayed when the player loses all lives
     */
    class GameOverScreen : public Screen
    {
    private:
        std::shared_ptr<Texture> mBackground;
        int mScore;

    public:
        GameOverScreen(int score) : mScore(score) {}
        virtual ~GameOverScreen() = default;
        virtual void render(Renderer &renderer);
        virtual void init();
    };

    /**
     * @brief The level complete screen
     * @details This screen is displayed when the player completes a level
     */
    class LevelCompleteScreen : public Screen
    {
    private:
        std::shared_ptr<Texture> mBackground;
        int mScore;

    public:
        LevelCompleteScreen(int score) : mScore(score) {}
        virtual ~LevelCompleteScreen() = default;
        virtual void render(Renderer &renderer);
        virtual void init();
    };
}

#include "core/App.hpp"
#include "core/Player.hpp"

#endif