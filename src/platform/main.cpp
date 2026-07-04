#include <iostream>
#include <raylib.h>
#include  <imgui.h>
#include <rlImGui.h>
#include <gameMain.h>
#include <block.h>

int main()
{
#if PRODUCTION_BUILD == 1
	SetTraceLogLevel(LOG_NONE); // no log output to console by raylib  
#endif

	SetConfigFlags (FLAG_WINDOW_RESIZABLE);

	InitWindow(1280, 720, "Game Window");

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

		if (!updateGame())
		{
			CloseWindow();
		}
		
#pragma region ImGui
			
		if (show_imgui)
			{
				rlImGuiBegin();

				ImGui::Begin("Block Selector");
				ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
				ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
				ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
				ImGui::PopStyleColor(2);

#pragma region Imgui Game
				ImGui::Text("Block Slider:");
				ImGui::SliderInt("##Block_Type_Slider", &selected_block, 0, Block::BLOCKS_COUNT - 1);
				ImGui::Text("%s", Block::names[selected_block]);
#pragma endregion

				ImGui::End();
				rlImGuiEnd();
			}
#pragma endregion

		EndDrawing();
	}

	rlImGuiShutdown();

	CloseWindow();

	closeGame();

	return 0;
}