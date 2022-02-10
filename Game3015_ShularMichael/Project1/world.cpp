#include "world.h"
#include "Game.h"
/// The defualt conconstructor
///
/// @param: Game
World::World(Game* game):
	sceneGraph(new sceneNode())
{
	mGame = game;
	loadTextures();
}
/// Used update sceneNode class
/// 
/// @param: const GameTimer&
void World::update(const GameTimer& gt)
{
	sceneGraph->update(gt);
}
/// Used draw
/// 
/// @param: const GameTimer&
void World::draw(const GameTimer& gt)
{
}
/// Used to pass information about textures to game 
/// 
/// @returns &std::unordered_map<std::string, std::wstring>
std::unordered_map<std::string, std::wstring>* World::getTextures()
{
	return &mTexture;
}
/// Used to construct materials for scene and game objects
void World::buildScene()
{
	mGame->BuildMaterials("desert");
	mGame->BuildMaterials("sky");
	mGame->BuildMaterials("eagle");
	mGame->BuildMaterials("raptor");

	std::unique_ptr<Aircraft> BGGround(new Aircraft(Aircraft::Eagle));
	mplayerAircraft = BGGround.get();
	mplayerAircraft->setWorldPosition(0.0f, 0.0f, 0.0f);
	mplayerAircraft->setWorldRotation(0.0f, 0.0f, 0.0f);
	mplayerAircraft->setWorldScale(2.0f, 3.0f, 0.0f);
	mGame->BuildRenderItems("desert", "box", mplayerAircraft->getWorldPosition(), mplayerAircraft->getWorldRotation(), mplayerAircraft->getWorldScale());
	sceneGraph->attachChild(std::move(BGGround));

	std::unique_ptr<Aircraft> BGSky(new Aircraft(Aircraft::Eagle));
	mplayerAircraft2 = BGSky.get();
	mplayerAircraft2->setWorldPosition(1.0f, 0.0f, 0.5f);
	mplayerAircraft2->setWorldRotation(1.57f, 0.0f, 0.0f);
	mplayerAircraft2->setWorldScale(0.0f, 2.0f, 3.0f);
	sceneGraph->attachChild(std::move(BGSky));

	mGame->BuildRenderItems("sky", "box", mplayerAircraft2->getWorldPosition(), mplayerAircraft2->getWorldRotation(), mplayerAircraft2->getWorldScale());

	std::unique_ptr<Aircraft> eaglePlane(new Aircraft(Aircraft::Eagle));
	mplayerAircraft4 = eaglePlane.get();
	mplayerAircraft4->setWorldPosition(0.7f, -1.5f, 0.6f);
	mplayerAircraft4->setWorldRotation(0.0f, 1.0f, 0.2f);
	mplayerAircraft4->setWorldScale(0.05f, 0.05f, 0.0f);
	sceneGraph->attachChild(std::move(eaglePlane));

	mGame->BuildRenderItems("eagle", "box", mplayerAircraft4->getWorldPosition(), mplayerAircraft4->getWorldRotation(), mplayerAircraft4->getWorldScale());

	std::unique_ptr<Aircraft> raptorPlane(new Aircraft(Aircraft::Eagle));
	mplayerAircraft5 = raptorPlane.get();
	mplayerAircraft5->setWorldPosition(0.3f, -1.6f, 0.4f);
	mplayerAircraft5->setWorldRotation(0.0f, 1.0f, 0.1f);
	mplayerAircraft5->setWorldScale(0.05f, 0.05f, 0.0f);
	sceneGraph->attachChild(std::move(raptorPlane));

	mGame->BuildRenderItems("raptor", "box", mplayerAircraft5->getWorldPosition(), mplayerAircraft5->getWorldRotation(), mplayerAircraft5->getWorldScale());
}
/// Used get set all information for textures
void World::loadTextures()
{
	CreateTexture("desert", L"Desert.dds");
	CreateTexture("sky", L"sky.dds");
	CreateTexture("eagle", L"Eagle.dds");
	CreateTexture("raptor", L"Raptor.dds");
}
/// Used save information about textures name and file path
/// 
/// @param: std::string
/// @param: std::wstring
void World::CreateTexture(std::string name, std::wstring fileName)
{
	mTexture[name] = fileName;
}
