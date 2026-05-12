/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_surface_params_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:49:00 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/08 14:49:01 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects_bonus.h"

void	set_surface_matrix(t_surface_parameters p, t_mat4 *m)
{
	m->m[0][0] = p.w.x;
	m->m[1][1] = p.w.y;
	m->m[2][2] = p.w.z;
	m->m[0][3] = p.l.x;
	m->m[3][0] = m->m[0][3];
	m->m[1][3] = p.l.y;
	m->m[3][1] = m->m[1][3];
	m->m[2][3] = p.l.z;
	m->m[3][2] = m->m[2][3];
	m->m[3][3] = p.diameter;
}

void	set_surface_type(t_surface_parameters *p)
{
	if (p->type == SPHERE)
		set_surface_sphere_quadric(p);
	else if (p->type == PLANE)
		set_surface_plane_quadric(p);
	else if (p->type == CYLINDER)
		set_surface_cylinder_quadric(p);
	else if (p->type == CONE)
		set_surface_cone_quadric(p);
	else if (p->type == HYPERBOLOID)
		set_surface_hyperboloid_quadric(p);
	else if (p->type == PARABOLOID)
		set_surface_paraboloid_quadric(p);
}
