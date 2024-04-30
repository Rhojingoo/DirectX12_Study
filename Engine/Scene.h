#pragma once
#include "GameObject.h"
#include "Camera.h"
#include "Light.h"

enum
{
	MAX_LAYER = 32
};

class Scene
{
public:
	virtual void Awake();
	virtual void Start();
	virtual void Update();
	virtual void LateUpdate();
	virtual void FinalUpdate();

	shared_ptr<Camera> GetMainCamera();

	virtual void Render();
	virtual void ClearRTV();
	virtual void RenderShadow();
	virtual void RenderDeferred();
	virtual void RenderLights();
	virtual void RenderFinal();

	virtual void RenderForward();

private:
	virtual void PushLightData();

public:
	void AddGameObject(shared_ptr<GameObject> gameObject);
	void RemoveGameObject(shared_ptr<GameObject> gameObject);

	const vector<shared_ptr<GameObject>>& GetGameObjects() { return _gameObjects; }

	void SetLayerName(uint8 index, const wstring& name);
	const wstring& IndexToLayerName(uint8 index) { return _layerNames[index]; }
	uint8 LayerNameToIndex(const wstring& name);

private:
	vector<shared_ptr<GameObject>>		_gameObjects;
	vector<shared_ptr<Camera>>			_cameras;
	vector<shared_ptr< Light>>			_lights;

	array<wstring, MAX_LAYER> _layerNames;
	map<wstring, uint8> _layerIndex;
};

