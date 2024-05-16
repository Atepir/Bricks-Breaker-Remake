#include "factories/PowerFactory.hpp"

using namespace Factories;
using namespace GameObjects;

void PowerFactory::createPower(ePowerType pType, Point pPowerPosition)
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

void PowerFactory::onBrickDestroyed(eBrickType pBrickType, Point pBrickPosition)
{
  int chance = rand() % 300;

  if (chance < 10)
  {
    createPower(ePowerType::PowerUp_Multi_Ball, pBrickPosition);
  }
  else if (chance < 20)
  {
    createPower(ePowerType::PowerUp_Extra_Life, pBrickPosition);
  }
  else if (chance < 30)
  {
    if (MAP_TYPE == eMapType::Map_Circular)
    {
      return;
    }
    createPower(ePowerType::PowerDown_Shrink_Paddle, pBrickPosition);
  }
  else if (chance < 50)
  {
    createPower(ePowerType::PowerDown_Shrink_Ball, pBrickPosition);
  }
  else if (chance < 70)
  {
    if (MAP_TYPE == eMapType::Map_Circular)
    {
      return;
    }
    createPower(ePowerType::PowerUp_Expand_Paddle, pBrickPosition);
  }
  else if (chance < 100)
  {
    createPower(ePowerType::PowerUp_Expand_Ball, pBrickPosition);
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
