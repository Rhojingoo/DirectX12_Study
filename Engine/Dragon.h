#pragma once
#include "GameObject.h"

class Dragon : public GameObject
{
public:
	Dragon();
	~Dragon();

	void Awake()override;
	void Start()override;
	void Update()override;
	void LateUpdate()override;
	void FinalUpdate()override;
protected:

private:


};

