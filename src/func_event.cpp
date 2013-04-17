#include "func_event.h"

/*
void
Timer(int value)
{
	const int fps = 120;
	glutTimerFunc(1000 / fps, Timer, ++value);
	Render::GetInstance()->FPS();
	glutPostRedisplay();
}
*/
void
KeyboardSpecial(int key, int x, int y)
{
	(void)x;
	(void)y;

	switch (key)
	{
		case GLUT_KEY_PAGE_UP:
			Render::GetInstance()->SetTranslation(0, 1, 0);
			break;
		case GLUT_KEY_PAGE_DOWN:
			Render::GetInstance()->SetTranslation(0, -1, 0);
			break;
		case GLUT_KEY_UP:
			Render::GetInstance()->SetTranslation(0, 0, 1);
			break;
		case GLUT_KEY_DOWN:
			Render::GetInstance()->SetTranslation(0, 0, -1);
			break;
		case GLUT_KEY_RIGHT:
			Render::GetInstance()->SetTranslation(-1, 0, 0);
			break;
		case GLUT_KEY_LEFT:
			Render::GetInstance()->SetTranslation(1, 0, 0);
			break;
		case GLUT_KEY_F1:
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			break;
		case GLUT_KEY_F2:
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			break;
		case GLUT_KEY_F3:
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			break;
		case GLUT_KEY_F5:
			break;
	}
	glutPostRedisplay();
}

void
Keyboard(unsigned char key, int x, int y)
{
	(void)x;
	(void)y;

	switch(key)
	{
		case 27:
			exit(0);
			break;
		case '-':
			glDisable(GL_LIGHT0);
			break;
		case '+':
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

void
Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		Render::GetInstance()->SetMouseButton(true);
		Render::GetInstance()->SetPosMouse(x, y);
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		Render::GetInstance()->SetMouseButton(false);
	if (button == 3)
		Render::GetInstance()->SetTranslation(0, 0, 1);
	if (button == 4)
		Render::GetInstance()->SetTranslation(0, 0, -1);
	glutPostRedisplay();
}

void
MotionMouse(int x, int y)
{
	if ( Render::GetInstance()->GetMouseButton() == true)
	{
		Render::GetInstance()->SetRotation(x, y);
		glutPostRedisplay();
	}
	Render::GetInstance()->SetPosMouse(x, y);
}

void
Draw(void)
{
	Render::GetInstance()->RenderScene();
}

void
OrthographicProjection()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0,800, 0, 600);
	glMatrixMode(GL_MODELVIEW);
}

void
PerspectiveProjection()
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void
itoa(unsigned int value, char* buf)
{
	int i(1);

	while((value / i) >= 10)
		i *= 10;

	while (i > 0)
	{
		*buf = (value / i) % 10 + '0';
		++buf;
		i /= 10;
	}
	*buf = 0;
}
