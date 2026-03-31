#include <iostream>
#include <raylib.h>

int main()
{
	SetConfigFlags (FLAG_WINDOW_RESIZABLE);

	InitWindow(800, 450, "First Window");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		//DrawText("Congrats! You created your first window!", 190, 200, 20, RED);
		DrawRectangle(50, 50, 100, 100, {255, 0, 0, 127});
		DrawRectangle(75, 75, 100, 100, {0, 255, 0, 127});

		EndDrawing();
	}

	CloseWindow();

	return 0;
}