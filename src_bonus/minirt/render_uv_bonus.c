/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_uv_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:00:00 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/11 10:00:00 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "rt_math_bonus.h"
#include <math.h>

static void	get_basis_from_axis(t_vec4 axis, t_vec4 *u_axis, t_vec4 *v_axis)
{
	t_vec4	ref;

	ref = (t_vec4){0, 1, 0, 0};
	if (fabs(axis.y) >= 0.9)
		ref = (t_vec4){1, 0, 0, 0};
	*u_axis = vec4_normalize(vec4_cross_prod(ref, axis));
	*v_axis = vec4_normalize(vec4_cross_prod(axis, *u_axis));
}

static void	uv_cylinder_cone(t_surface *s, t_vec4 local_p, float *u, float *v)
{
	t_vec4	axis;
	t_vec4	u_axis;
	t_vec4	v_axis;
	double	range;
	double	h;

	axis = vec4_normalize(s->obj.orientation);
	get_basis_from_axis(axis, &u_axis, &v_axis);
	h = vec4_dot_prod(local_p, axis);
	range = s->obj.max - s->obj.min;
	*u = 0.5 + (atan2(vec4_dot_prod(local_p, v_axis), vec4_dot_prod(local_p,
					u_axis)) / (2.0 * M_PI));
	if (range > 0.0001)
		*v = (float)((h - s->obj.min) / range);
	else
		*v = 0.0f;
}

t_uv	get_generic_uv(t_surface *s, t_vec4 n, t_vec4 hit_p)
{
	t_vec4	local_p;
	t_vec4	u_axis;
	t_vec4	v_axis;
	t_vec4	d;
	t_uv	uv;

	local_p = vec4_sub(hit_p, s->obj.coordinate);
	if (s->type == PLANE)
	{
		get_basis_from_axis(n, &u_axis, &v_axis);
		uv.u = vec4_dot_prod(local_p, u_axis);
		uv.v = vec4_dot_prod(local_p, v_axis);
	}
	else if (s->type == CYLINDER || s->type == CONE)
		uv_cylinder_cone(s, local_p, &uv.u, &uv.v);
	else
	{
		d = vec4_normalize(local_p);
		uv.u = 0.5 + (atan2(d.z, d.x) / (2.0 * M_PI));
		uv.v = 0.5 - (asin(d.y) / M_PI);
	}
	return (uv);
}

void	apply_checkerboard(t_surface *s, t_uv uv)
{
	int		u_check;
	int		v_check;
	float	frequency;
	t_color	color[2];

	frequency = 16.0;
	if (s->type == PLANE)
		frequency = 0.5;
	u_check = (int)floor(uv.u * frequency);
	v_check = (int)floor(uv.v * frequency);
	color[0] = (t_color){255, 255, 255, 0};
	color[1] = (t_color){0, 0, 0, 0};
	if ((u_check + v_check) % 2 == 0)
	{
		s->obj.material.color = color[0];
		s->obj.color = color[0];
	}
	else
	{
		s->obj.material.color = color[1];
		s->obj.color = color[1];
	}
}
