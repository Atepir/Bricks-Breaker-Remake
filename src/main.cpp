#include "main.hpp"

using namespace Gui;

int main()
{
    Core::App *app = Core::App::getInstance();
    app->setScreen(new MainMenuScreen());
    app->run();

    return 0;
}
