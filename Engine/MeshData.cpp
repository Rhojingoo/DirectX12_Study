#include "pch.h"
#include "MeshData.h"
//#include "FBXLoader.h"
#include "Mesh.h"
#include "Material.h"
#include "Resources.h"
#include "Transform.h"
#include "MeshRenderer.h"
#include "Animator.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
namespace fs = std::filesystem;


MeshData::MeshData() : Object(OBJECT_TYPE::MESH_DATA)
{
}

MeshData::~MeshData()
{
}

shared_ptr<MeshData> MeshData::LoadFromFBX(const wstring& path)
{
	//FBXLoader loader;
	loader.LoadFbx(path);

	shared_ptr<MeshData> meshData = make_shared<MeshData>();

	for (int32 i = 0; i < loader.GetMeshCount(); i++)
	{
		shared_ptr<Mesh> mesh = Mesh::CreateFromFBX(&loader.GetMesh(i), loader);

		GET_SINGLE(Resources)->Add<Mesh>(mesh->GetName(), mesh);

		// Material 찾아서 연동
		vector<shared_ptr<Material>> materials;
		for (size_t j = 0; j < loader.GetMesh(i).materials.size(); j++)
		{
			shared_ptr<Material> material = GET_SINGLE(Resources)->Get<Material>(loader.GetMesh(i).materials[j].name);
			materials.push_back(material);
		}

		MeshRenderInfo info = {};
		info.mesh = mesh;
		info.materials = materials;
		meshData->_meshRenders.push_back(info);
	}

	return meshData;
}

void MeshData::Load(const wstring& _strFilePath)
{
	// TODO
}

bool MeshData::Load_Meshdata(const wstring& _strFilePath)
{
	//std::wifstream inFile(_strFilePath);
	//if (!inFile.is_open()) {
	//	std::wcerr << L"Failed to open file for reading: " << _strFilePath << std::endl;
	//	return false; // 파일 열기 실패
	//}

	//std::wstring line;
	//while (std::getline(inFile, line))
	//{
	//	if (line == L"---") {
	//		continue; // 새로운 메시 렌더 정보 시작
	//	}

	//	// 메시 이름 읽기
	//	std::wstring meshName = line;

	//	// 재질 이름들 읽기
	//	std::vector<std::shared_ptr<Material>> materials;
	//	while (std::getline(inFile, line) && line != L"---") {
	//		std::shared_ptr<Material> material = GET_SINGLE(Resources)->Get<Material>(line);
	//		materials.push_back(material);
	//	}

	//	// 메시 렌더 정보 생성
	//	shared_ptr<Mesh> mesh = GET_SINGLE(Resources)->Get<Mesh>(meshName);
	//	MeshRenderInfo info = { mesh, materials };
	//	_meshRenders.push_back(info);
	//}

	//inFile.close();
	//return true; // 성공적으로 로드
}

void MeshData::Save(const wstring& _strFilePath)
{
	// TODO
	//std::wofstream outFile(_strFilePath);
	//if (!outFile.is_open()) {
	//	std::wcerr << L"Failed to open file for writing: " << _strFilePath << std::endl;
	//	return;
	//}

	//// Set precision for writing floating point values to file
	//outFile << std::fixed << std::setprecision(6);

	//for (const auto& renderInfo : _meshRenders) {
	//	// Write mesh name
	//	outFile << L"MeshName: " << renderInfo.mesh->GetName() << std::endl;

	//	// Write vertices
	//	outFile << L"Vertices:\n";
	//	const auto& vertices = renderInfo.mesh->GetVertices();
	//	for (const auto& vertex : vertices) {
	//		outFile << vertex.x << L" " << vertex.y << L" " << vertex.z << std::endl;
	//	}

	//	// Write normals
	//	outFile << L"Normals:\n";
	//	const auto& normals = renderInfo.mesh->GetNormals();
	//	for (const auto& normal : normals) {
	//		outFile << normal.x << L" " << normal.y << L" " << normal.z << std::endl;
	//	}

	//	// Write UV coordinates
	//	outFile << L"UVs:\n";
	//	const auto& uvs = renderInfo.mesh->GetUVs();
	//	for (const auto& uv : uvs) {
	//		outFile << uv.u << L" " << uv.v << std::endl;
	//	}

	//	// Write materials
	//	outFile << L"Materials:\n";
	//	for (const auto& material : renderInfo.materials) {
	//		outFile << material->GetName() << std::endl;
	//	}

	//	outFile << L"---\n"; // Section delimiter
	//}

	//outFile.close();
}

vector<shared_ptr<GameObject>> MeshData::Instantiate()
{
	vector<shared_ptr<GameObject>> v;

	for (MeshRenderInfo& info : _meshRenders)
	{
		shared_ptr<GameObject> gameObject = make_shared<GameObject>();
		gameObject->AddComponent(make_shared<Transform>());
		gameObject->AddComponent(make_shared<MeshRenderer>());
		gameObject->GetMeshRenderer()->SetMesh(info.mesh);

		for (uint32 i = 0; i < info.materials.size(); i++)
			gameObject->GetMeshRenderer()->SetMaterial(info.materials[i], i);

		if (info.mesh->IsAnimMesh())
		{
			shared_ptr<Animator> animator = make_shared<Animator>();
			gameObject->AddComponent(animator);
			animator->SetBones(info.mesh->GetBones());
			animator->SetAnimClip(info.mesh->GetAnimClip());
		}

		v.push_back(gameObject);
	}


	return v;
}

