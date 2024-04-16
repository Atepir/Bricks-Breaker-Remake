#include "gameobjects/Paddle.hpp"

Paddle *Paddle::instance = nullptr;

Point gravityCenterPoint = Point(512, 360 - 20);

Paddle::Paddle(double x, double y, double width, double height, double speed, double angularVelocity)
{
    this->entityType = GameObjectType::GameObjectPaddle;
    this->pTexture = ResourceManager::getInstance()->getTexture("paddle_basic");
    this->position.x = x;
    this->position.y = y;
    this->width = width;
    this->height = height;
    this->speed = speed;
    this->angularVelocity = angularVelocity;
}

Paddle::~Paddle()
{
}

void Paddle::update(eMapType pMapType)
{
    // std::cout << "Paddle Update" << std::endl;
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    switch (pMapType)
    {
    case eMapType::Basic:
    {

        if (state[SDL_SCANCODE_LEFT])
        {
            position.x -= speed;
        }
        if (state[SDL_SCANCODE_RIGHT])
        {
            position.x += speed;
        }
        break;
    }
    case eMapType::Circular:
    {
        double angle = 0;

        if (state[SDL_SCANCODE_LEFT])
        {
            angle = angularVelocity * M_PI / 180;
        }
        if (state[SDL_SCANCODE_RIGHT])
        {
            angle = -angularVelocity * M_PI / 180;
        }

        double xM = position.x - gravityCenterPoint.x;
        double yM = position.y - gravityCenterPoint.y;
        position.x = round(xM * cos(angle) - yM * sin(angle) + gravityCenterPoint.x);
        position.y = round(xM * sin(angle) + yM * cos(angle) + gravityCenterPoint.y);

        // update the angle of the paddle
        double newAngle = atan2(position.y - gravityCenterPoint.y, position.x - gravityCenterPoint.x);
        this->angle = newAngle * 180 / M_PI;
        this->angle += 90;

        break;
    }
    default:
        break;
    }
}

void Paddle::draw(eMapType pMapType)
{
    SDL_Rect dstRect = {(int)position.x - 80, (int)position.y - 20, (int)width, (int)height};
    SDL_RenderCopyEx(GraphicsManager::getInstance()->getRenderer(), pTexture, NULL, &dstRect, angle, NULL, SDL_FLIP_NONE);
}

void Paddle::collide(GameObject *other)
{
}

Paddle *Paddle::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Paddle(420, 600, 160, 60, 30, 10);
    }
    return instance;
}

double Paddle::getWidth() { return this->width; }
double Paddle::getHeight() { return this->height; }
double Paddle::getSpeed() { return this->speed; }

void Paddle::setWidth(double width) { this->width = width; }
void Paddle::setHeight(double height) { this->height = height; }
void Paddle::setSpeed(double speed) { this->speed = speed; }

SDL_Texture *Paddle::getTexture() { return this->pTexture; }
void Paddle::setTexture(SDL_Texture *pTexture) { this->pTexture = pTexture; }