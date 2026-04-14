#include <raylib.h>
#include <gameMain.h>
#include <iostream>
#include <fstream>

struct GameData
{
	float pos_X = 100;
	float pos_Y = 100;
	float speed = 100;
}gameData;

bool initGame()
{
	return true;
}

bool updateGame()
{
	float deltaTime = GetFrameTime();

	if (deltaTime > 1.f/5)
	{
		deltaTime = 1 / 5.f;
	}

	if (IsKeyDown(KEY_W)) { gameData.pos_Y -= gameData.speed * deltaTime; }
	if (IsKeyDown(KEY_A)) { gameData.pos_X -= gameData.speed * deltaTime; }
	if (IsKeyDown(KEY_S)) { gameData.pos_Y += gameData.speed * deltaTime; }
	if (IsKeyDown(KEY_D)) { gameData.pos_X += gameData.speed * deltaTime; }


	DrawRectangle(gameData.pos_X, gameData.pos_Y, 50, 50, RED);
	//DrawText("Congrats! You created your first window!", 190, 200, 20, RED);

	return true;
}

void closeGame()
{
	std::cout << "Closing Game!!";
}
