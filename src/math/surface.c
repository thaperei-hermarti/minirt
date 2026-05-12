/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:49:34 by hermarti          #+#    #+#             */
/*   Updated: 2026/04/29 21:13:43 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "objects.h"
#include "rt_math.h"

static t_vec4	get_orientation(t_vec4 orientation)
{
	if (vec4_mag(orientation) < 0.0001)
		return ((t_vec4){0.0, 1.0, 0.0, 0.0});
	return (vec4_normalize(orientation));
}

static t_mat4	compute_final_mat(t_surface_parameters p, t_mat4 base)
{
	t_mat4	rot;
	t_mat4	trans;
	t_mat4	res;
	t_vec4	orient;

	orient = get_orientation(p.orientation);
	rot = mat4_rotation_from_to((t_vec4){0.0, 1.0, 0.0, 0.0}, orient);
	res = mat4_mat4_mult(mat4_mat4_mult(rot, base), mat4_transpose(rot));
	trans = mat4_translation((t_vec4){-p.coordinate.x, -p.coordinate.y,
			-p.coordinate.z, 1.0});
	return (mat4_mat4_mult(mat4_mat4_mult(mat4_transpose(trans), res), trans));
}

t_surface	create_surface(t_surface_parameters p)
{
	t_surface				res;
	t_mat4					base_mat;
	t_surface_parameters	base_p;

	ft_memset(&res, 0, sizeof(t_surface));
	ft_memset(&base_mat, 0, sizeof(t_mat4));
	base_p = p;
	base_p.coordinate = (t_vec4){.x = 0.0, .y = 0.0, .z = 0.0, .w = 1.0};
	base_p.orientation = (t_vec4){.x = 0.0, .y = 1.0, .z = 0.0, .w = 0.0};
	set_surface_type(&base_p);
	set_surface_matrix(base_p, &base_mat);
	res.obj.coordinate = p.coordinate;
	res.obj.min = -p.height / 2;
	res.obj.max = p.height / 2;
	res.obj.mat = compute_final_mat(p, base_mat);
	res.obj.orientation = get_orientation(p.orientation);
	res.type = p.type;
	res.is_bounded = p.is_bounded;
	res.obj.color = p.color;
	return (res);
}

t_vec4	get_surface_normal(t_surface s, t_vec4 hit_point)
{
	t_vec4	n;

	ft_memset(&n, 0, sizeof(t_vec4));
	n = vec4_mat4_mul(hit_point, s.obj.mat);
	return (vec4_normalize(n));
}
