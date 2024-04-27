#include "main.hpp"

using namespace Gui;

int main()
{
    std::shared_ptr<Core::App> app = Core::App::getInstance();
    app->setScreen(std::make_shared<MainMenuScreen>());
    app->run();

    return 0;
}
