#pragma region step 2
#include "Player.h"
#include "CommandQueue.h"
#include "Aircraft.h""
#include "../../Common/d3dUtil.h"
#include "map"
#include "string"
#include "algorithm"
#include "../../Common/MathHelper.h"

struct AircraftMover
{
	AircraftMover(float vx, float vy)
		: mVelocity(vx, vy)
	{
	}

	void operator() (Aircraft& aircraft) const
	{
		aircraft.setVelocity(mVelocity);
	}

	XMFLOAT2 mVelocity;
};

Player::Player()
{
	// Set initial key bindings
	mKeyBinding[44] = MoveLeft;
	mKeyBinding[47] = MoveRight;
	mKeyBinding[66] = MoveUp;
	mKeyBinding[62] = MoveDown;

	// Set initial action bindings
	initializeActions();

	// Assign all categories to player's aircraft
	for (auto& pair : mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(CommandQueue& commands)
{

	// Check if pressed key appears in key binding, trigger command if so
	auto found = mKeyBinding.find(44);
	if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
		commands.push(mActionBinding[found->second]);
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
	// Traverse all assigned keys and check if they are pressed
	for (auto pair : mKeyBinding)
	{
		// If key is pressed, lookup action and trigger corresponding command
		if (d3dUtil::IsKeyDown(pair.first) && isRealtimeAction(pair.second))
		commands.push(mActionBinding[pair.second]);
	}
}


void Player::initializeActions()
{
	const float playerSpeed = 200.f;

	mActionBinding[MoveLeft].action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
	mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(+playerSpeed, 0.f));
	mActionBinding[MoveUp].action = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
	mActionBinding[MoveDown].action = derivedAction<Aircraft>(AircraftMover(0.f, +playerSpeed));
}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
	case MoveLeft:
	case MoveRight:
	case MoveDown:
	case MoveUp:
		return true;

	default:
		return false;
	}
}

#pragma endregion
