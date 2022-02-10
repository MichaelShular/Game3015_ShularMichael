#pragma once
#include "entity.h"

class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
	};
public:
	Aircraft(Type type);

 
private:
	virtual void drawCurrent() const;
private:
	Type mType;
	std::string mSprite;
};

