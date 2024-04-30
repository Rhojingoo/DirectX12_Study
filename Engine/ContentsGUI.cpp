#include "pch.h"
#include "ContentsGUI.h"

ContentsGUI::ContentsGUI() 
{
}

ContentsGUI::~ContentsGUI() 
{
}

void ContentsGUI::Init() 
{
}

void ContentsGUI::OnGui(Scene* Level, float _Delta)
{
    {
       // static float f = 0.0f;
       // static int counter = 0;

       // ImGuiIO& io = ImGui::GetIO(); (void)io;

       //// ImGui::Begin("Hello, world!");
       // ImGui::Text("This is some useful text.");
       // ImGui::Checkbox("Demo Window",&show_demo_window);
       // ImGui::Checkbox("Another Window",&show_another_window);
       // ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
       // ImGui::ColorEdit3("clear color", (float*)&clear_color);

       // if (ImGui::Button("Button"))
       //     counter++;
       // ImGui::SameLine();
       // ImGui::Text("counter = %d", counter);

       // ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
       // ImGui::End();
    }


	if (true == ImGui::Button("TitleLevel"))
	{
		//GEngine->ChangeLevel("TitleLevel");
	}

	if (true == ImGui::Button("TestLevel"))
	{
		//GEngine->ChangeLevel("TestLevel");
	}
}
