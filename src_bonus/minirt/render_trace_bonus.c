/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_trace_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:00:00 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/11 10:00:00 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "rt_math_bonus.h"

static t_shade_hit	shade_color(t_env *env, t_ray *ray, double t,
		t_surface *surface)
{
	t_shade_hit	hit;
	t_uv		uv;
	t_color		base_color;
	t_color		base_obj_color;
	int			color;

	hit.hit_p = vec4_add(ray->orig, vec4_scale(ray->dir, t));
	hit.n = get_surface_normal(*surface, hit.hit_p);
	if (vec4_dot_prod(hit.n, ray->dir) > 0)
		hit.n = vec4_scale(hit.n, -1.0);
	uv = get_generic_uv(surface, hit.n, hit.hit_p);
	base_color = surface->obj.material.color;
	base_obj_color = surface->obj.color;
	if (surface->is_checked)
		apply_checkerboard(surface, uv);
	if (surface->has_texture)
		hit.n = perturb_normal(&surface->obj.texture, hit.n, uv);
	hit.hit_p = vec4_add(hit.hit_p, vec4_scale(hit.n, 0.001));
	color = calc_lighting(env, hit.n, hit.hit_p, surface);
	surface->obj.material.color = base_color;
	surface->obj.color = base_obj_color;
	hit.color = int_to_vec4(color);
	return (hit);
}

static t_vec4	trace_reflection(t_trace_ctx *ctx, t_shade_hit hit)
{
	t_ray	refl_ray;
	t_vec4	refl_color;
	double	refl;

	if (ctx->surface->obj.reflectivity <= 0.0)
		return (hit.color);
	refl = ctx->surface->obj.reflectivity;
	refl_ray.dir = vec4_normalize(vec4_reflect(ctx->ray.dir, hit.n));
	refl_ray.orig = vec4_add(hit.hit_p, vec4_scale(hit.n, 0.001));
	refl_color = trace_ray(ctx->env, refl_ray, ctx->depth - 1);
	return (vec4_add(vec4_scale(hit.color, 1.0 - refl), vec4_scale(refl_color,
				refl)));
}

t_vec4	trace_ray(t_env *env, t_ray ray, int depth)
{
	t_trace_ctx	ctx;
	t_shade_hit	hit;
	double		t;
	int			hit_idx;

	if (depth <= 0)
		return ((t_vec4){0, 0, 0, 0});
	hit_idx = cast_ray(&ray, env, &t);
	if (hit_idx == -1)
		return ((t_vec4){0, 0, 0, 0});
	ctx.env = env;
	ctx.ray = ray;
	ctx.depth = depth;
	ctx.surface = &env->scene.surfaces[hit_idx];
	hit = shade_color(env, &ray, t, ctx.surface);
	return (trace_reflection(&ctx, hit));
}
