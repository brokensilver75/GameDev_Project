#include <raylib.h>
#include <gameMain.h>
#include <iostream>
#include <asserts.h>
#include <assetManager.h>
#include <gameMap.h>
#include <helpers.h>
#include <raymath.h>

bool show_imgui = false; // single definition
int selected_block = 0;

struct GameData
{
	GameMap gameMap;
	Camera2D camera;
}gameData;

AssetManager asset_manager;

bool initGame()
{
	asset_manager.loadAll();

	gameData.gameMap.create(700, 500);	

	/*gameData.gameMap.getBlockUnsafe(0, 0).type = Block::dirt;
	gameData.gameMap.getBlockUnsafe(1, 1).type = Block::grass;
	gameData.gameMap.getBlockUnsafe(2, 2).type = Block::goldBlock;
	gameData.gameMap.getBlockUnsafe(3, 3).type = Block::glass;
	gameData.gameMap.getBlockUnsafe(4, 4).type = Block::platform;*/

	for (int i = 0; i < 700; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			gameData.gameMap.getBlockUnsafe(i, j).type = Block::stone;
		}
	}

	gameData.camera.target = { 0, 0 }; // world space center
	gameData.camera.rotation = 0.0f;
	gameData.camera.zoom = 100.0f;

	show_imgui = false; // optional (keeps initial state explicit)

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

	Vector2 worldPos = GetScreenToWorld2D(GetMousePosition(), gameData.camera);
	int blockX = (int)floor(worldPos.x);
	int blockY = (int)floor(worldPos.y);

	//BREAK BLOCK
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		auto b = gameData.gameMap.getBlockSafe(blockX, blockY);

		if (b)
		{
			*b = {};
		}
	}

	//PLACE BLOCK
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		auto b = gameData.gameMap.getBlockSafe(blockX, blockY);
		if (b)
		{
			b->type = selected_block;//Block::gold;
		}
	}

	if (IsKeyPressed(KEY_GRAVE))
	{
		show_imgui = !show_imgui;		
	}

	BeginMode2D(gameData.camera);

	Vector2 top_left_view = GetScreenToWorld2D({ 0, 0 }, gameData.camera);
	Vector2 bottom_right_view = GetScreenToWorld2D({ (float)GetScreenWidth(), (float)GetScreenHeight() }, gameData.camera);

	int start_view_x = (int)floorf(top_left_view.x - 1);
	int end_view_x = (int)ceilf(bottom_right_view.x + 1);
	int start_view_y = (int)floorf(top_left_view.y - 1);
	int end_view_y = (int)floorf(bottom_right_view.y - 1);

	start_view_x = Clamp(start_view_x, 0, gameData.gameMap.w - 1);
	end_view_x = Clamp(end_view_x, 0, gameData.gameMap.w - 1);

	start_view_y = Clamp(start_view_y, 0, gameData.gameMap.h - 1);
	end_view_y = Clamp(end_view_y, 0, gameData.gameMap.h - 1);

	for (int y = start_view_y; y < end_view_y; y++)
	{
		for (int x = start_view_x; x < end_view_x; x++)
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
					asset_manager.block_texture_atlas,
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

	//Draw selected block
	DrawTexturePro(
		asset_manager.frame,
		{ 0, 0, (float)asset_manager.frame.width, (float)asset_manager.frame.height }, //source
		{ (float)blockX, (float)blockY, 1, 1 }, //dest
		{ 0, 0 }, //origin (top left corner)
		0.0f, //rotation
		WHITE //tint
	);

	EndMode2D();
	
	DrawFPS(10, 10);

	return true;
}

void closeGame()
{
	std::cout << "Closing Game!!";
}
