#include "gameobjects/Ball.hpp"

using namespace GameObjects;

void Ball<eMapType::Basic>::update()
{
    std::shared_ptr<Graphics::Renderer> renderer = Graphics::Renderer::getInstance();

    position.x += velocity.x;
    position.y += velocity.y;

    if (position.x < BORDER_WIDTH || position.x > renderer->getScreenWidth() - BORDER_WIDTH - getWidth())
    {
        velocity.x = -velocity.x;
        mCollisionSound->play();
    }

    if (position.y < BORDER_WIDTH + MARGIN_TOP || position.y > renderer->getScreenHeight() - BORDER_WIDTH)
    {
        velocity.y = -velocity.y;
        mCollisionSound->play();
    }

    if (position.x < BORDER_WIDTH)
    {
        position.x = BORDER_WIDTH + 1;
    }
    else if (position.x > renderer->getScreenWidth() - BORDER_WIDTH - getWidth())
    {
        position.x = renderer->getScreenWidth() - BORDER_WIDTH - getWidth() - 1;
    }

    if (position.y < BORDER_WIDTH + MARGIN_TOP)
    {
        position.y = BORDER_WIDTH + MARGIN_TOP + 1;
    }

    if (position.y > renderer->getScreenHeight() - BORDER_WIDTH)
    {
        mFallSound->play();
        // notify the observers that the ball has fallen
        notifyObserversBallFallen();
    }
}

void Ball<eMapType::Circular>::update()
{
    std::shared_ptr<Graphics::Renderer> renderer = Graphics::Renderer::getInstance();

    // if distance from the center is greater than the radius of the circle
    double distanceFromCenter = sqrt(pow(position.x - renderer->getScreenWidth() / 2, 2) + pow(position.y - renderer->getScreenHeight() / 2, 2));
    if (distanceFromCenter > renderer->getScreenWidth() / 2 - 30)
    {
        mFallSound->play();
        // has fallen off the screen
        // notify the observers that the ball has fallen
        notifyObserversBallFallen();
    }

    // ball is repulsed by the center of the circle
    double centerX = renderer->getScreenWidth() / 2;
    double centerY = renderer->getScreenHeight() / 2;
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
        mCollisionSound->play();
        if (pOther->getEntityType() == GameObjectType::GameObjectPaddle)
        {
            double paddleCenter = pOther->getPosition().x + pOther->getWidth() / 2;
            double ballCenter = position.x + getWidth() / 2;
            double distanceFromCenter = ballCenter - paddleCenter;
            double normalizedDistance = distanceFromCenter / (pOther->getWidth() / 2);
            double bounceAngle = normalizedDistance * 45;
            velocity.x = 12 * sin(bounceAngle * M_PI / 180);
            velocity.y = -12 * cos(bounceAngle * M_PI / 180);
        }
        else if (pOther->getEntityType() == GameObjectType::GameObjectBrick)
        {
            std::shared_ptr<Brick> brick = std::static_pointer_cast<Brick>(pOther);
            damageBrick(brick);

            velocity.y = -velocity.y;
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
        mCollisionSound->play();
        if (pOther->getEntityType() == GameObjectType::GameObjectPaddle)
        {
            // ball collision with paddle on circular map
            // we have to take into account the angle of the paddle
            double paddleAngle = pOther->getAngle();
            double paddleCenter = pOther->getPosition().x + pOther->getWidth() / 2;
            double ballCenter = position.x + getWidth() / 2;
            double distanceFromCenter = ballCenter - paddleCenter;
            double normalizedDistance = distanceFromCenter / (pOther->getWidth() / 2);
            double bounceAngle = normalizedDistance * 20;
            double angleDifference = bounceAngle - paddleAngle;

            double ballForce = 8;
            if (paddleAngle > -180 && paddleAngle < -90)
            {
                velocity.x = ballForce * cos(angleDifference * M_PI / 90);
                velocity.y = -ballForce * sin(angleDifference * M_PI / 90);
            }

            // Pas mal pas bien
            else if ((paddleAngle < 0 && paddleAngle > -90))
            {
                velocity.x = ballForce * sin(-angleDifference * M_PI / 90);
                if (distanceFromCenter > 0)
                    velocity.y = ballForce * cos(angleDifference * M_PI / 90);
                else
                    velocity.y = -ballForce * cos(angleDifference * M_PI / 90);
            }

            // Inverse
            else if (paddleAngle > -270 && paddleAngle < -180)
            {
                velocity.x = -ballForce * cos(angleDifference * M_PI / 90);
                velocity.y = ballForce * sin(angleDifference * M_PI / 90);
            }

            // Pas bon
            else // if (paddleAngle > 0 && paddleAngle < 90)
            {
                if (distanceFromCenter > 0)
                    velocity.x = ballForce * sin(-angleDifference * M_PI / 90);
                else
                    velocity.x = -ballForce * sin(-angleDifference * M_PI / 90);
                velocity.y = -ballForce * cos(angleDifference * M_PI / 90);
            }
        }
        else if (pOther->getEntityType() == GameObjectType::GameObjectBrick)
        {
            std::shared_ptr<Brick> brick = std::static_pointer_cast<Brick>(pOther);
            damageBrick(brick);

            velocity.y = -velocity.y;
        }
    }
}
