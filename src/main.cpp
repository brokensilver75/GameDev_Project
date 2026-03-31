#include <iostream>
#include <raylib.h>
#include  <imgui.h>
#include <rlImGui.h>

int main()
{
	SetConfigFlags (FLAG_WINDOW_RESIZABLE);

	InitWindow(800, 450, "First Window");

	rlImGuiSetup(true);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		rlImGuiBegin();

		//DrawText("Congrats! You created your first window!", 190, 200, 20, RED);
		DrawRectangle(50, 50, 100, 100, {255, 0, 0, 127});
		DrawRectangle(75, 75, 100, 100, {0, 255, 0, 127});

		ImGui::ShowDemoWindow();
		/*ImGui::Begin("test");

		ImGui::Text("hello");
		ImGui::Button("button");

		ImGui::End();*/

		rlImGuiEnd();

		EndDrawing();
	}

	rlImGuiShutdown();

	CloseWindow();

	return 0;
}