#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "mesh.h"
#include "node.h"
#include "func_event.h"
#include <GL/glew.h>


class Window
{
protected:
	Node	__tree;

public:
		Window();
	void	InitGL(int argc, char** argv);
	bool	MakeChild(Node* node, KFbxNode* pnode);
	bool	InitTree(Node* node, KFbxNode* pnode);
	bool	InitBuffer(KFbxNode* node);
	void	DrawMesh();
};

#endif
