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


Vec3 Direction_Light::DirectionLight = Vec3(0, -1, 1.f);
Vec3 Direction_Light::Diffuse = Vec3(1.f, 1.f, 1.f);
Vec3 Direction_Light::Ambient = Vec3(0.1f, 0.1f, 0.1f);
Vec3 Direction_Light::Specular = Vec3(0.1f, 0.1f, 0.1f);

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
	GetLight()->SetLightDirection(DirectionLight);
	GetLight()->SetLightType(LIGHT_TYPE::DIRECTIONAL_LIGHT);
	GetLight()->SetDiffuse(Diffuse);
	GetLight()->SetAmbient(Ambient);
	GetLight()->SetSpecular(Specular);
	UEngineEditorGUI::CreateEditorWindow<Direction_Light>("Direction_Light_Setter");
}

void Direction_Light::Start()
{
}

void Direction_Light::Update()
{
}

void Direction_Light::LateUpdate()
{
	GetLight()->SetLightDirection(DirectionLight);
	GetLight()->SetDiffuse(Diffuse);
	GetLight()->SetAmbient(Ambient);
	GetLight()->SetSpecular(Specular);
}

void Direction_Light::FinalUpdate()
{
}


void Direction_Light::OnGui(Scene* _scene, float _Delta)
{

	ImGui::SliderFloat("DirectionLightX", &DirectionLight.x, 0.0f, 1.0f);
	ImGui::SliderFloat("DirectionLightY", &DirectionLight.y, 0.0f, 1.0f);
	ImGui::SliderFloat("DirectionLightZ", &DirectionLight.z, 0.0f, 1.0f);


	ImGui::SliderFloat("DiffuseX", &Diffuse.x, 0.0f, 1.0f);
	ImGui::SliderFloat("DiffuseY", &Diffuse.y, 0.0f, 1.0f);
	ImGui::SliderFloat("DiffuseZ", &Diffuse.z, 0.0f, 1.0f);


	ImGui::SliderFloat("AmbientX", &Ambient.x, 0.0f, 1.0f);
	ImGui::SliderFloat("AmbientY", &Ambient.y, 0.0f, 1.0f);
	ImGui::SliderFloat("AmbientZ", &Ambient.z, 0.0f, 1.0f);



	ImGui::SliderFloat("SpecularX", &Specular.x, 0.0f, 1.0f);
	ImGui::SliderFloat("SpecularY", &Specular.y, 0.0f, 1.0f);
	ImGui::SliderFloat("SpecularZ", &Specular.z, 0.0f, 1.0f);

	


	if (true == ImGui::Button("No"))
	{
		//Animation_Indext = 0;
		//ChangeAniMation = true;
	}

}
