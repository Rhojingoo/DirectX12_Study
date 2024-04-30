#pragma once
#include "GameObject.h"

class Direction_Light : public GameObject
{
public:
	Direction_Light();
	~Direction_Light();

	void Awake()override;
	void Start()override;
	void Update()override;
	void LateUpdate()override;
	void FinalUpdate()override;

private:

};



