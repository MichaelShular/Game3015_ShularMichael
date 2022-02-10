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
	mGame->BuildMaterials("desert");
	mGame->BuildMaterials("sky");
	mGame->BuildMaterials("eagle");
	mGame->BuildMaterials("raptor");

	std::unique_ptr<Aircraft> BGGround(new Aircraft(Aircraft::Eagle));
	mplayerAircraft = BGGround.get();
	mplayerAircraft->attachChild(std::move(BGGround));
	mplayerAircraft->setWorldPosition(0.0f, 0.0f, 0.0f);
	mplayerAircraft->setWorldRotation(0.0f, 0.0f, 0.0f);
	mplayerAircraft->setWorldScale(2.0f, 3.0f, 0.0f);

	mGame->BuildRenderItems("desert", "box", mplayerAircraft->getWorldPosition(), mplayerAircraft->getWorldRotation(), mplayerAircraft->getWorldScale());
	sceneGraph->attachChild(std::move(BGGround));

	std::unique_ptr<Aircraft> BGSky(new Aircraft(Aircraft::Eagle));
	mplayerAircraft2 = BGSky.get();
	mplayerAircraft2->attachChild(std::move(BGSky));
	mplayerAircraft2->setWorldPosition(1.0f, 0.0f, 0.5f);
	mplayerAircraft2->setWorldRotation(1.57f, 0.0f, 0.0f);
	mplayerAircraft2->setWorldScale(0.0f, 2.0f, 3.0f);

	mGame->BuildRenderItems("sky", "box", mplayerAircraft2->getWorldPosition(), mplayerAircraft2->getWorldRotation(), mplayerAircraft2->getWorldScale());
	//sceneGraph->attachChild(std::move(player));

	/*std::unique_ptr<Aircraft> BGSky2(new Aircraft(Aircraft::Eagle));
	mplayerAircraft3 = BGSky2.get();
	mplayerAircraft3->attachChild(std::move(BGSky2));
	mplayerAircraft3->setWorldPosition(0.0f, 1.0f, 0.5f);
	mplayerAircraft3->setWorldRotation(0.0f, 0.0f, 0.0f);
	mplayerAircraft3->setWorldScale(1.0f, 0.0f, 1.0f);

	mGame->BuildRenderItems("sky", "box", mplayerAircraft3->getWorldPosition(), mplayerAircraft3->getWorldRotation(), mplayerAircraft3->getWorldScale());*/

	std::unique_ptr<Aircraft> eaglePlane(new Aircraft(Aircraft::Eagle));
	mplayerAircraft4 = eaglePlane.get();
	mplayerAircraft4->attachChild(std::move(eaglePlane));
	mplayerAircraft4->setWorldPosition(0.4f, -1.5f, 0.6f);
	mplayerAircraft4->setWorldRotation(0.0f, 1.0f, 0.2f);
	mplayerAircraft4->setWorldScale(0.05f, 0.05f, 0.0f);

	mGame->BuildRenderItems("eagle", "box", mplayerAircraft4->getWorldPosition(), mplayerAircraft4->getWorldRotation(), mplayerAircraft4->getWorldScale());

	std::unique_ptr<Aircraft> raptorPlane(new Aircraft(Aircraft::Eagle));
	mplayerAircraft5 = raptorPlane.get();
	mplayerAircraft5->attachChild(std::move(raptorPlane));
	mplayerAircraft5->setWorldPosition(0.3f, -1.6f, 0.4f);
	mplayerAircraft5->setWorldRotation(0.0f, 1.0f, 0.1f);
	mplayerAircraft5->setWorldScale(0.05f, 0.05f, 0.0f);

	mGame->BuildRenderItems("raptor", "box", mplayerAircraft5->getWorldPosition(), mplayerAircraft5->getWorldRotation(), mplayerAircraft5->getWorldScale());

}

void World::loadTextures()
{
	CreateTexture("desert", L"Desert.dds");
	CreateTexture("sky", L"sky.dds");
	CreateTexture("eagle", L"Eagle.dds");
	CreateTexture("raptor", L"Raptor.dds");
}

void World::CreateTexture(std::string name, std::wstring fileName)
{
	mTexture[name] = fileName;
}
