#include "gameobjects/Power.hpp"

using namespace GameObjects;

Power::Power(PowerType type, Point point, double length, double mass) : GameObject(point, 70, 70, Vector(0, 10), 0, 0)
{
    this->mType = type;
    this->mLength = length;
    this->mMass = mass;
    this->entityType = GameObjectType::GameObjectPower;
}

PowerExtendBall::PowerExtendBall(Point point, double length, double mass) : Power(PowerType::POWERUP_EXPAND_BALL, point, length, mass) {
    texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Powerup_Expand_Ball);
}

void PowerExtendBall::description() {
	std::cout << "PowerExtendBall" << std::endl;
}

void PowerExtendBall::update() {
}

void PowerExtendBall::collide(std::shared_ptr<GameObject> pOther) {
	// std::cout << "PowerExtendBall collided with something" << std::endl;
}

void PowerExtendBall::addObserver(std::shared_ptr<IPowerObserver> observer)
{
    mObservers.push_back(observer);
}

PowerShrinkBall::PowerShrinkBall(Point point, double length, double mass) : Power(PowerType::POWERDOWN_SHRINK_BALL, point, length, mass) {
    texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Powerdown_Shrink_Ball);
}

void PowerShrinkBall::description() {
    std::cout << "PowerExtendBall" << std::endl;
}

void PowerShrinkBall::update() {
}

void PowerShrinkBall::collide(std::shared_ptr<GameObject> pOther) {
    // std::cout << "PowerExtendBall collided with something" << std::endl;
}

void PowerShrinkBall::addObserver(std::shared_ptr<IPowerObserver> observer)
{
    mObservers.push_back(observer);
}

PowerExtendPaddle::PowerExtendPaddle(Point point, double length, double mass) : Power(PowerType::POWERUP_EXPAND_PADDLE, point, length, mass) {
    texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Powerup_Expand_Paddle);
}

void PowerExtendPaddle::description() {
    std::cout << "PowerExtendBall" << std::endl;
}

void PowerExtendPaddle::update() {
}

void PowerExtendPaddle::collide(std::shared_ptr<GameObject> pOther) {
    // std::cout << "PowerExtendBall collided with something" << std::endl;
}

void PowerExtendPaddle::addObserver(std::shared_ptr<IPowerObserver> observer)
{
    mObservers.push_back(observer);
}

PowerShrinkPaddle::PowerShrinkPaddle(Point point, double length, double mass) : Power(PowerType::POWERDOWN_SHRINK_PADDLE, point, length, mass) {
    texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Powerdown_Shrink_Paddle);
}

void PowerShrinkPaddle::description() {
    std::cout << "PowerExtendBall" << std::endl;
}

void PowerShrinkPaddle::update() {
}

void PowerShrinkPaddle::collide(std::shared_ptr<GameObject> pOther) {
    // std::cout << "PowerExtendBall collided with something" << std::endl;
}

void PowerShrinkPaddle::addObserver(std::shared_ptr<IPowerObserver> observer)
{
    mObservers.push_back(observer);
}

PowerExtraLife::PowerExtraLife(Point point, double length, double mass) : Power(PowerType::POWERUP_EXTRA_LIFE, point, length, mass) {
    texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Powerup_Extra_Life);
}

void PowerExtraLife::description() {
    std::cout << "PowerExtendBall" << std::endl;
}

void PowerExtraLife::update() {
}

void PowerExtraLife::collide(std::shared_ptr<GameObject> pOther) {
    // std::cout << "PowerExtendBall collided with something" << std::endl;
}

void PowerExtraLife::addObserver(std::shared_ptr<IPowerObserver> observer)
{
    mObservers.push_back(observer);
}

PowerFireBall::PowerFireBall(Point point, double length, double mass) : Power(PowerType::POWERUP_FIREBALL, point, length, mass) {
    texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Powerup_Fireball);
}

void PowerFireBall::description() {
    std::cout << "PowerExtendBall" << std::endl;
}

void PowerFireBall::update() {
}

void PowerFireBall::collide(std::shared_ptr<GameObject> pOther) {
    // std::cout << "PowerExtendBall collided with something" << std::endl;
}

void PowerFireBall::addObserver(std::shared_ptr<IPowerObserver> observer)
{
    mObservers.push_back(observer);
}