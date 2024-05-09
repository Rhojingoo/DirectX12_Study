#pragma once
#include "Object.h"
#include "FBXLoader.h"


class Mesh;
class Material;
class GameObject;

struct MeshRenderInfo
{
	shared_ptr<Mesh>				mesh;
	vector<shared_ptr<Material>>	materials;
};

class MeshData : public Object
{
public:
	MeshData();
	virtual ~MeshData();

public:
	static shared_ptr<MeshData> LoadFromFBX(const wstring& path);

	void Load(const wstring& _strFilePath)override;
	bool Load_Meshdata(const wstring& _strFilePath) override;
	void Save(const wstring& _strFilePath) override;

	vector<shared_ptr<GameObject>> Instantiate();
	static FBXLoader loader;
private:
	shared_ptr<Mesh>				_mesh;
	vector<shared_ptr<Material>>	_materials;

	vector<MeshRenderInfo> _meshRenders;
	
};
