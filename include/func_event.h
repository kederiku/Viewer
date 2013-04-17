#ifndef __FUNC_EVENT_H__
#define __FUNC_EVENT_H__

#include <GLTools.h>
#include <GL/glut.h>
#include "render.h"

void	Timer(int value);
void	KeyboardSpecial(int key, int x, int y);
void	Keyboard(unsigned char key, int x, int y);
void	Mouse(int button, int stat, int x, int y);
void	Draw(void);
void	MotionMouse(int x, int y);
void	OrthographicProjection(void);
void	PerspectiveProjection(void);
void	itoa(unsigned int value, char* buf);

#endif
