#include <raylib.h>
#include <gameMain.h>
#include <iostream>
#include <asserts.h>
#include <assetManager.h>
#include <gameMap.h>

struct GameData
{
	GameMap gameMap;
	Camera2D camera;
}gameData;

AssetManager asset_manager;

bool initGame()
{
	asset_manager.loadAll();

	gameData.gameMap.create(30, 10);

	gameData.gameMap.getBlockUnsafe(0, 0).type = Block::dirt;
	gameData.gameMap.getBlockUnsafe(1, 1).type = Block::dirt;
	gameData.gameMap.getBlockUnsafe(2, 2).type = Block::dirt;
	gameData.gameMap.getBlockUnsafe(3, 3).type = Block::dirt;
	gameData.gameMap.getBlockUnsafe(4, 4).type = Block::dirt;

	gameData.camera.target = { 0, 0 }; // world space center
	gameData.camera.rotation = 0.0f;
	gameData.camera.zoom = 100.0f;

	return true;
}

bool updateGame()
{
	float deltaTime = GetFrameTime();
	if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; }

	gameData.camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };

	//DrawTexturePro(asset_manager.dirt, { 0, 0, (float)asset_manager.dirt.width, (float)asset_manager.dirt.height }, { 50, 50, 100, 100 }, {}, 0, WHITE);
	ClearBackground(SKYBLUE);

#pragma region	Camera Movement
	if (IsKeyDown(KEY_LEFT)) gameData.camera.target.x -= 7.f * deltaTime;
	if (IsKeyDown(KEY_RIGHT)) gameData.camera.target.x += 7.f * deltaTime;
	if (IsKeyDown(KEY_UP)) gameData.camera.target.y -= 7.f * deltaTime;
	if (IsKeyDown(KEY_DOWN)) gameData.camera.target.y += 7.f * deltaTime;
#pragma endregion

	BeginMode2D(gameData.camera);

	for (int y = 0; y < gameData.gameMap.h; y++)
	{
		for (int x = 0; x < gameData.gameMap.w; x++)
		{
			auto& block = gameData.gameMap.getBlockUnsafe(x, y);

			if (block.type != Block::air)
			{
				float size = 1;
				float posX = x * size;
				float posY = y * size;

				DrawTexturePro(
					asset_manager.dirt,
					Rectangle{ 0.f,0.f,(float)asset_manager.dirt.width, (float)asset_manager.dirt.height},
					{ posX, posY, size, size },
					{ 0,0 },
					0.0f,
					WHITE
				);
			}
		}
	}

	EndMode2D();
	

	return true;
}

void closeGame()
{
	std::cout << "Closing Game!!";
}
