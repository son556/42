#ifndef HITTABLE_H
# define HITTABLE_H

# include "ray.h"

typedef struct hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		t;
}	hit_record;

#endif