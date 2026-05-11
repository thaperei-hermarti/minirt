/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_calc2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:15:01 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/11 17:54:41 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "rt_math_bonus.h"

int	calc_lighting(t_env *env, t_vec4 n, t_vec4 hit_p, t_surface *obj)
{
	double						shadow;
	t_vec4						light_sum;
	t_light_componets_params	p;

	shadow = calc_shadow(env, hit_p, obj, NULL);
	p = (t_light_componets_params){n, hit_p, shadow, NULL};
	light_sum = calc_light_components(env, obj, &p);
	return (vec4_to_int(light_sum));
}
