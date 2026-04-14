#include <iostream>
#include <raylib.h>
#include  <imgui.h>
#include <rlImGui.h>
#include <gameMain.h>

int main()
{
#if PRODUCTION_BUILD == 1
	SetTraceLogLevel(LOG_NONE); // no log output to console by raylib  
#endif

	SetConfigFlags (FLAG_WINDOW_RESIZABLE);

	InitWindow(800, 450, "First Window");

	SetExitKey(KEY_NULL); // Disable Esc from closing game.

	SetTargetFPS(240);

	rlImGuiSetup(true);

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.FontGlobalScale = 2;

	if (!initGame())
	{
		return 0;
	}


	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

#pragma region ImGui
		rlImGuiBegin();

		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);

		//ImGui::ShowDemoWindow();
#pragma region Imgui Game

#pragma endregion

		rlImGuiEnd();
#pragma endregion

		if (!updateGame())
		{
			CloseWindow();
		}


		EndDrawing();
	}

	rlImGuiShutdown();

	CloseWindow();

	closeGame();

	return 0;
}