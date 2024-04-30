#include "pch.h"
#include "Game.h"
#include "Engine.h"
#include "SceneManager.h"

#include <../Engine/Timer.h>
#include <../Engine/EngineEditorGUI.h>


void Game::Init(const WindowInfo& info)
{
	GEngine->Init(info);

	UEngineEditorGUI::GUIInit();

	GET_SINGLE(SceneManager)->Init();
	
}

void Game::Update()
{
	GEngine->Update();
}
	

void Game::End()
{
	UEngineEditorGUI::GUIRelease();
}
