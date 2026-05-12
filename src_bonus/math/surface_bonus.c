/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:49:34 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/07 12:16:30 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "objects_bonus.h"
#include "rt_math_bonus.h"

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
	t_vec4	trans_vec;

	orient = get_orientation(p.orientation);
	rot = mat4_rotation_from_to((t_vec4){0.0, 1.0, 0.0, 0.0}, orient);
	res = mat4_mat4_mult(mat4_mat4_mult(rot, base), mat4_transpose(rot));
	trans_vec = (t_vec4){-p.coordinate.x, -p.coordinate.y, -p.coordinate.z,
		1.0};
	trans = mat4_translation(trans_vec);
	return (mat4_mat4_mult(mat4_mat4_mult(mat4_transpose(trans), res), trans));
}

static void	init_surface_bounds(t_surface *res, t_surface_parameters p)
{
	if (!p.is_bounded)
		return ;
	if (p.type == CONE || p.type == PARABOLOID)
	{
		res->obj.min = 0.0;
		res->obj.max = p.height;
	}
	else
	{
		res->obj.min = -p.height / 2;
		res->obj.max = p.height / 2;
	}
}

static void	set_surface_properties(t_surface *res, t_surface_parameters p)
{
	res->obj.mat = compute_final_mat(p, res->obj.mat);
	res->obj.orientation = get_orientation(p.orientation);
	res->obj.reflectivity = p.reflectivity;
	res->obj.material = (t_material){
		.color = p.color,
		.specular = (t_specular){
		.index = 16.0,
		.strenght = p.spec_strength,
		.color = (t_color){255, 255, 255, 0}
	},
		.reflect = p.reflectivity
	};
	res->type = p.type;
	res->is_bounded = p.is_bounded;
	res->is_checked = p.is_checked;
	res->has_texture = p.has_texture;
	res->texture_path = p.texture_path;
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
	res.obj.mat = base_mat;
	init_surface_bounds(&res, p);
	set_surface_properties(&res, p);
	return (res);
}
