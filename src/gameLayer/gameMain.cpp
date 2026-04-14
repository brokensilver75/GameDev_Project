#include <raylib.h>
#include <gameMain.h>
#include <iostream>
#include <fstream>

struct GameData
{
}gameData;

bool initGame()
{
	return true;
}

bool updateGame()
{
	float deltaTime = GetFrameTime();	

	return true;
}

void closeGame()
{
	std::cout << "Closing Game!!";
}
