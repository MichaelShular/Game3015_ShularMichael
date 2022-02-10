#pragma once
#ifndef WORLD_H
#define WORLD_H

#include "../../Common/d3dApp.h"
#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "FrameResource.h"
#include "../../Common/GeometryGenerator.h"
using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")

class Game;

class World
{
public:
	World(Game * game);
	void update(const GameTimer& gt);
	void draw(const GameTimer& gt);
	std::unordered_map<std::string, std::wstring> *getTextures();
	
private:
	void CreateTexture(std::string name, std::wstring fileName);
	void buildScene();
	void loadTextures();
private:
	Game *mGame;
	//Aircraft* mplayerAircraft;
	std::unordered_map<std::string, std::wstring> mTexture;
};

#endif
