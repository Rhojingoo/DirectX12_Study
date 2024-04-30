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

	GET_SINGLE(SceneManager)->LoadScene(L"TestScene");
}

void Game::Update()
{
	GEngine->Update();
	UEngineEditorGUI::GUIRender(GET_SINGLE(Timer)->GetDeltaTime());
}

void Game::End()
{
	UEngineEditorGUI::GUIRelease();
}
