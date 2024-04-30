#pragma once
#include "MonoBehaviour.h"
#include "EngineEditorWindow.h"

class TestDragon : public MonoBehaviour, public UEngineEditorWindow
{
public:
	virtual void Update() override;
	virtual void Init();
	virtual void OnGui(class Scene* Level, float _Delta);

	static int32 Animation_Indext;
	static bool ChangeAniMation;;

};

