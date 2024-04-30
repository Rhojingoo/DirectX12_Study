#include "pch.h"
#include "SkyBox.h"

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



SkyBox::SkyBox()
{
}

SkyBox::~SkyBox()
{
}

void SkyBox::Awake()
{
	AddComponent(make_shared<Transform>());
	SetCheckFrustum(false);
	shared_ptr<MeshRenderer> meshRenderer = make_shared<MeshRenderer>();
	shared_ptr<Mesh> sphereMesh = GET_SINGLE(Resources)->LoadSphereMesh();
	meshRenderer->SetMesh(sphereMesh);

	shared_ptr<Shader> shader = GET_SINGLE(Resources)->Get<Shader>(L"Skybox");
	shared_ptr<Texture> texture = GET_SINGLE(Resources)->Load<Texture>(L"Sky01", L"..\\Resources\\Texture\\Sky03.jpg");
	shared_ptr<Material> material = make_shared<Material>();
	material->SetShader(shader);
	material->SetTexture(0, texture);
	meshRenderer->SetMaterial(material);
	AddComponent(meshRenderer);	
}

void SkyBox::Start()
{
}

void SkyBox::Update()
{
}

void SkyBox::LateUpdate()
{
}

void SkyBox::FinalUpdate()
{
}
