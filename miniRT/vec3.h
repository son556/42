#ifndef	VEC3_H
# define VEC3_H

#include <math.h>
#include "ray.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	init_vec3(double x, double y, double z)
{
	t_vec3	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

t_vec3	add_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vec3	min_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vec3	mul_vec3(t_vec3 v1, double s)
{
	t_vec3	result;

	result.x = v1.x * s;
	result.y = v1.y * s;
	result.z = v1.z * s;
	return (result);
}

t_vec3	div_vec3(t_vec3 v1, double s)
{
	t_vec3	result;

	result.x = v1.x / s;
	result.y = v1.y / s;
	result.z = v1.z / s;
	return (result);
}

double	dot_vec3(t_vec3 v1, t_vec3 v2)
{
	double	result;

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (result);
}

t_vec3	cross_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v1.x;
	return (result);
}

double	len_vec3(t_vec3 v1)
{
	double	result;

	result = v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
	return (sqrt(result));
}

t_vec3	unit_vec3(t_vec3 v1)
{
	t_vec3	result;
	double	len;

	len = len_vec3(v1);
	result = div_vec3(v1, len);
	return (result);
}

typedef t_vec3 t_point3;
typedef t_vec3 t_color;

#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#endif


#endif