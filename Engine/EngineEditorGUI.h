#pragma once
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx12.h"

// Ό³Έν :
class UEngineEditorGUI
{
public:
	// constrcuter destructer
	UEngineEditorGUI();
	~UEngineEditorGUI();

	// delete Function
	UEngineEditorGUI(const UEngineEditorGUI& _Other) = delete;
	UEngineEditorGUI(UEngineEditorGUI&& _Other) noexcept = delete;
	UEngineEditorGUI& operator=(const UEngineEditorGUI& _Other) = delete;
	UEngineEditorGUI& operator=(UEngineEditorGUI&& _Other) noexcept = delete;
	static void GUIRender(float _DeltaTime);
	static void GUIInit();
	static void GUIRelease();

protected:

private:


	static ImGuiIO* IOPtr;

};

