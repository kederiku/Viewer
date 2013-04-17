#ifndef __MESH_H__
#define __MESH_H_

#include <fbxsdk.h>
#include <GLTools.h>
#include <GL/glut.h>
#include <vector>
#include "node.h"


class Mesh : public Node
{
private:
	int			__nb_indice;
	GLuint			__tab[3];
	bool			__is_normal;
public:
				Mesh();
				~Mesh();
	bool			InitNode(KFbxNode* node);
	bool			InitArray(KFbxMesh* mesh);
	bool			InitIndice(KFbxMesh* mesh);
	bool			InitNormal(KFbxMesh* mesh);
	std::vector<int>	ResizeIndice(KFbxMesh* mesh, int*);
	void			Draw();
};

#endif
