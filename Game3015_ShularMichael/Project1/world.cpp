#include "world.h"

World::World()
{
	loadTextures();
}

World::~World()
{
}

void World::update()
{
}

void World::draw()
{
}

std::unordered_map<std::string, std::wstring>* World::getTextures()
{
	return &mTexture;
}

void World::buildScene()
{
}

void World::loadTextures()
{
	CreateTexture("temp", L"WireFence.dds");
}

void World::CreateTexture(std::string name, std::wstring fileName)
{
	mTexture[name] = fileName;
}
