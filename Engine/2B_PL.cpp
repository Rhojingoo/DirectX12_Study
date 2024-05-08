#include "pch.h"
#include "2B_PL.h"
#include "TestDragon.h"

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

_2B_Player::_2B_Player()
{
}

_2B_Player::~_2B_Player()
{
}

void _2B_Player::Awake()
{
	shared_ptr<MeshData> meshData = GET_SINGLE(Resources)->LoadFBX(L"..\\Resources\\FBX\\2B_Idle.fbx");
	vector<shared_ptr<GameObject>> gameObjects = meshData->Instantiate();
	for (auto& gameObject : gameObjects)
	{
		gameObject->SetName(L"Dragon");
		gameObject->SetCheckFrustum(false);
		gameObject->GetTransform()->SetLocalPosition(Vec3(0.f, 150.f, 300.f));
		gameObject->GetTransform()->SetLocalScale(Vec3(30.f, 30.f, 30.f));
		GET_SINGLE(SceneManager)->GetActiveScene()->AddGameObject(gameObject);
		gameObject->AddComponent(make_shared<TestDragon>());
		gameObject->SetStatic(false);
	}
	//UEngineEditorGUI::CreateEditorWindow<TestDragon>("Dragon_Animation");
}

void _2B_Player::Start()
{
	GameObject::Start();
}

void _2B_Player::Update()
{
	GameObject::Update();
}

void _2B_Player::LateUpdate()
{
	GameObject::LateUpdate();
}

void _2B_Player::FinalUpdate()
{
	GameObject::FinalUpdate();
}

