#pragma once
#include "imgui.h"
#include "NameObject.h"

// 우린 이것만 사용합니다.
// 여러분들이 나만의 창을 띄우고 싶어.

// 설명 :
class Scene;
class UEngineEditorGUI;
class UEngineEditorWindow : public UNameObject
{
	friend UEngineEditorGUI;

public:
	// constrcuter destructer
	UEngineEditorWindow();
	~UEngineEditorWindow();

	// delete Function
	UEngineEditorWindow(const UEngineEditorWindow& _Other) = delete;
	UEngineEditorWindow(UEngineEditorWindow&& _Other) noexcept = delete;
	UEngineEditorWindow& operator=(const UEngineEditorWindow& _Other) = delete;
	UEngineEditorWindow& operator=(UEngineEditorWindow&& _Other) noexcept = delete;

	void On()
	{
		IsActive = true;
	}

	void Off()
	{
		IsActive = false;
	}

protected:
	virtual void Init() {}
	virtual void Update(Scene* _scene, float _Delta);
	virtual void OnGui(Scene* _scene, float _Delta) = 0;

private:
	std::string Title;
	bool IsActive = true;

	void Begin();
	void End();
};

