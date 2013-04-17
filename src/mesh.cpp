#include "mesh.h"
#include <iostream>

#include "debug.h"

Mesh::Mesh()
{
	this->__nb_indice = 0;
	this->__is_normal = false;
}

Mesh::~Mesh()
{
	if (this->__nb_indice != 0)
		glDeleteBuffers(3, this->__tab);
}

bool
Mesh::InitNode(KFbxNode* node)
{
	KFbxMesh*	mesh = node->GetMesh();

//	PrintNode(node);
	Node::InitNode(node);
//	std::cout << "Nb Polygon: " << mesh->GetPolygonCount() << std::endl;
	glGenBuffers(3, this->__tab);
	mesh->ComputeVertexNormals();
	if (this->InitArray(mesh) == false)
		return false;
	if (this->InitIndice(mesh) == false)
		return false;
	if (this->InitNormal(mesh) == false)
		return false;
	return true;
}

bool
Mesh::InitArray(KFbxMesh* mesh)
{
	KFbxVector4*	vector = mesh->GetControlPoints();

	glBindBuffer(GL_ARRAY_BUFFER, this->__tab[0]);
	glBufferData(GL_ARRAY_BUFFER, mesh->GetControlPointsCount() * sizeof(*vector), vector, GL_STATIC_DRAW);
	return true;
}

bool
Mesh::InitIndice(KFbxMesh* mesh)
{
	std::vector<int>	nb_indice;

	nb_indice = ResizeIndice(mesh, mesh->GetPolygonVertices());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->__tab[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, nb_indice.size() * sizeof(int), nb_indice.data(), GL_STATIC_DRAW);
	this->__nb_indice = nb_indice.size();
	std::cout << "NB INDICE: " << this->__nb_indice << std::endl;
	return true;
}

bool
Mesh::InitNormal(KFbxMesh* mesh)
{
	mesh->ComputeVertexNormals();
	for (int i = 0; i < mesh->GetLayerCount(); ++i)
	{
		if (mesh->GetLayer(i)->GetNormals() != 0)
		{
			KFbxLayerElementArrayReadLock<KFbxVector4>	lock(mesh->GetLayer(i)->GetNormals()->GetDirectArray());
			glBindBuffer(GL_ARRAY_BUFFER, this->__tab[2]);
			glBufferData(GL_ARRAY_BUFFER, mesh->GetControlPointsCount() * sizeof(double) * 4, lock.GetData(), GL_STATIC_DRAW);
			this->__is_normal = true;
			break;
		}
	}
	return true;
}

/*
void
Mesh::InitMaterial(KFbxNode* node)
{
	KFbxProperty		property;
	KFbxFileTexture*	texture;

	for (int i = 0; i < node->GetMaterialCountt(); i++)
	{
		if (node->GetMaterial(i))
		{
			property = node->GetMaterial()->FindProperty(KFbxSurfaceMaterial::sDiffuse);
			if (property.IsValid())
			{
				if (property.GetSrcObjectCount())
				{
					texture = property.GetSrcObject(FBX_TYPE(KFbxFileTexture), 0);
				}
			}
		}
}
*/

std::vector<int>
Mesh::ResizeIndice(KFbxMesh* mesh, int*)
{
	int			i = 0;
	int			j = 1;
	std::vector<int>	nb_indice;

	while (i < mesh->GetPolygonCount())
	{
		j = 1;
		while (j + 1 < mesh->GetPolygonSize(i))
		{
			nb_indice.push_back(mesh->GetPolygonVertex(i, 0));
			nb_indice.push_back(mesh->GetPolygonVertex(i, j));
			nb_indice.push_back(mesh->GetPolygonVertex(i, j + 1));
			j++;
		}
		i++;
	}
	return nb_indice;
}

void
Mesh::Draw()
{
	Node::Draw();
	glBindBuffer(GL_ARRAY_BUFFER, this->__tab[0]);
	glVertexPointer(3, GL_DOUBLE, 4 * sizeof(double), 0);
	glEnableClientState(GL_VERTEX_ARRAY);
	if (this->__is_normal == true)
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->__tab[2]);
		glNormalPointer(GL_DOUBLE, sizeof(double) * 4, 0);
		glEnableClientState(GL_NORMAL_ARRAY);
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->__tab[1]);
	glDrawElements(GL_TRIANGLES, this->__nb_indice, GL_UNSIGNED_INT, 0);
	if (this->__is_normal == true)
		glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}
