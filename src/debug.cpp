#include "debug.h"
#include <iostream>

int	numTabs = 0;
void
PrintTabs()
{
	for (int i = 0; i < numTabs; i++)
		printf("\t");

}

void
PrintNode(KFbxNode* pNode)
{
	PrintTabs();
	const char*	nodeName = pNode->GetName();
	fbxDouble3 translation = pNode->LclTranslation.Get();
	fbxDouble3 rotation = pNode->LclRotation.Get();
	fbxDouble3 scaling = pNode->LclScaling.Get();

	std::cout << "-------- NODE -------" << std::endl;
	std::cout << "NAME: " << nodeName << std::endl;
	std::cout << "Translation: " << translation[0] << ", " << translation[1] << ", " << translation[2] << std::endl;
	std::cout << "Rotation: " << rotation[0] << ", " << rotation[1] << ", " << rotation[2] << std::endl;
	std::cout << "Scaling: " << scaling[0] << ", " << scaling[1] << ", " << scaling[2] << std::endl;
	numTabs++;
	for(int j = 0; j < pNode->GetChildCount(); j++)
		PrintNode(pNode->GetChild(j));
	numTabs--;
	PrintTabs();
}
