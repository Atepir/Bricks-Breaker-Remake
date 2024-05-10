#include "factories/PowerFactory.hpp"

using namespace Factories;
using namespace GameObjects;

void PowerFactory::createPower(PowerType pType, Point pPowerPosition)
{
  std::shared_ptr<Power> power = std::make_shared<Power>(pType, pPowerPosition);
  power->addObserver(BallFactory::getInstance());
  power->addObserver(Paddle<MAP_TYPE>::getInstance());
  power->addObserver(mPlayer);
  mPowers.push_back(power);
}

void PowerFactory::setPlayer(std::shared_ptr<Core::Player> pPlayer)
{
  mPlayer = pPlayer;
}

void PowerFactory::onBrickDestroyed(BrickType pBrickType, Point pBrickPosition)
{
  std::cout << "PowerFactory::onBrickDestroyed" << std::endl;
  int chance = rand() % 300;

  std::cout << "Chance: " << chance << "\n";

  if (chance < 10)
  {
    createPower(PowerType::POWERUP_MULTI_BALL, pBrickPosition);
  }
  else if (chance < 20)
  {
    createPower(PowerType::POWERUP_EXTRA_LIFE, pBrickPosition);
  }
  else if (chance < 30)
  {
    createPower(PowerType::POWERDOWN_SHRINK_PADDLE, pBrickPosition);
  }
  else if (chance < 50)
  {
    createPower(PowerType::POWERDOWN_SHRINK_BALL, pBrickPosition);
  }
  else if (chance < 70)
  {
    createPower(PowerType::POWERUP_EXPAND_PADDLE, pBrickPosition);
  }
  else if (chance < 100)
  {
    createPower(PowerType::POWERUP_EXPAND_BALL, pBrickPosition);
  }
  else
  {
    void;
  }
}

void PowerFactory::update()
{
  for (auto power : mPowers)
  {
    if (power == nullptr)
    {
      continue;
    }

    power->update();
    if (power->getDeleteFlag())
    {
      mPowers.erase(std::remove(mPowers.begin(), mPowers.end(), power), mPowers.end());
    }
  }
}

void PowerFactory::render(Graphics::Renderer &pRenderer)
{
  for (auto power : mPowers)
  {
    if (power == nullptr)
    {
      continue;
    }

    power->render(pRenderer);
  }
}

void PowerFactory::collide(std::shared_ptr<GameObjects::GameObject> pGameObject)
{
  for (auto power : mPowers)
  {
    if (power == nullptr)
    {
      continue;
    }

    power->collide(pGameObject);
  }
}
