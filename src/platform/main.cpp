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

		ClearBackground(WHITE);

#pragma region ImGui
		if (show_imgui)
		{
			rlImGuiBegin();

			ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
			ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
			ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
			ImGui::PopStyleColor(2);

			//ImGui::ShowDemoWindow();
#pragma region Imgui Game
			
			ImGui::Begin("Matrix Settings");

			ImGui::SliderInt("Random Matrix Size", &random_matrix_size, 1, 10);
			
			if (ImGui::Button("Update Random Matrix"))
			{
				Update_Random_Matrix(random_matrix_size);
			}


#pragma endregion

			ImGui::End();
			rlImGuiEnd();
		}
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