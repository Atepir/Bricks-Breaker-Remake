#include "gameobjects/Paddle.hpp"

Paddle *Paddle::instance = nullptr;

Point gravityCenterPoint = Point(512, 360 - 20);

Paddle::Paddle(double x, double y, double width, double height, double speed, double angularVelocity)
{
    this->pTexture = GraphicsManager::getInstance()->loadTexture("paddle.bmp");
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
            std::cout << "Position: " << position.x << std::endl;
        }
        if (state[SDL_SCANCODE_RIGHT])
        {
            position.x += speed;
        }
        break;
    }
    case eMapType::Circular:
    {
        SDL_Rect gravityCenter = {gravityCenterPoint.x, gravityCenterPoint.y, 12, 12};
        SDL_SetRenderDrawColor(GraphicsManager::getInstance()->getRenderer(), 255, 0, 0, 255);
        SDL_RenderFillRect(GraphicsManager::getInstance()->getRenderer(), &gravityCenter);

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

        std::cout << "new angle: " << this->angle << std::endl;

        break;
    }
    default:
        break;
    }
}

void Paddle::draw(eMapType pMapType)
{
    if (this->pTexture != nullptr)
    {
        SDL_Renderer *renderer = GraphicsManager::getInstance()->getRenderer();
        if (renderer != nullptr)
        {
            switch (pMapType)
            {
            case eMapType::Basic:
            {
                for (int i = 0; i < 1024; i += 80)
                {
                    // clear bottom of the screen
                    SDL_Rect rect = {i, 600, 80, 40};
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderFillRect(renderer, &rect);
                }
                break;
            }
            case eMapType::Circular:
            {
                // clear a circle without clearing the center
                for (int i = 0; i < 360; i++)
                {
                    SDL_Rect rect = {490 + 296 * cos(i * M_PI / 180), 320 + 296 * sin(i * M_PI / 180), 80, 80};
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
            default:
                break;
            }

            SDL_Rect dstRect = {(int)position.x - 80, (int)position.y - 20, (int)width, (int)height};
            // render with angle
            std::cout << "new angle in draw: " << Paddle::getInstance()->angle << std::endl;
            SDL_RenderCopyEx(renderer, pTexture, NULL, &dstRect, Paddle::getInstance()->angle, NULL, SDL_FLIP_NONE);
            SDL_RenderPresent(renderer); // updates the screen
        }
        else
        {
            std::cerr << "Renderer is null" << std::endl;
        }
    }
    else
    {
        std::cerr << "Texture is null" << std::endl;
    }
}

void Paddle::collide(GameObject *other)
{
}

Paddle *Paddle::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Paddle(420, 600, 200, 80, 30, 10);
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