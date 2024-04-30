#include "pch.h"
#include "Direction_Light.h"

#include "Engine.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Resources.h"
#include "Transform.h"

#include "Material.h"
#include "MeshRenderer.h"
#include "MonoBehaviour.h"
#include "BaseCollider.h"
#include "Animator.h"
#include "MeshData.h"
#include "EngineEditorGUI.h"


Direction_Light::Direction_Light()
{
}

Direction_Light::~Direction_Light()
{
}

void Direction_Light::Awake()
{
	AddComponent(make_shared<Transform>());
	GetTransform()->SetLocalPosition(Vec3(0, 1000, 500));
	AddComponent(make_shared<Light>());
	GetLight()->SetLightDirection(Vec3(0, -1, 1.f));
	GetLight()->SetLightType(LIGHT_TYPE::DIRECTIONAL_LIGHT);
	GetLight()->SetDiffuse(Vec3(1.f, 1.f, 1.f));
	GetLight()->SetAmbient(Vec3(0.1f, 0.1f, 0.1f));
	GetLight()->SetSpecular(Vec3(0.1f, 0.1f, 0.1f));
}

void Direction_Light::Start()
{
}

void Direction_Light::Update()
{
}

void Direction_Light::LateUpdate()
{
}

void Direction_Light::FinalUpdate()
{
}
