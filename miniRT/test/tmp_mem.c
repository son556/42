static t_rot	rotate_plane_z(t_cube_plane	plane)
{
	t_vec3	point;
	t_vec3	l_vec;
	t_vec3	rot;
	t_rot	rot_r;

	l_vec = sub_vec3(plane.plane_vertex[0], plane.plane_vertex[3]);
	point = plane.plane_vertex[0];
	rot.x = (ft_pow(l_vec.y) * point.x - l_vec.x * l_vec.y * point.y) / \
		(ft_pow(l_vec.x) + ft_pow(l_vec.y));
	rot.y = (-l_vec.y / l_vec.x) * rot.x;
	rot.z = rot.y / rot.x;
	point.z = sqrt(ft_pow(rot.y) + ft_pow(rot.x));
	rot_r.v_x = vec3init(rot.x / point.z, rot.y / point.z, 0);
	rot_r.v_y = vec3init(-rot.y / point.z, rot.x / point.z, 0);
	rot_r.v_z = vec3init(0, 0, 1);
	return (rot_r);
}

static t_cube_plane	rot_plane_abcd(t_rot rot, t_cube_plane plane)
{
	t_cube_plane	rot_plane;
	int				i;

	rot_plane.center = vec3x3_x_vec3(rot, plane.center);
	rot_plane.n_vec = vec3x3_x_vec3(rot, plane.n_vec);
	i = -1;
	while (++i < 4)
		rot_plane.plane_vertex[i] = vec3x3_x_vec3(rot, plane.plane_vertex[i]);
	return (rot_plane);
}

static int	in_the_target(t_rot	rot, t_discrim disc, t_cube_plane rot_plane)
{
	t_minmax	m;
	int			i;

	disc.ac = vec3x3_x_vec3(rot, disc.ac);
	rot_plane = rot_plane_abcd(rot, rot_plane);
	m.max_x = -INFINITY;
	m.min_x = INFINITY;
	m.max_y = -INFINITY;
	m.min_y = INFINITY;
	i = -1;
	while (++i < 4)
	{
		if (rot_plane.plane_vertex[i].x < m.min_x)
			m.min_x = rot_plane.plane_vertex[i].x;
		if (rot_plane.plane_vertex[i].x > m.max_x)
			m.max_x = rot_plane.plane_vertex[i].x;
		if (rot_plane.plane_vertex[i].y < m.min_y)
			m.min_y = rot_plane.plane_vertex[i].y;
		if (rot_plane.plane_vertex[i].y > m.max_y)
			m.max_y = rot_plane.plane_vertex[i].y;
	}
	if (disc.ac.x >= m.min_x && disc.ac.x <= m.max_x && \
		disc.ac.y >= m.min_y && disc.ac.y <= m.max_y)
		return (1);
	return (0);
}

static double	hit_plane_c(t_cube_plane rot_plane, t_ray rot_ray, double t_max)
{
	t_discrim	disc;
	t_rot		rot;
	t_vec3		vec_c;

	vec_c.x = dot_vec3(rot_ray.direction, rot_plane.n_vec);
	if (vec_c.x <= 1e-5 && vec_c.x >= -1e-5)
		return (0);
	vec_c.x = dot_vec3(sub_vec3(rot_ray.point, rot_plane.center), \
		rot_plane.n_vec);
	if (vec_c.x <= 1e-5 && vec_c.x >= -1e-5)
		return (0);
	disc.ac = sub_vec3(rot_ray.point, rot_plane.center);
	disc.a = -1 * dot_vec3(disc.ac, rot_plane.n_vec);
	disc.b = dot_vec3(rot_ray.direction, rot_plane.n_vec);
	disc.root = disc.a / disc.b;
	if (disc.root < 0.0001 || disc.root > t_max)
		return (0);
	disc.ac = ray_at(rot_ray, disc.root);
	vec_c = normalize_vec3(rot_plane.center);
	rot = rotate_plane_z(rot_plane);
	if (in_the_target(rot, disc, rot_plane) == 0)
		return (0);
	return (disc.root);
}

double	hit_cube(t_obj obj, t_ray ray, double t_max, t_color3 *color)
{
	t_ray			rot_ray;
	t_cube			cube;
	t_rot			rot;
	t_cube_plane	rot_plane;
	int				i;

	cube = obj.cube;
	i = -1;
	cube.t_root = t_max;
	while (++i < 6)
	{
		rot = rotate_vec_001(cube.plane[i].n_vec);
		rot_ray.point = vec3x3_x_vec3(rot, ray.point);
		rot_ray.direction = vec3x3_x_vec3(rot, ray.direction);
		rot_plane = rot_plane_abcd(rot, cube.plane[i]);
		cube.temp_root = hit_plane_c(rot_plane, rot_ray, cube.t_root);
		if (cube.temp_root > 0 && cube.temp_root < cube.t_root)
		{
			color->x = cube.plane[i].color.x;
			color->y = cube.plane[i].color.y;
			color->z = cube.plane[i].color.z;
			cube.t_root = cube.temp_root;
		}
	}
	return (cube.t_root);
}
