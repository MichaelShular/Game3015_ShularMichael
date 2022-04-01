#pragma region step 2
#include "Player.h"
#include "CommandQueue.h"
#include "Aircraft.h"
#include "../../Common/d3dUtil.h"
#include "map"
#include "string"
#include "algorithm"
#include "../../Common/MathHelper.h"
#include <windows.system.diagnostics.h>

struct AircraftMover
{
	AircraftMover(float vx, float vy)
		: mVelocity(vx, vy)
	{
	}

	void operator() (Aircraft& aircraft, const GameTimer& gt) const
	{
		aircraft.setVelocity(mVelocity);
	}

	XMFLOAT2 mVelocity;
};

Player::Player()
{
	// Set initial key bindings
	mKeyBinding[VK_LEFT] = MoveLeft;
	mKeyBinding[VK_RIGHT] = MoveRight;
	mKeyBinding[VK_UP] = MoveUp;
	mKeyBinding[VK_DOWN] = MoveDown;

	// Set initial action bindings
	initializeActions();

	// Assign all categories to player's aircraft
	for (auto& pair : mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(CommandQueue& commands, int key)
{

	//OutputDebugStringW((L"asad dd aaaa\n"));
	// Check if pressed key appears in key binding, trigger command if so
	auto found = mKeyBinding.find(key);
	if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
		commands.push(mActionBinding[found->second]);

}

void Player::handleRealtimeInput(CommandQueue& commands, int key)
{
	// Traverse all assigned keys and check if they are pressed
	for (auto pair : mKeyBinding)
	{
		// If key is pressed, lookup action and trigger corresponding command
		if (GetAsyncKeyState(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}


void Player::initializeActions()
{
	const float playerSpeed = 1.0f;

	mActionBinding[MoveLeft].action = derivedAction<Aircraft>(AircraftMover(playerSpeed, 0.f));
	mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
	mActionBinding[MoveUp].action = derivedAction<Aircraft>(AircraftMover(0.f, playerSpeed));
	mActionBinding[MoveDown].action = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
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

void Player::assignKey(Action action, unsigned int key)
{
	// Remove all keys that already map to action
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyBinding[key] = action;
}

unsigned int Player::getAssignedKey(Action action) const
{
	for (auto pair : mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}
	return  0x000;
}

#pragma endregion
