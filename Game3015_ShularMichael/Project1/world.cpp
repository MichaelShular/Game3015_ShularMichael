#include "world.h"
#include "Game.h"

World::World(Game* game):
	sceneGraph(new sceneNode())
{
	mGame = game;
	//mGame->LoadTextures("temp", L"WireFence.dds");
	loadTextures();
}

void World::update(const GameTimer& gt)
{
	sceneGraph->update(gt);
}

void World::draw(const GameTimer& gt)
{
}

std::unordered_map<std::string, std::wstring>* World::getTextures()
{
	return &mTexture;
}

void World::buildScene()
{
	std::unique_ptr<Aircraft> player(new Aircraft(Aircraft::Eagle));
	mplayerAircraft = player.get();
	mplayerAircraft->attachChild(std::move(player));
	mplayerAircraft->setWorldPosition(0.0f, 0.0f, 0.0f);
	mplayerAircraft->setWorldRotation(0.0f, 0.0f, 0.0f);
	mplayerAircraft->setWorldScale(1.0f, 1.0f, 1.0f);

	mGame->BuildRenderItems("woodCrate", "box", mplayerAircraft->getWorldPosition(), mplayerAircraft->getWorldRotation(), mplayerAircraft->getWorldScale());
	//sceneGraph->attachChild(std::move(player));
}

void World::loadTextures()
{
	CreateTexture("temp", L"WireFence.dds");
}

void World::CreateTexture(std::string name, std::wstring fileName)
{
	mTexture[name] = fileName;
}
