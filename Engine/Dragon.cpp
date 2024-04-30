#include "pch.h"
#include "Dragon.h"
#include "Transform.h"
#include "MeshRenderer.h"
#include "Camera.h"
#include "Light.h"
#include "MonoBehaviour.h"
#include "ParticleSystem.h"
#include "BaseCollider.h"
#include "Animator.h"

#include "Engine.h"
#include "Material.h"

#include "SceneManager.h"
#include "Resources.h"
#include "ParticleSystem.h"
#include "SphereCollider.h"
#include "MeshData.h"
#include "TestDragon.h"
#include "EngineEditorGUI.h"



Dragon::Dragon()
{
}

Dragon::~Dragon()
{
}

void Dragon::Awake()
{
}

void Dragon::Start()
{
//#pragma region FBX
//	{
//		shared_ptr<MeshData> meshData = GET_SINGLE(Resources)->LoadFBX(L"..\\Resources\\FBX\\Dragon.fbx");
//
//		vector<shared_ptr<GameObject>> gameObjects = meshData->Instantiate();
//
//		for (auto& gameObject : gameObjects)
//		{
//			gameObject->SetName(L"Dragon");
//			gameObject->SetCheckFrustum(false);
//			gameObject->GetTransform()->SetLocalPosition(Vec3(0.f, 0.f, 300.f));
//			gameObject->GetTransform()->SetLocalScale(Vec3(1.f, 1.f, 1.f));
//			GET_SINGLE(SceneManager)->GetActiveScene()->AddGameObject();
//			gameObject->AddComponent(make_shared<TestDragon>());
//		}
//	}
//#pragma endregion
}

void Dragon::Update()
{
}

void Dragon::LateUpdate()
{
}

void Dragon::FinalUpdate()
{
}

