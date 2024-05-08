#include "factories/PowerFactory.hpp"

using namespace Factories;
using namespace GameObjects;


std::shared_ptr<GameObjects::Power> PowerFactory::createPower(PowerType pType, Point pPowerPosition)
{
  return std::make_shared<Power>(pType, pPowerPosition);
}

void PowerFactory::onBrickDestroyed(BrickType pBrickType, Point pBrickPosition){
  bool powerGenerated = 0;
  srand(time(nullptr));
  
  int shouldGeneratePower = rand() % 3;

  if (shouldGeneratePower == 1){
    int chance = rand() % 100;
    
    if (chance < 10){
      createPower(PowerType::POWERUP_MISSILE, pBrickPosition);
    }
    else if (chance < 20) {
      createPower(PowerType::POWERUP_EXTRA_LIFE, pBrickPosition);
    }
    else if (chance < 30) {
      createPower(PowerType::POWERDOWN_SHRINK_PADDLE, pBrickPosition);
    }
    else if (chance < 50) {
      createPower(PowerType::POWERDOWN_SHRINK_BALL, pBrickPosition);
    }
    else if (chance < 70) {
      createPower(PowerType::POWERUP_EXPAND_PADDLE, pBrickPosition);
    }
    else if (chance < 100){
      createPower(PowerType::POWERUP_EXPAND_BALL, pBrickPosition);
    }
  }
}