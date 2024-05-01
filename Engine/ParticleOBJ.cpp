#include "pch.h"
#include "ParticleOBJ.h"
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
#include "ParticleSystem.h"


ParticleOBJ::ParticleOBJ()
{
}

ParticleOBJ::~ParticleOBJ()
{
}

void ParticleOBJ::Awake()
{
	GameObject::Awake();
	//AddComponent(make_shared<Transform>());
	//AddComponent(make_shared<ParticleSystem>());
	//SetCheckFrustum(false);
	//GetTransform()->SetLocalPosition(Vec3(0.f, 0.f, 100.f));
}

void ParticleOBJ::Start()
{
	GameObject::Start();
}

void ParticleOBJ::Update()
{
	GameObject::Update();
}

void ParticleOBJ::LateUpdate()
{
	GameObject::LateUpdate();
}

void ParticleOBJ::FinalUpdate()
{
	GameObject::FinalUpdate();
}

