#ifndef __SCREEN_HPP
#define __SCREEN_HPP

#include "graphics/Drawable.hpp"
#include "graphics/GraphicsManager.hpp"
#include "gui/Button.hpp"
#include <vector>

using namespace Graphics;

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

    virtual void keyUp(SDL_KeyboardEvent *event);
    virtual void keyDown(SDL_KeyboardEvent *event);
    virtual void buttonPressed(SDL_MouseButtonEvent *event);
    virtual void buttonReleased(SDL_MouseButtonEvent *event);

    UiElement *add(UiElement *child);
};

class GameScreen : public Screen
{
private:
    Texture *background;

public:
    virtual ~GameScreen();
    virtual void init();
    virtual void keyUp(SDL_KeyboardEvent *event);
    virtual void update(double delta);
    virtual void render(GraphicsManager &renderer);
    virtual void keyDown(SDL_KeyboardEvent *event);
};

class MainMenuScreen : public Screen, public ClickListener
{
private:
    Texture *background;

public:
    MainMenuScreen();
    virtual ~MainMenuScreen();
    virtual void render(GraphicsManager &renderer);
    virtual void init();

    virtual void onClick(int buttonId);
};

class GameOverScreen : public Screen, public ClickListener
{
private:
    Texture *background;
    int score;

public:
    GameOverScreen(int score);
    virtual ~GameOverScreen();
    virtual void render(GraphicsManager &renderer);
    virtual void init();

    virtual void onClick(int buttonId);
};

#endif