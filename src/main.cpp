#include <iostream>
#include "render.h"
#include "FBXloader.h"
#include "window.h"

int main(int argc, char** argv)
{
	Render*		render;
	FBX_Loader	loader;
	Window		window;

	render = Render::GetInstance();
	if (render == 0)
		return -1;
	window.InitGL(argc, argv);
	if (loader.Load("/info/gp2016/fbx/fps.FBX") == NULL)
		return -1;
	if (window.InitBuffer(loader.GetScene()->GetRootNode()) == false)
			return -1;
	glutMainLoop();
	loader.GetManager()->Destroy();
	Render::Kill();
	return 0;
}
