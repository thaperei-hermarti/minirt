/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_calc2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:43:44 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/10 14:43:45 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "rt_math_bonus.h"

int	calc_lighting(t_env *env, t_vec4 n, t_vec4 hit_p, t_surface *obj)
{
	double						shadow;
	t_vec4						light_sum;
	t_light_componets_params	p;
	unsigned int				i;

	light_sum = calc_ambient(env, obj);
	i = 0;
	while (i < env->scene.num_lights)
	{
		shadow = calc_shadow(env, hit_p, obj, &env->scene.light[i]);
		p = (t_light_componets_params){.n = n, .hit_p = hit_p, .shadow = shadow,
			.light = &env->scene.light[i]};
		light_sum = vec4_add(light_sum, calc_light_components(env, obj, &p));
		i++;
	}
	return (vec4_to_int(light_sum));
}
