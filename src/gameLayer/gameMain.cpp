#include <raylib.h>
#include <gameMain.h>
#include <iostream>
#include <fstream>

bool show_imgui = false;
int random_matrix_size = 1;
int rows = 1;
int cols = 1;

struct GameData
{
	float pos_X = 100;
	float pos_Y = 100;
	float speed = 100;
}gameData;

bool initGame()
{
	show_imgui = false;
	random_matrix_size = 1;
	rows = 1;
	cols = 1;
	return true;
}

bool updateGame()
{
	float deltaTime = GetFrameTime();

	if (deltaTime > 1.f/5)
	{
		deltaTime = 1 / 5.f;
	}	

	if (IsKeyPressed(KEY_GRAVE))
	{
		show_imgui = !show_imgui;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			DrawRectangle(i * 5, j * 5, 5, 5, BLACK);
		}
	}

	//DrawRectangle(gameData.pos_X, gameData.pos_Y, 50, 50, RED);
	//DrawText("Congrats! You created your first window!", 190, 200, 20, RED);

	return true;
}

void closeGame()
{
	std::cout << "Closing Game!!";
}

void Update_Random_Matrix(int size)
{
	rows = pow(2, size);
	cols = pow(2, size);

	std::cout << "Updating Random Matrix with size: " << size << " (" << rows << "x" << cols << ")" << std::endl;


}
