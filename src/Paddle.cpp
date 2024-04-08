#include "Paddle.hpp"

Paddle* Paddle::instance = nullptr;

Paddle::Paddle(double x, double y, double width, double height, double speed)
{
    this->pTexture = Graphics::getInstance()->loadTexture("paddle.bmp");
    this->position.x = x;
    this->position.y = y;
    this->width = width;
    this->height = height;
    this->speed = speed;
}

Paddle::~Paddle()
{
}

void Paddle::update()
{
    const Uint8* state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_LEFT])
    {
        position.x -= speed;
    }
    if (state[SDL_SCANCODE_RIGHT])
    {
        position.x += speed;
    }
}

void Paddle::draw()
{
    // SDL_Rect dstRect = {(int)position.x, (int)position.y, (int)width, (int)height};
    // SDL_RenderCopyEx(Graphics::getInstance()->getRenderer(), pTexture, NULL, &dstRect, 0, NULL, SDL_FLIP_NONE);
    if (this->pTexture != nullptr) {
        SDL_Renderer* renderer = Graphics::getInstance()->getRenderer();
        if (renderer != nullptr) {
            SDL_RenderClear(renderer); //clears the renderer
            SDL_Rect dstRect = { (int)position.x, (int)position.y, (int)width, (int)height };
            SDL_RenderCopy(renderer, pTexture, NULL, &dstRect);
            SDL_RenderPresent(renderer); //updates the screen
        }
        else {
            std::cerr << "Renderer is null" << std::endl;
        }
    }
    else {
        std::cerr << "Texture is null" << std::endl;
    }
}

void Paddle::collide(GameObject* other)
{
}

Paddle* Paddle::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Paddle(250, 250, 329, 143, 0);
    }
    return instance;
}

double Paddle::getWidth() { return this->width; }
double Paddle::getHeight() { return this->height; }
double Paddle::getSpeed() { return this->speed; }

void Paddle::setWidth(double width) { this->width = width; }
void Paddle::setHeight(double height) { this->height = height; }
void Paddle::setSpeed(double speed) { this->speed = speed; }

SDL_Texture* Paddle::getTexture() { return this->pTexture; }
void Paddle::setTexture(SDL_Texture* pTexture) { this->pTexture = pTexture; }
