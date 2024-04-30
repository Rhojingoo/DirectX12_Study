#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TestPlay_Scene.h"


#include "Timer.h"
#include "Engine.h"
#include "Camera.h"
#include "Light.h"
#include "EngineEditorGUI.h"
#include "MeshData.h"
#include "BaseCollider.h"



void SceneManager::Init()
{
	TestPlay = make_shared<TestPlay_Scene>();


	GET_SINGLE(SceneManager)->LoadScene(TestPlay);
}

void SceneManager::Update()
{
	if (_activeScene == nullptr)
		return;

	_activeScene->Update();
	_activeScene->LateUpdate();
	_activeScene->FinalUpdate();
}

// TEMP
void SceneManager::Render()
{
	if (_activeScene)
	{
		_activeScene->Render();
		UEngineEditorGUI::GUIRender(_activeScene.get(), GET_SINGLE(Timer)->GetDeltaTime());
		UEngineEditorGUI::GUIRender(_activeScene.get(), GET_SINGLE(Timer)->GetDeltaTime());	
	}
}

void SceneManager::LoadScene(shared_ptr<Scene> _sceneName)
{
	_activeScene = _sceneName;
	_activeScene->Awake();
	_activeScene->Start();
}


shared_ptr<GameObject> SceneManager::Pick(int32 screenX, int32 screenY)
{
	shared_ptr<Camera> camera = GetActiveScene()->GetMainCamera();

	float width = static_cast<float>(GEngine->GetWindow().width);
	float height = static_cast<float>(GEngine->GetWindow().height);

	Matrix projectionMatrix = camera->GetProjectionMatrix();

	// ViewSpace에서 Picking 진행
	float viewX = (+2.0f * screenX / width - 1.0f) / projectionMatrix(0, 0);
	float viewY = (-2.0f * screenY / height + 1.0f) / projectionMatrix(1, 1);

	Matrix viewMatrix = camera->GetViewMatrix();
	Matrix viewMatrixInv = viewMatrix.Invert();

	auto& gameObjects = GET_SINGLE(SceneManager)->GetActiveScene()->GetGameObjects();

	float minDistance = FLT_MAX;
	shared_ptr<GameObject> picked;

	for (auto& gameObject : gameObjects)
	{
		if (gameObject->GetCollider() == nullptr)
			continue;

		// ViewSpace에서의 Ray 정의
		Vec4 rayOrigin = Vec4(0.0f, 0.0f, 0.0f, 1.0f);
		Vec4 rayDir = Vec4(viewX, viewY, 1.0f, 0.0f);

		// WorldSpace에서의 Ray 정의
		rayOrigin = XMVector3TransformCoord(rayOrigin, viewMatrixInv);
		rayDir = XMVector3TransformNormal(rayDir, viewMatrixInv);
		rayDir.Normalize();

		// WorldSpace에서 연산
		float distance = 0.f;
		if (gameObject->GetCollider()->Intersects(rayOrigin, rayDir, OUT distance) == false)
			continue;

		if (distance < minDistance)
		{
			minDistance = distance;
			picked = gameObject;
		}
	}

	return picked;
}



