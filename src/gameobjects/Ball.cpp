#include "gameobjects/Ball.hpp"

using namespace GameObjects;

void Ball<eMapType::Basic>::update()
{
    position.x += velocity.x;
    position.y += velocity.y;

    if (position.x < BORDER_WIDTH || position.x > 1024 - BORDER_WIDTH)
    {
        velocity.x = -velocity.x;
    }

    if (position.y < BORDER_WIDTH + MARGIN_TOP || position.y > 720 - BORDER_WIDTH)
    {
        velocity.y = -velocity.y;
    }

    if (position.y > 720 - BORDER_WIDTH)
    {
        // has fallen off the screen
        position.y = 720;
        // notify the observers that the ball has fallen
        notifyObserversBallFallen();
    }
}

void Ball<eMapType::Circular>::update()
{
    // ball is repulsed by the center of the circle
    double distanceFromCenter = sqrt(pow(position.x - 512, 2) + pow(position.y - 360, 2));
    double angle = atan2(position.y - 360, position.x - 512);
    double repulsion = 0.1 * (distanceFromCenter - 300);
    velocity.x += repulsion * cos(angle);
    velocity.y += repulsion * sin(angle);

    position.x += velocity.x;
    position.y += velocity.y;

    if (position.x < BORDER_WIDTH || position.x > 1024 - BORDER_WIDTH)
    {
        velocity.x = -velocity.x;
    }

    if (position.y < BORDER_WIDTH + MARGIN_TOP || position.y > 720 - BORDER_WIDTH)
    {
        velocity.y = -velocity.y;
    }

    if (position.y > 720 - BORDER_WIDTH)
    {
        // has fallen off the screen
        position.y = 720;
        // notify the observers that the ball has fallen
        notifyObserversBallFallen();
    }
}

void Ball<eMapType::Basic>::collide(std::shared_ptr<GameObject> pOther)
{
    // Calculate the minimum and maximum coordinates of both objects
    double thisLeft = position.x;
    double thisRight = position.x + getWidth();
    double thisTop = position.y;
    double thisBottom = position.y + getHeight();

    double otherLeft = pOther->getPosition().x;
    double otherRight = pOther->getPosition().x + pOther->getWidth();
    double otherTop = pOther->getPosition().y;
    double otherBottom = pOther->getPosition().y + pOther->getHeight();

    // Check for overlap between the bounding boxes of the two objects
    if (thisRight >= otherLeft && thisLeft <= otherRight &&
        thisBottom >= otherTop && thisTop <= otherBottom)
    {
        if (pOther->getEntityType() == GameObjectType::GameObjectPaddle)
        {
            // bounce with repulsion as it is circular
            double paddleCenter = pOther->getPosition().x + pOther->getWidth() / 2;
            double ballCenter = position.x + getWidth() / 2;
            double distanceFromCenter = ballCenter - paddleCenter;
            double normalizedDistance = distanceFromCenter / (pOther->getWidth() / 2);
            double bounceAngle = normalizedDistance * 45;
            velocity.x = 20 * sin(bounceAngle * M_PI / 180);
            velocity.y = -20 * cos(bounceAngle * M_PI / 180);
        }
        else if (pOther->getEntityType() == GameObjectType::GameObjectBrick)
        {
            std::shared_ptr<Brick> brick = std::static_pointer_cast<Brick>(pOther);
            switch (brick->mType)
            {
            case BrickType::BRICK_BLUE:
                damageBrick(brick, 100);
                break;
            case BrickType::BRICK_GREEN:
                damageBrick(brick, 60);
                break;
            case BrickType::BRICK_VIOLET:
                damageBrick(brick, 40);
                break;
            case BrickType::BRICK_YELLOW:
                damageBrick(brick, 20);
                break;
            case BrickType::BRICK_RED:
                damageBrick(brick, 10);
                break;
            }

            // bounce with repulsion as it is circular
            double brickCenter = pOther->getPosition().x + pOther->getWidth() / 2;
            double ballCenter = position.x + getWidth() / 2;
            double distanceFromCenter = ballCenter - brickCenter;
            double normalizedDistance = distanceFromCenter / (pOther->getWidth() / 2);
            double bounceAngle = normalizedDistance * 45;
            velocity.x = 20 * sin(bounceAngle * M_PI / 180);
            velocity.y = -20 * cos(bounceAngle * M_PI / 180);
        }
    }
}

void Ball<eMapType::Circular>::collide(std::shared_ptr<GameObject> pOther)
{
    // Calculate the minimum and maximum coordinates of both objects
    double thisLeft = position.x;
    double thisRight = position.x + getWidth();
    double thisTop = position.y;
    double thisBottom = position.y + getHeight();

    double otherLeft = pOther->getPosition().x;
    double otherRight = pOther->getPosition().x + pOther->getWidth();
    double otherTop = pOther->getPosition().y;
    double otherBottom = pOther->getPosition().y + pOther->getHeight();

    // Check for overlap between the bounding boxes of the two objects
    if (thisRight >= otherLeft && thisLeft <= otherRight &&
        thisBottom >= otherTop && thisTop <= otherBottom)
    {
        if (pOther->getEntityType() == GameObjectType::GameObjectPaddle)
        {
            double paddleCenter = pOther->getPosition().x + pOther->getWidth() / 2;
            double ballCenter = position.x + getWidth() / 2;
            double distanceFromCenter = ballCenter - paddleCenter;
            double normalizedDistance = distanceFromCenter / (pOther->getWidth() / 2);
            double bounceAngle = normalizedDistance * 45;
            velocity.x = 20 * sin(bounceAngle * M_PI / 180);
            velocity.y = -20 * cos(bounceAngle * M_PI / 180);
        }
        else if (pOther->getEntityType() == GameObjectType::GameObjectBrick)
        {
            std::shared_ptr<Brick> brick = std::static_pointer_cast<Brick>(pOther);
            switch (brick->mType)
            {
            case BrickType::BRICK_BLUE:
                damageBrick(brick, 100);
                break;
            case BrickType::BRICK_GREEN:
                damageBrick(brick, 60);
                break;
            case BrickType::BRICK_VIOLET:
                damageBrick(brick, 40);
                break;
            case BrickType::BRICK_YELLOW:
                damageBrick(brick, 20);
                break;
            case BrickType::BRICK_RED:
                damageBrick(brick, 10);
                break;
            }

            velocity.y = -velocity.y;
        }
    }
}

void Ball<eMapType::Basic>::expand()
{
    if (this->width >= 60 && this->height >= 60)
    {
        return;
    }
    this->width *= 2;
    this->height *= 2;

    std::thread([this]()
                {
        std::this_thread::sleep_for(std::chrono::seconds(POWER_TIMEOUT));
        this->width /= 2;
        this->height /= 2; })
        .detach();
}

void Ball<eMapType::Basic>::shrink()
{
    if (this->width <= 15 && this->height <= 15)
    {
        return;
    }
    this->width /= 2;
    this->height /= 2;

    std::thread([this]()
                {
        std::this_thread::sleep_for(std::chrono::seconds(POWER_TIMEOUT));
        this->width *= 2;
        this->height *= 2; })
        .detach();
}