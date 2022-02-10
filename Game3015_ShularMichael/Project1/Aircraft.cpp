#include "Aircraft.h"

/// The defualt conconstructor
/// 
/// @param: enum Type: use to switch sprites
Aircraft::Aircraft(Type type) : Entity()
{
	switch (type)
	{
	case Aircraft::Eagle:  
		 mSprite = "Eagle";
		 break;
	case Aircraft::Raptor:
		mSprite = "Raptor";
		break;
	default:
		mSprite = "Eagle";
		break;
	}
}

void Aircraft::drawCurrent() const
{
}