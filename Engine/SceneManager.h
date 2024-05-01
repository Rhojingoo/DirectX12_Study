#pragma once

class Scene;
class TestPlay_Scene;
class SceneManager
{
	DECLARE_SINGLE(SceneManager);

public:
	void Init();
	void Update();
	void Render();
	void LoadScene(shared_ptr<Scene> _sceneName);


	shared_ptr<class GameObject> Pick(int32 screenX, int32 screenY);

public:
	shared_ptr<Scene> GetActiveScene() { return _activeScene; }

private:
	static shared_ptr<Scene> _activeScene;
	shared_ptr<TestPlay_Scene> TestPlay;



};

