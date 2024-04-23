#include "main.hpp"

using namespace Gui;

int main()
{
    // GameScreen *gameScreen = new GameScreen();
    // gameScreen->init();
    // std::shared_ptr<Graphics::GraphicsManager> gm = std::make_shared<Graphics::GraphicsManager>();
    // gameScreen->render(*gm);

    MainMenuScreen *mainMenuScreen = new MainMenuScreen();
    mainMenuScreen->init();
    std::shared_ptr<Graphics::GraphicsManager> gm = std::make_shared<Graphics::GraphicsManager>();
    mainMenuScreen->render(*gm);

    return 0;
}
