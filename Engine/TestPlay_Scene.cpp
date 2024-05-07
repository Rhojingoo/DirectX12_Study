#include "pch.h"
#include "TestPlay_Scene.h"
#include "Engine.h"
#include "Shader.h"
#include "MeshData.h"

#include "ConstantBuffer.h"
#include "Light.h"
#include "Resources.h"
#include "Material.h"
#include "GameObject.h"
#include "MeshRenderer.h"
#include "Transform.h"
#include "ParticleSystem.h"
#include "Terrain.h"
#include "SphereCollider.h"

#include "ParticleOBJ.h"
#include "TestDragon.h"
#include "Dragon.h"
#include "SkyBox.h"
#include "Direction_Light.h"
#include "TestCameraScript.h"
#include "EngineEditorGUI.h"
#include "ContentsGUI.h"


TestPlay_Scene::TestPlay_Scene()
{
}

TestPlay_Scene::~TestPlay_Scene()
{
}

void TestPlay_Scene::Awake()
{
	UEngineEditorGUI::CreateEditorWindow<ContentsGUI>("Contents");
	//UEngineEditorGUI::CreateEditorWindow<MapEditorGUI>("MapEditor");

	Scene::Awake();

#pragma region LayerMask
	SetLayerName(0, L"Default");
	SetLayerName(1, L"UI");
#pragma endregion

#pragma region ComputeShader
	{
		shared_ptr<Shader> shader = GET_SINGLE(Resources)->Get<Shader>(L"ComputeShader");

		// UAV �� Texture ����
		shared_ptr<Texture> texture = GET_SINGLE(Resources)->CreateTexture(L"UAVTexture",
			DXGI_FORMAT_R8G8B8A8_UNORM, 1024, 1024,
			CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT), D3D12_HEAP_FLAG_NONE,
			D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);

		shared_ptr<Material> material = GET_SINGLE(Resources)->Get<Material>(L"ComputeShader");
		material->SetShader(shader);
		material->SetInt(0, 1);
		GEngine->GetComputeDescHeap()->SetUAV(texture->GetUAVHandle(), UAV_REGISTER::u0);

		// ������ �׷� (1 * 1024 * 1)
		material->Dispatch(1024, 1024, 1);
	}
#pragma endregion



#pragma region Camera
	{
		shared_ptr<GameObject> camera = make_shared<GameObject>();
		camera->SetName(L"Main_Camera");
		camera->AddComponent(make_shared<Transform>());
		camera->AddComponent(make_shared<Camera>()); // Near=1, Far=1000, FOV=45��
		camera->AddComponent(make_shared<TestCameraScript>());
		camera->GetCamera()->SetFar(10000.f);
		camera->GetTransform()->SetLocalPosition(Vec3(0.f, 150.f, 0.f));
		uint8 layerIndex = LayerNameToIndex(L"UI");
		camera->GetCamera()->SetCullingMaskLayerOnOff(layerIndex, true); // UI�� �� ����
		AddGameObject(camera);
	}
#pragma endregion

#pragma region UI_Camera
	{
		shared_ptr<GameObject> camera = make_shared<GameObject>();
		camera->AddComponent(make_shared<Transform>());
		camera->AddComponent(make_shared<Camera>()); // Near=1, Far=1000, 800*600
		camera->GetTransform()->SetLocalPosition(Vec3(0.f, 0.f, 0.f));
		camera->GetCamera()->SetProjectionType(PROJECTION_TYPE::ORTHOGRAPHIC);
		uint8 layerIndex =LayerNameToIndex(L"UI");
		camera->GetCamera()->SetCullingMaskAll(); // �� ����
		camera->GetCamera()->SetCullingMaskLayerOnOff(layerIndex, false); // UI�� ����
		AddGameObject(camera);
	}
#pragma endregion


#pragma region SkyBox
	{		
		shared_ptr<SkyBox> skybox = make_shared<SkyBox>();
		AddGameObject(skybox);
	}
#pragma endregion



#pragma region Object
	{
		//shared_ptr<GameObject> obj = make_shared<GameObject>();
		//obj->SetName(L"OBJ");
		//obj->AddComponent(make_shared<Transform>());
		//obj->AddComponent(make_shared<SphereCollider>());
		//obj->GetTransform()->SetLocalScale(Vec3(100.f, 100.f, 100.f));
		//obj->GetTransform()->SetLocalPosition(Vec3(0, 150.f, 500.f));
		//obj->SetStatic(false);
		//shared_ptr<MeshRenderer> meshRenderer = make_shared<MeshRenderer>();
		//{
		//	shared_ptr<Mesh> sphereMesh = GET_SINGLE(Resources)->LoadSphereMesh();
		//	meshRenderer->SetMesh(sphereMesh);
		//}
		//{
		//	shared_ptr<Material> material = GET_SINGLE(Resources)->Get<Material>(L"GameObject_Hole");
		//	meshRenderer->SetMaterial(material->Clone());
		//}
		//dynamic_pointer_cast<SphereCollider>(obj->GetCollider())->SetRadius(0.5f);
		//dynamic_pointer_cast<SphereCollider>(obj->GetCollider())->SetCenter(Vec3(0.f, 0.f, 0.f));
		//obj->AddComponent(meshRenderer);
		//AddGameObject(obj);
	}
#pragma endregion




#pragma region Object
	{
		//shared_ptr<GameObject> obj = make_shared<GameObject>();
		//obj->SetName(L"OBJ");
		//obj->AddComponent(make_shared<Transform>());
		//obj->AddComponent(make_shared<SphereCollider>());
		//obj->GetTransform()->SetLocalScale(Vec3(100.f, 100.f, 100.f));
		//obj->GetTransform()->SetLocalPosition(Vec3(100.f, 150.f, 500.f));
		//obj->SetStatic(false);
		//shared_ptr<MeshRenderer> meshRenderer = make_shared<MeshRenderer>();
		//{
		//	shared_ptr<Mesh> QUBEMesh = GET_SINGLE(Resources)->LoadCubeMesh();
		//	meshRenderer->SetMesh(QUBEMesh);
		//}
		//{
		//	shared_ptr<Material> material = GET_SINGLE(Resources)->Get<Material>(L"GameObject_Substance");
		//	meshRenderer->SetMaterial(material->Clone());
		//}
		//dynamic_pointer_cast<SphereCollider>(obj->GetCollider())->SetRadius(0.5f);
		//dynamic_pointer_cast<SphereCollider>(obj->GetCollider())->SetCenter(Vec3(0.f, 0.f, 0.f));
		//obj->AddComponent(meshRenderer);
		//AddGameObject(obj);
	}
#pragma endregion



#pragma region Object_instancing
	//for (int32 i = 0; i < 50; i++)
	//{
	//	shared_ptr<GameObject> obj = make_shared<GameObject>();
	//	obj->AddComponent(make_shared<Transform>());
	//	obj->GetTransform()->SetLocalScale(Vec3(25.f, 25.f, 25.f));
	//	obj->GetTransform()->SetLocalPosition(Vec3(-300.f + i * 10.f, 200.f, 500.f));
	//	shared_ptr<MeshRenderer> meshRenderer = make_shared<MeshRenderer>();
	//	{
	//		shared_ptr<Mesh> sphereMesh = GET_SINGLE(Resources)->LoadSphereMesh();
	//		meshRenderer->SetMesh(sphereMesh);
	//	}
	//	{
	//		shared_ptr<Material> material = GET_SINGLE(Resources)->Get<Material>(L"GameObject_Wood");
	//		material->SetInt(0, 1);
	//		meshRenderer->SetMaterial(material);
	//	//material->SetInt(0, 0);
	//	//meshRenderer->SetMaterial(material->Clone());
	//	}
	//	obj->AddComponent(meshRenderer);
	//	AddGameObject(obj);
	//}
#pragma endregion


#pragma region Terrain
	/*{
		shared_ptr<GameObject> obj = make_shared<GameObject>();
		obj->AddComponent(make_shared<Transform>());
		obj->AddComponent(make_shared<Terrain>());
		obj->AddComponent(make_shared<MeshRenderer>());

		obj->GetTransform()->SetLocalScale(Vec3(50.f, 250.f, 50.f));
		obj->GetTransform()->SetLocalPosition(Vec3(-100.f, -200.f, 300.f));
		obj->SetStatic(true);
		obj->GetTerrain()->Init(64, 64);
		obj->SetCheckFrustum(false);

		scene->AddGameObject(obj);
	}*/
#pragma endregion



#pragma region Object
	{
		//shared_ptr<GameObject> obj = make_shared<GameObject>();
		//obj->AddComponent(make_shared<Transform>());
		//obj->GetTransform()->SetLocalScale(Vec3(100.f, 100.f, 100.f));
		//obj->GetTransform()->SetLocalPosition(Vec3(0, 150.f, 500.f));
		//obj->SetStatic(false);
		//shared_ptr<MeshRenderer> meshRenderer = make_shared<MeshRenderer>();
		//{
		//	shared_ptr<Mesh> sphereMesh = GET_SINGLE(Resources)->LoadSphereMesh();
		//	meshRenderer->SetMesh(sphereMesh);
		//}
		//{
		//	shared_ptr<Material> material = GET_SINGLE(Resources)->Get<Material>(L"GameObject_Wood");
		//	meshRenderer->SetMaterial(material->Clone());
		//}
		//obj->AddComponent(meshRenderer);
		//AddGameObject(obj);
	}
#pragma endregion

#pragma region FBX
	{
		shared_ptr<Dragon> BlackDragon = make_shared<Dragon>();
		BlackDragon->Awake();
	}
#pragma endregion	


#pragma region Plane
	{
		shared_ptr<GameObject> obj = make_shared<GameObject>();
		obj->AddComponent(make_shared<Transform>());
		obj->GetTransform()->SetLocalScale(Vec3(7000.f, 50.f, 7000.f));
		obj->GetTransform()->SetLocalPosition(Vec3(0.f, -250.f, 500.f));
		obj->SetStatic(true);
		shared_ptr<MeshRenderer> meshRenderer = make_shared<MeshRenderer>();
		{
			shared_ptr<Mesh> mesh = GET_SINGLE(Resources)->LoadCubeMesh();
			meshRenderer->SetMesh(mesh);
		}
		{
			shared_ptr<Material> material = GET_SINGLE(Resources)->Get<Material>(L"GameObject_Leather")->Clone();
			material->SetInt(0, 0);
			meshRenderer->SetMaterial(material);
		}
		obj->AddComponent(meshRenderer);
		AddGameObject(obj);
	}
#pragma endregion



#pragma region UI_Test
	for (int32 i = 0; i < 6; i++)
	{
		shared_ptr<GameObject> obj = make_shared<GameObject>();
		obj->SetLayerIndex(LayerNameToIndex(L"UI")); // UI
		obj->AddComponent(make_shared<Transform>());
		obj->GetTransform()->SetLocalScale(Vec3(100.f, 100.f, 100.f));
		obj->GetTransform()->SetLocalPosition(Vec3(-350.f + (i * 120), 250.f, 500.f));
		shared_ptr<MeshRenderer> meshRenderer = make_shared<MeshRenderer>();
		{
			shared_ptr<Mesh> mesh = GET_SINGLE(Resources)->LoadRectangleMesh();
			meshRenderer->SetMesh(mesh);
		}
		{
			shared_ptr<Shader> shader = GET_SINGLE(Resources)->Get<Shader>(L"Texture");

			shared_ptr<Texture> texture;
			if (i < 3)
				texture = GEngine->GetRTGroup(RENDER_TARGET_GROUP_TYPE::G_BUFFER)->GetRTTexture(i);
			else if (i < 5)
				texture = GEngine->GetRTGroup(RENDER_TARGET_GROUP_TYPE::LIGHTING)->GetRTTexture(i - 3);
			else
				texture = GEngine->GetRTGroup(RENDER_TARGET_GROUP_TYPE::SHADOW)->GetRTTexture(0);

			shared_ptr<Material> material = make_shared<Material>();
			material->SetShader(shader);
			material->SetTexture(0, texture);
			meshRenderer->SetMaterial(material);
		}
		obj->AddComponent(meshRenderer);
		AddGameObject(obj);
	}
#pragma endregion



#pragma region Directional Light
	{
		shared_ptr<Direction_Light> light = make_shared<Direction_Light>();
		light->AddComponent(make_shared<Transform>());
		light->GetTransform()->SetLocalPosition(Vec3(0, 1000, 500));
		light->AddComponent(make_shared<Light>());
		light->GetLight()->SetLightDirection(Vec3(0, -1, 0.f));
		light->GetLight()->SetLightType(LIGHT_TYPE::DIRECTIONAL_LIGHT);
		light->GetLight()->SetDiffuse(Vec3(1.f, 1.f, 1.f));
		light->GetLight()->SetAmbient(Vec3(0.1f, 0.1f, 0.1f));
		light->GetLight()->SetSpecular(Vec3(0.1f, 0.1f, 0.1f));
		AddGameObject(light);
	}
#pragma endregion
}

void TestPlay_Scene::Start()
{
	Scene::Start();
}

void TestPlay_Scene::Update()
{
	Scene::Update();
}

void TestPlay_Scene::LateUpdate()
{
	Scene::LateUpdate();
}

void TestPlay_Scene::FinalUpdate()
{
	Scene::FinalUpdate();
}

void TestPlay_Scene::Render()
{
	Scene::Render();
}

void TestPlay_Scene::ClearRTV()
{
	Scene::ClearRTV();
}

void TestPlay_Scene::RenderShadow()
{
	Scene::RenderShadow();
}

void TestPlay_Scene::RenderDeferred()
{
	Scene::RenderDeferred();
}

void TestPlay_Scene::RenderLights()
{
	Scene::RenderLights();
}

void TestPlay_Scene::RenderFinal()
{
	Scene::RenderFinal();
}
