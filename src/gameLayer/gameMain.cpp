#include <raylib.h>
#include <gameMain.h>
#include <iostream>
#include <asserts.h>
#include <assetManager.h>
#include <gameMap.h>
#include <helpers.h>

struct GameData
{
	GameMap gameMap;
	Camera2D camera;
}gameData;

AssetManager asset_manager;

bool initGame()
{
	asset_manager.loadAll();

	gameData.gameMap.create(30, 30);

	/*gameData.gameMap.getBlockUnsafe(0, 0).type = Block::dirt;
	gameData.gameMap.getBlockUnsafe(1, 1).type = Block::grass;
	gameData.gameMap.getBlockUnsafe(2, 2).type = Block::goldBlock;
	gameData.gameMap.getBlockUnsafe(3, 3).type = Block::glass;
	gameData.gameMap.getBlockUnsafe(4, 4).type = Block::platform;*/

	for (int y = 0; y < gameData.gameMap.h; y++)
		for (int x = 0; x < gameData.gameMap.w; x++)
		{

			float s = (std::sin(x) + 1.f) / 2.f;
			float s2 = (std::sin(x * 0.5) + 1.f) / 2.f;

			if (gameData.gameMap.h - (gameData.gameMap.h * 0.3 * s) - gameData.gameMap.h * 0.5 -
				(gameData.gameMap.h * 0.2 * s2)

				< y)
			{
				gameData.gameMap.getBlockUnsafe(x, y).type = Block::dirt;
			}
			else
			{
				gameData.gameMap.getBlockUnsafe(x, y).type = Block::air;
			}
		}

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
				Rectangle textureUV;
				textureUV.width = 32;
				textureUV.height = 32;
				textureUV.x = block.type * 32;
				textureUV.y = 0;

				float size = 1;
				float posX = x * size;
				float posY = y * size;

				DrawTexturePro(
					asset_manager.textures,
					GetTextureAtlas(block.type, 0, 32, 32),
					//Rectangle{ 0.f,0.f,(float)asset_manager.dirt.width, (float)asset_manager.dirt.height},
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
