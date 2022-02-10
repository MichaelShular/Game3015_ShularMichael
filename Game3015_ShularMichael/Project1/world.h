#pragma once
#ifndef WORLD_H
#define WORLD_H

#include "../../Common/d3dApp.h"
#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "FrameResource.h"
#include "../../Common/GeometryGenerator.h"
#include "Aircraft.h"
#include "sceneNode.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")

class Game;
/// This class is use to build game objects and hold sceneNode which will hold all objects that are part of the game
class World
{
public:
	World(Game * game);
	void update(const GameTimer& gt);
	void draw(const GameTimer& gt);
	std::unordered_map<std::string, std::wstring> *getTextures();
	void buildScene();
private:
	void CreateTexture(std::string name, std::wstring fileName);
	void loadTextures();
private:
	Game *mGame;
	Aircraft* mplayerAircraft;
	Aircraft* mplayerAircraft2;
	Aircraft* mplayerAircraft3;
	Aircraft* mplayerAircraft4;
	Aircraft* mplayerAircraft5;

	sceneNode* sceneGraph;
	std::unordered_map<std::string, std::wstring> mTexture;
};

#endif
