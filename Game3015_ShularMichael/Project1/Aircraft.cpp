#include "Aircraft.h"

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