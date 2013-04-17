#include "node.h"
#include <GL/glut.h>

Node::Node()
{
	this->__node = 0;
}

Node::~Node()
{
}

bool
Node::InitNode(KFbxNode* node)
{
	this->__node = node;
	return true;
}

bool
Node::AddChild(Node* node)
{
	try
	{
		this->__list_node.push_back(node);
	}
	catch(...)
	{
		return false;
	}
	return true;
}

void
Node::Draw()
{
	std::list<Node*>::iterator	it;
	it = this->__list_node.begin();

	glMultMatrixd(this->__node->EvaluateLocalTransform());
	while (it != this->__list_node.end())
	{
		glPushMatrix();
		(*it)->Draw();
		glPopMatrix();
		it++;
	}
}

