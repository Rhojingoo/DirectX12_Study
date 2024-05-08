#pragma once
#include "Scene.h"

class TestScene : public Scene
{
public:
	TestScene();
	~TestScene();

	void Awake()override;
	void Start()override;
	void Update()override;
	void LateUpdate()override;
	void FinalUpdate()override;

	void Render()override;
	void ClearRTV()override;
	void RenderShadow()override;
	void RenderDeferred()override;
	void RenderLights()override;
	void RenderFinal()override;

protected:

private:
};


