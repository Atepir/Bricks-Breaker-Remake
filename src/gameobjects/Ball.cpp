#include "gameobjects/Ball.hpp"

using namespace GameObjects;

void Ball<eMapType::Basic>::update()
{
    std::cout << "Ball update" << " x: " << position.x << " y: " << position.y << std::endl;
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

    // ball is repulsed by the center of the circle - also use angular velocity
    double centerX = 1024 / 2;
    double centerY = 720 / 2;
    double distanceX = position.x - centerX;
    double distanceY = position.y - centerY;
    double distance = sqrt(distanceX * distanceX + distanceY * distanceY);
    double normalizedDistanceX = distanceX / distance;
    double normalizedDistanceY = distanceY / distance;
    double repulsion = 0.1;
    velocity.x += repulsion * normalizedDistanceX;
    velocity.y += repulsion * normalizedDistanceY;

    position.x += velocity.x;
    position.y += velocity.y;
    angle += angularVelocity;
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
            // bounce with repulsion as it is circular - independent of the paddle's position
            double paddleCenter = pOther->getPosition().x + pOther->getWidth() / 2;
            double ballCenter = position.x + getWidth() / 2;
            double distanceFromCenter = ballCenter - paddleCenter;
            double normalizedDistance = distanceFromCenter / (pOther->getWidth() / 2);
            double bounceAngle = normalizedDistance * 45;
            velocity.x = 8 * sin(bounceAngle * M_PI / 180);
            velocity.y = -8 * cos(bounceAngle * M_PI / 180);
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