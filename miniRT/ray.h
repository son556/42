#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
}	t_ray;

t_ray	ray_init(t_point3 point3, t_vec3 dir)
{
	t_ray	out;

	out.orig = init_vec3(point3.x, point3.y, point3.z);
	out.dir = init_vec3(dir.x, dir.y, dir.z);
	return (out);
}

t_vec3	ray_at(t_ray ray, double t)
{
	t_vec3	out;
	t_vec3	dir;

	dir = mul_vec3(ray.dir, t);
	out = add_vec3(ray.orig, ray.dir);
	return (out);
}

int	hit_sphere(t_point3 center, double r, t_ray ray, double t_min, double t_max)
{
	t_vec3	oc = min_vec3(ray.orig, center);
	double	a = dot_vec3(ray.dir, ray.dir);
	double	b = dot_vec3(oc, ray.dir);
	double	c = dot_vec3(oc, oc) - r * r;
	double	discrim = b * b - a * c;

	if (discrim < 0)
		return (0);
	double sqrtd = sqrt(discrim);
	double root = (-b - sqrtd) / a;
	if (root < t_min || t_max < root)
	{
		root = (-b + sqrtd) / a;
		if (root < t_min || t_max < root)
			return (0);
	}
}

t_color	ray_color(t_ray ray)
{
	t_color	color;
	t_vec3	unit_dir;
	t_vec3	center;
	t_vec3	tmp;
	t_vec3	N;
	double	t;

	center = init_vec3(0, 0, -1);
	t = hit_sphere(center, 0.5, ray);
	if (t != -1)
	{
		tmp = ray_at(ray, t);
		N = unit_vec3(min_vec3(tmp, center));
		color = mul_vec3(init_vec3(N.x + 1, N.y + 1, N.z + 1), 0.5);
		return (color);
	}
	unit_dir = unit_vec3(ray.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	color = init_vec3(1.0 - 0.5 * t, 1.0 - 0.3 * t, 1.0);
	return (color);
}

#endif