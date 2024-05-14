#include "main.hpp"

int main()
{
    std::shared_ptr<Core::App> app = Core::App::getInstance();
    app->setScreen(std::make_shared<Gui::MainMenuScreen>());
    app->run();

    return 0;
}
