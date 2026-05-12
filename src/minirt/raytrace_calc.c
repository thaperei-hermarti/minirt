/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:59:09 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/05 12:06:17 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "objects.h"
#include "rt_math.h"
#include <math.h>

double	calc_shadow(t_env *env, t_vec4 hit_p, t_surface *obj)
{
	t_ray			shadow_ray;
	unsigned int	i;
	double			light_dist;
	double			shadow_t;

	light_dist = vec4_mag(vec4_sub(env->scene.light->origin, hit_p));
	shadow_ray = (t_ray){vec4_normalize(vec4_sub(env->scene.light->origin,
				hit_p)), hit_p, 0};
	i = 0;
	while (i < env->scene.num_objs)
	{
		if (&env->scene.surfaces[i] != obj)
		{
			shadow_t = intersection(&shadow_ray, &env->scene.surfaces[i]);
			if (!isnan(shadow_t) && shadow_t > 0.0001 && shadow_t < (light_dist
					- 0.001))
				return (0.0);
		}
		i++;
	}
	return (1.0);
}

static t_vec4	calc_ambient(t_env *env, t_surface *obj)
{
	t_vec4	amb_color;

	amb_color = norm_color(obj->obj.color);
	amb_color = vec4_scale(amb_color, env->scene.ambient.lightness);
	amb_color = vec4_mul(amb_color, norm_color(env->scene.ambient.color));
	return (amb_color);
}

static t_vec4	calc_diffuse(t_env *env, t_surface *obj, double diff,
		double shadow)
{
	t_vec4	dir_color;

	dir_color = norm_color(obj->obj.color);
	dir_color = vec4_scale(dir_color, env->scene.light->brightness * diff
			* shadow);
	return (dir_color);
}

static t_vec4	calc_specular(t_env *env, double spec, double shadow)
{
	t_vec4	spec_color;

	spec_color = norm_color(env->scene.specular.color);
	spec_color = vec4_scale(spec_color, env->scene.specular.strenght * spec
			* shadow);
	return (spec_color);
}

t_vec4	calc_light_components(t_env *env, t_surface *obj,
		t_light_componets_params *p)
{
	t_vec4	light_dir;
	t_vec4	view_dir;
	double	diff;
	double	spec;

	light_dir = vec4_normalize(vec4_sub(env->scene.light->origin, p->hit_p));
	view_dir = vec4_normalize(vec4_sub(env->scene.camera.origin, p->hit_p));
	diff = fmax(vec4_dot_prod(p->n, light_dir), 0.0);
	spec = pow(fmax(vec4_dot_prod(view_dir, vec4_reflect(vec4_scale(light_dir,
							-1.0), p->n)), 0.0), 32.0);
	return (vec4_add(calc_ambient(env, obj), vec4_add(calc_diffuse(env, obj,
					diff, p->shadow), calc_specular(env, spec, p->shadow))));
}
