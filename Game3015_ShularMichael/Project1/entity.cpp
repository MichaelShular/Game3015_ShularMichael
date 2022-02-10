#include "entity.h"
/// The defualt conconstructor
Entity::Entity() : sceneNode ()
{
}
/// Used to set velocity of an game object
/// 
/// /// @param: DirectX::XMFLOAT2
void Entity::setVelocity(XMFLOAT2 velocity)
{
	mVelocity = velocity;
}
/// Used to set velocity of an game object
/// 
/// @param: a float in the x direction
/// @param: a float in the y direction
void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}
/// Used to get the velocity of game object
/// 
/// @returns DirectX::XMFLOAT2
XMFLOAT2 Entity::getVelocity() const
{
	return mVelocity;
}
/// Used update entities velocity
/// 
/// @param: GameTimer 
void Entity::updateCurrent(const GameTimer& gt)
{
	mVelocity.x * gt.DeltaTime();
	mVelocity.y * gt.DeltaTime();

}