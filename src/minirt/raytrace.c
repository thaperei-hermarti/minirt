/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:58:31 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/05 11:02:09 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"
#include "minirt.h"
#include <math.h>

int	cast_ray(t_ray *ray, t_env *env, double *out_t)
{
	double				t;
	double				min_t;
	int					hit_idx;
	unsigned int		i;

	min_t = INFINITY;
	hit_idx = -1;
	i = 0;
	while (i < env->scene.num_objs)
	{
		t = intersection(ray, &env->scene.surfaces[i]);
		if (!isnan(t) && t > 0.0f && t < min_t)
		{
			min_t = t;
			hit_idx = i;
		}
		i++;
	}
	*out_t = min_t;
	return (hit_idx);
}
