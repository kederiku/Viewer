#ifndef __FBXLOADER_H__
#define __FBXLOADER_H__

#include <fbxsdk.h>

class FBX_Loader
{
	private:
		KFbxScene*	__scene;
		KFbxSdkManager*	__manager;

		KFbxNode*	__lLightNode;
		KFbxLight*	__lLight;
	public:
				FBX_Loader();
		KFbxScene*	Load(const char* filename);
		KFbxScene*	GetScene();
		KFbxNode*	Get_NodeLight();
		KFbxLight*	Get_Light();
		KFbxSdkManager*	GetManager();
};


#endif
