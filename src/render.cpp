#include "render.h"
#include "window.h"
#include <iostream>
Render::Render(void)
{
	this->__transform.rotation[0] = 0.0f;
	this->__transform.rotation[1] = 0.0f;
	this->__transform.translation[0] = 18.0f;
	this->__transform.translation[1] = -44.0f;
	this->__transform.translation[2] = -46.0f;
}


Render::~Render()
{
}

void
Render::SetPosMouse(int x, int y)
{
	this->__mouse.xold = x;
	this->__mouse.yold = y;
}

bool
Render::GetMouseButton()
{
	return this->__mouse.button;
}

void
Render::SetMouseButton(bool state)
{
	this->__mouse.button = state;
}

void
Render::SetTranslation(double x, double y, double z)
{
	Matrix4	matrix;
	Matrix4	tmp;

	matrix.Rotate(-this->__transform.rotation[0], -this->__transform.rotation[1], 0);
	tmp.Set(3, 0, x);
	tmp.Set(3, 1, y);
	tmp.Set(3, 2, z);
	tmp = matrix.Mul(tmp);
	this->__transform.translation[0] += tmp.Get(3, 0);
	this->__transform.translation[1] += tmp.Get(3, 1);
	this->__transform.translation[2] += tmp.Get(3, 2);
}

void
Render::SetRotation(double x, double y)
{
	this->__transform.rotation[1] = this->__transform.rotation[1] + (x - this->__mouse.xold);
	this->__transform.rotation[0] = this->__transform.rotation[0] + (y - this->__mouse.yold);
}

void
Render::CopyWindow(Window* window)
{
	this->__window = window;
}

void
Render::RenderScene()
{
	Matrix4	matrix;
	Matrix4 tmp;
	char buf[11];
	int fps = FPS();

	matrix.Rotate(this->__transform.rotation[0], this->__transform.rotation[1], 0);
	tmp.Translate(this->__transform.translation[0], this->__transform.translation[1], this->__transform.translation[2]);
	tmp = matrix.Mul(tmp);
	glLoadMatrixd(tmp.Get_Matrix4());
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	this->__window->DrawMesh();
	itoa(fps, buf);
	Text(25, 570, "FPS: ");
	Text(70, 570, buf);
	glutSwapBuffers();
	glutPostRedisplay();
}

void
Render::Text(int x, int y, const char* txt)
{
	int i;
	OrthographicProjection();
	glLoadIdentity();
	glRasterPos2f(x, y);
	for (i = 0; txt[i]; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, txt[i]);
	}
	PerspectiveProjection();
}

int
Render::FPS(void)
{
	static int	current_time = 0;
	static int	last_time = 0;
	static int	n = 0;
	static int 	fps = n;

	n++;
	current_time = glutGet(GLUT_ELAPSED_TIME);
	if ((current_time - last_time) >= 1000)
	{
		fps = n;
		n = 0;
		last_time = current_time;
	}
	return fps;
}
