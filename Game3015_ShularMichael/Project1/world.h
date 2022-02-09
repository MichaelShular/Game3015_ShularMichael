#pragma once

#include "sceneNode.h"
#include "Aircraft.h"
#include "../../Common/d3dApp.h"
#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "FrameResource.h"
#include "../../Common/GeometryGenerator.h"
#include "world.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")

class World
{
public:
	World();
	~World();
	void update();
	void draw();
	std::unordered_map<std::string, std::wstring> *getTextures();
	std::unordered_map<std::string, std::wstring> mTexture;
private:
	void CreateTexture(std::string name, std::wstring fileName);
	void buildScene();
	void loadTextures();
private:
	
	Aircraft* mplayerAircraft;
};


