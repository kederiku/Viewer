#ifndef __BATCH_H__
#define __BATCH_H__

#include <GLTools.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <fbxsdk.h>
#include "node.h"


class Batch : public Node
{
private:
	GLuint				__tab[3];
	KFbxLayerElementNormal*		normals;
	int				__nb_vertex;
private:

public:
		Batch();
	void	Init(KFbxNode* node);
	void	Init_index(KFbxMesh* mesh);
	void	Draw();
};

#endif


