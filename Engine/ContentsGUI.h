#pragma once
#include "EngineEditorWindow.h"

// 설명 : 내가 만드는 게임 전반에서 사용할 내용들
class ParticleOBJ;
class ContentsGUI : public UEngineEditorWindow
{
public:
	// constrcuter destructer
	ContentsGUI();
	~ContentsGUI();

	// delete Function
	ContentsGUI(const ContentsGUI& _Other) = delete;
	ContentsGUI(ContentsGUI&& _Other) noexcept = delete;
	ContentsGUI& operator=(const ContentsGUI& _Other) = delete;
	ContentsGUI& operator=(ContentsGUI&& _Other) noexcept = delete;

protected:
	virtual void Init();
	virtual void OnGui(class Scene* Level, float _Delta);

private:
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);;
	bool show_demo_window = true;
	bool show_another_window = false;

};

