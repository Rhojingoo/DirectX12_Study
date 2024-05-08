#pragma once
#include "GameObject.h"

class _2B_Player : public GameObject
{
public:
	_2B_Player();
	~_2B_Player();

	void Awake()override;
	void Start()override;
	void Update()override;
	void LateUpdate()override;
	void FinalUpdate()override;

protected:

private:


};

