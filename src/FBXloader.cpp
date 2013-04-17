#include "FBXloader.h"
#include <iostream>

FBX_Loader::FBX_Loader()
{
	this->__scene = NULL;
}

KFbxScene*
FBX_Loader::Load(const char* filename)
{
	KFbxScene*	tmp = NULL;
	this->__manager = KFbxSdkManager::Create();
	KFbxIOSettings*		ios = KFbxIOSettings::Create(this->__manager, IOSROOT);
	KFbxImporter*		import = KFbxImporter::Create(this->__manager, "");

	this->__manager->SetIOSettings(ios);
	if (!import->Initialize(filename, -1, this->__manager->GetIOSettings()))
	{
		std::cout << "Error: " << import->GetLastErrorString() << std::endl;
		return NULL;
	}
	tmp = KFbxScene::Create(this->__manager, "scene");
	this->__scene = tmp;

	import->Import(tmp);
	import->Destroy();

	return this->__scene;
}

KFbxScene*
FBX_Loader::GetScene(void)
{
	return this->__scene;
}

KFbxSdkManager*
FBX_Loader::GetManager()
{
	return this->__manager;
}

KFbxNode*
FBX_Loader::Get_NodeLight()
{
	return this->__lLightNode;
}

KFbxLight*
FBX_Loader::Get_Light()
{
	return this->__lLight;
}
