#include "pch.h"
#include "TestDragon.h"
#include "Input.h"
#include "Animator.h"
#include "ParticleOBJ.h"
#include "ParticleSystem.h"
#include "Transform.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GameObject.h"


bool TestDragon::ChangeAniMation = false;
int32 TestDragon::Animation_Indext = 0;

void TestDragon::Update()
{
	if (ChangeAniMation == true)
	{
		GetAnimator()->Play(Animation_Indext);
		ChangeAniMation = false;
	}



	if (INPUT->GetButtonDown(KEY_TYPE::KEY_1))
	{
		int32 count = GetAnimator()->GetAnimCount();
		int32 currentIndex = GetAnimator()->GetCurrentClipIndex();

		int32 index = (currentIndex + 1) % count;
		GetAnimator()->Play(index);
	}

	if (INPUT->GetButtonDown(KEY_TYPE::KEY_2))
	{
		int32 count = GetAnimator()->GetAnimCount();
		int32 currentIndex = GetAnimator()->GetCurrentClipIndex();

		int32 index = (currentIndex - 1 + count) % count;
		GetAnimator()->Play(index);
	}
}

void TestDragon::Init()
{
}

void TestDragon::OnGui(Scene* Level, float _Delta)
{
	if (true == ImGui::Button("No1.Animation"))
	{
		Animation_Indext = 0;
		ChangeAniMation = true;
	}

	if (true == ImGui::Button("No2.Animation"))
	{
		Animation_Indext = 1;
		ChangeAniMation = true;
	}
	if (true == ImGui::Button("No3.Animation"))
	{
		Animation_Indext = 2;
		ChangeAniMation = true;
	}
	if (true == ImGui::Button("No4.Animation"))
	{
		Animation_Indext = 3;
		ChangeAniMation = true;
	}

	if (true == ImGui::Button("Particl_Create"))
	{
		particle = make_shared<ParticleOBJ>();
		particle->AddComponent(make_shared<Transform>());
		particle->AddComponent(make_shared<ParticleSystem>());
		particle->SetCheckFrustum(false);
		particle->GetTransform()->SetLocalPosition(Vec3(0.f, 0.f, 100.f));
		GET_SINGLE(SceneManager)->GetActiveScene()->AddGameObject(particle);
	}

	if (true == ImGui::Button("Particl_Destroy"))
	{
		GET_SINGLE(SceneManager)->GetActiveScene()->RemoveGameObject(particle);
		//GEngine->ChangeLevel("TestLevel");
	}
}
