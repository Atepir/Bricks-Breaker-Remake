
#include "gui/Screen.hpp"
#include "gui/Button.hpp"
#include "gui/Label.hpp"

using namespace Gui;

MainMenuScreen::MainMenuScreen()
{
}

void MainMenuScreen::init()
{
    Graphics::GraphicsManager *graphics = Graphics::GraphicsManager::getInstance();
    graphics->init();

    if (TTF_Init() == -1)
    {
        printf("Erreur - TTF_Init()\n");
        SDL_Delay(5000);
    }

    TTF_Font *smallFont = TTF_OpenFont("font.ttf", 24);
    if (smallFont == nullptr)
    {
        std::cerr << "Failed to load font.ttf" << std::endl;
        std::cerr << TTF_GetError() << std::endl;
    }
    std::cout << "smallFont: " << smallFont << std::endl;
    Font::setDefaultFonts(smallFont, smallFont);
    add(new Label("BricksBreaker Remake!", {300, 100}));
    add(new Button(0, "Play", {300, 500}, 100, 50));

    std::cout << "Main menu screen initialized" << std::endl;
}

void MainMenuScreen::render(Graphics::GraphicsManager &renderer)
{

    Graphics::GraphicsManager *graphics = Graphics::GraphicsManager::getInstance();

    Screen::render(renderer);
    graphics->render();
    SDL_Delay(10000);
}

void MainMenuScreen::onClick(int buttonId)
{
    // switch (buttonId)
    // {
    // case 0:
    //     break;
    // }
}

MainMenuScreen::~MainMenuScreen()
{
}