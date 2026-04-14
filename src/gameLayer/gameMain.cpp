#include <raylib.h>
#include <gameMain.h>
#include <iostream>
#include <asserts.h>
#include <assetManager.h>

struct GameData
{
}gameData;

AssetManager asset_manager;

bool initGame()
{
	asset_manager.loadAll();
	return true;
}

bool updateGame()
{
	float deltaTime = GetFrameTime();
	if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; }

	DrawTexturePro(asset_manager.dirt, { 0, 0, (float)asset_manager.dirt.width, (float)asset_manager.dirt.height }, { 50, 50, 100, 100 }, {}, 0, WHITE);
	

	return true;
}

void closeGame()
{
	std::cout << "Closing Game!!";
}
