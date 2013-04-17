#ifndef __SPHERE_H__
#define __SPHERE_H__

#include <vector>

struct triangle_indice
{
		int	x;
		int	y;
		int	z;
		triangle_indice(int x, int y, int z);
}

struct Point
{
	double x;
	double y;
	double z;
}

class Sphere
{
public:
		Sphere();
		~Sphere();
private:
	int	AddVertex(Point p);
	std::vector<Point>	geometry;

};

#endif
