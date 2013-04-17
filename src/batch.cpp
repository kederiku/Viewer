#include "batch.h"
#include <vector>

Batch::Batch()
{
	this->__nb_vertex = 0;
}


std::vector<int>
indice(KFbxMesh* mesh, int*)
{
	int			i = 0;
	int			j;
	std::vector<int>	tab;

	while (i < mesh->GetPolygonCount())
	{
		j = 1;
		while (j + 1 < mesh->GetPolygonSize(i))
		{
			tab.push_back(mesh->GetPolygonVertex(i, 0));
			tab.push_back(mesh->GetPolygonVertex(i, j));
			tab.push_back(mesh->GetPolygonVertex(i, j + 1));
			j++;
		}
		i++;
	}
	return tab;
}

void
Batch::Init_index(KFbxMesh* mesh)
{
	std::vector<int>	tab = indice(mesh, mesh->GetPolygonVertices());

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->__tab[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, tab.size() * sizeof(int), tab.data(), GL_STATIC_DRAW);
	this->__nb_vertex = tab.size();
}


void	Batch::Init(KFbxNode* node)
{
	KFbxMesh*	mesh = node->GetMesh();
	KFbxVector4*	vector(mesh->GetControlPoints());
	KFbxLayer*	layer;

	Node::Init(node);
	glGenBuffers(3, this->__tab);
	mesh->ComputeVertexNormals();
	glBindBuffer(GL_ARRAY_BUFFER, this->__tab[0]);
	glBufferData(GL_ARRAY_BUFFER, mesh->GetControlPointsCount() * sizeof(*vector), vector, GL_STATIC_DRAW);
	for (int i = 0; i < mesh->GetLayerCount(); ++i)
	{
		layer = mesh->GetLayer(i);

		this->normals = layer->GetNormals();
		if (this->normals != NULL)
		{
			KFbxLayerElementArrayReadLock<KFbxVector4>	lock(this->normals->GetDirectArray());
			glBindBuffer(GL_ARRAY_BUFFER, this->__tab[2]);
			glBufferData(GL_ARRAY_BUFFER, mesh->GetControlPointsCount() * sizeof(double) * 4, lock.GetData(), GL_STATIC_DRAW);
			break;
		}
	}
	this->Init_index(mesh);
}

void
Batch::Draw()
{
	Node::Draw();
	glBindBuffer(GL_ARRAY_BUFFER, this->__tab[0]);
	glVertexPointer(3, GL_DOUBLE, 4 * sizeof(double), 0);
	glEnableClientState(GL_VERTEX_ARRAY);
	if (this->normals != NULL)
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->__tab[2]);
		glNormalPointer(GL_DOUBLE, sizeof(double) * 4, 0);
		glEnableClientState(GL_NORMAL_ARRAY);
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->__tab[1]);
	glDrawElements(GL_TRIANGLES, this->__nb_vertex, GL_UNSIGNED_INT, 0);
	if (this->normals != NULL)
		glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}
