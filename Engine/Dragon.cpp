#include "pch.h"
#include "Dragon.h"
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





Dragon::Dragon()
{
}

Dragon::~Dragon()
{
}

void Dragon::Awake()
{
	//shared_ptr<MeshData> meshData = GET_SINGLE(Resources)->LoadFBX(L"..\\Resources\\FBX\\2B_Idle.fbx");
	shared_ptr<MeshData> meshData = GET_SINGLE(Resources)->LoadFBX(L"..\\Resources\\FBX\\Dragon.fbx");
	vector<shared_ptr<GameObject>> gameObjects = meshData->Instantiate();
	for (auto& gameObject : gameObjects)
	{
		gameObject->SetName(L"Dragon");
		gameObject->SetCheckFrustum(false);
		gameObject->GetTransform()->SetLocalPosition(Vec3(0.f, 150.f, 300.f));
		gameObject->GetTransform()->SetLocalScale(Vec3(1.f, 1.f, 1.f));
		GET_SINGLE(SceneManager)->GetActiveScene()->AddGameObject(gameObject);
		gameObject->AddComponent(make_shared<TestDragon>());
		gameObject->SetStatic(false);
	}
	UEngineEditorGUI::CreateEditorWindow<TestDragon>("Dragon_Animation");
}

void Dragon::Start()
{
	GameObject::Start();
}

void Dragon::Update()
{
	GameObject::Update();
}

void Dragon::LateUpdate()
{
	GameObject::LateUpdate();
}

void Dragon::FinalUpdate()
{
	GameObject::FinalUpdate();
}

