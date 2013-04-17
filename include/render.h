#ifndef __RENDER_H__
#define __RENDER_H__

#include "singleton.hpp"
#include "func_event.h"
#include "matrix.h"

class	Window;

struct t_transform
{
	double	rotation[2];
	double	translation[3];
};

struct t_mouse
{
	int	xold;
	int	yold;
	bool	button;
};

class Render : public Singleton<Render>
{
private:
	t_transform		__transform;
	t_mouse			__mouse;
	Window*			__window;
	GLuint			__fps;

	friend class Singleton;
				Render();
		virtual		~Render();

public:
	void			SetPosMouse(int x, int y);
	void			SetMouseButton(bool state);
	bool			GetMouseButton();
	void			SetTranslation(double x, double y, double z);
	void			SetRotation(double x, double y);
	void			CopyWindow(Window* window);
	void			RenderScene();
	void			Text(int x, int y, const char* txt);
	int			FPS(void);
};

#endif
