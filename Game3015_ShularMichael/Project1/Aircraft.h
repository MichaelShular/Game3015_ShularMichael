#pragma once
#include "entity.h"

///This class is the derived class from entity but only of aircrafts
class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
	};
public:
	Aircraft(Type type, Game* game);

	virtual unsigned int getCategory() const;
	void buildAircraft();
private:
	virtual void drawCurrent() const;
private:
	Type mType;
	std::string mSprite;

protected:
	Game* mGame;
};

