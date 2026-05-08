/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_surface_quadrics2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:13:44 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/08 14:14:25 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects_bonus.h"
#include <math.h>

void	set_surface_cone_quadric(t_surface_parameters *p)
{
	double	k;

	k = tan(p->angle * M_PI / 180.0);
	p->w = (t_vec4){.x = 1.0, .y = -(k * k), .z = 1.0, .w = 0.0};
	p->l = (t_vec4){.x = 0.0, .y = 0.0, .z = 0.0, .w = 0.0};
	p->diameter = 0.0;
}

void	set_surface_hyperboloid_quadric(t_surface_parameters *p)
{
	p->w = (t_vec4){.x = 1.0 / (p->a * p->a), .y = -1.0 / (p->c * p->c),
		.z = 1.0 / (p->b * p->b), .w = 0.0};
	p->l = (t_vec4){.x = 0.0, .y = 0.0, .z = 0.0, .w = 0.0};
	p->diameter = -1.0;
}

void	set_surface_paraboloid_quadric(t_surface_parameters *p)
{
	p->w = (t_vec4){.x = 1.0, .y = 0.0, .z = 1.0, .w = 0.0};
	p->l = (t_vec4){.x = 0.0, .y = -p->k / 2.0, .z = 0.0, .w = 0.0};
	p->diameter = 0.0;
}
