#include "window.h"
#include <math.h>

Window::Window()
{
}

void
Window::InitGL(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_STENCIL);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Viewer 3D");
//	glutTimerFunc(0, Timer, 0);
	glutDisplayFunc(Draw);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(KeyboardSpecial);
	glutMouseFunc(Mouse);
	glutMotionFunc(MotionMouse);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)800/600, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glewInit();
}


bool
Window::MakeChild(Node* node, KFbxNode* pnode)
{
	Node* child = 0;

	if (pnode->GetNodeAttribute()->GetAttributeType() == KFbxNodeAttribute::eMESH)
		child = new(std::nothrow) Mesh;
	else
		child = new(std::nothrow) Node;
	if (child == 0)
		return false;
	if (child->InitNode(pnode) == false)
		return false;
	if (node->AddChild(child) == false)
	{
		delete child;
		return false;
	}
	if (this->InitTree(child, pnode) == false)
		return false;
	return true;
}

bool
Window::InitTree(Node* node, KFbxNode* pnode)
{
	int	i = 0;
	int	nb_child;

	nb_child = pnode->GetChildCount();
	while (i < nb_child)
	{
		if (MakeChild(node, pnode->GetChild(i)) == false)
			return false;
		i++;
	}
	return true;
}

bool
Window::InitBuffer(KFbxNode* node)
{
	if (InitTree(&this->__tree, node) == false)
		return false;
	Render::GetInstance()->CopyWindow(this);
	return true;
}

void
Window::DrawMesh()
{
	this->__tree.Draw();
}

