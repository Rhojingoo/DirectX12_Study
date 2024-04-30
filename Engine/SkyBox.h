#pragma once
#include "GameObject.h"

class SkyBox : public GameObject
{
public:
	SkyBox();
	~SkyBox();

	void Awake()override;
	void Start()override;
	void Update()override;
	void LateUpdate()override;
	void FinalUpdate()override;


protected:

private:
};



