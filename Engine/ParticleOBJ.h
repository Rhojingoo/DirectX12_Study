#pragma once
#include "GameObject.h"

class ParticleOBJ : public GameObject
{
public:
	ParticleOBJ();
	~ParticleOBJ();

	void Awake()override;
	void Start()override;
	void Update()override;
	void LateUpdate()override;
	void FinalUpdate()override;


protected:

private:
};



