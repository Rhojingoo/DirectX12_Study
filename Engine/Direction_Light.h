#pragma once
#include "GameObject.h"
#include "EngineEditorWindow.h"

class Direction_Light : public GameObject,  public UEngineEditorWindow
{
public:
	Direction_Light();
	~Direction_Light();

	void Awake()override;
	void Start()override;
	void Update()override;
	void LateUpdate()override;
	void FinalUpdate()override;

	virtual void Init() {}
	virtual void OnGui(Scene* _scene, float _Delta);
private:
	static Vec3 DirectionLight; 
	static Vec3 Diffuse; 
	static Vec3 Ambient; 
	static Vec3 Specular; 
};



