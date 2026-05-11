/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:58:02 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/11 10:00:00 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "mlx.h"
#include "rt_math_bonus.h"
#include <math.h>

static int	render_pixel(t_env *env, t_ray *ray, int x, int y)
{
	double	vp_x;
	double	vp_y;
	double	scale;
	t_vec4	color;

	scale = tan(env->scene.camera.fov_scale * 0.5 * M_PI / 180.0);
	vp_x = ((2.0 * (x + 0.5) / WINDOW_WIDTH - 1.0) * (WINDOW_WIDTH
				/ (double)WINDOW_HEIGHT) * scale);
	vp_y = ((1.0 - 2.0 * (y + 0.5) / WINDOW_HEIGHT) * scale);
	ray->dir = vec4_add(vec4_add(vec4_scale(env->scene.camera.right, vp_x),
				vec4_scale(env->scene.camera.up, vp_y)),
			vec4_normalize(env->scene.camera.dir));
	ray->dir = vec4_normalize(ray->dir);
	color = trace_ray(env, *ray, 3);
	return (vec4_to_int(color));
}

static void	setup_camera_basis(t_env *env)
{
	t_vec4	forward;
	t_vec4	up;

	forward = vec4_normalize(env->scene.camera.dir);
	up = (t_vec4){.x = 0.0, .y = 1.0, .z = 0.0, .w = 0.0};
	if (fabs(forward.y) > 0.999f)
		up = (t_vec4){.x = 0.0, .y = 0.0, .z = 1.0, .w = 0.0};
	env->scene.camera.right = vec4_normalize(vec4_cross_prod(forward, up));
	env->scene.camera.up = vec4_normalize(
			vec4_cross_prod(env->scene.camera.right, forward));
}

static void	render_scene(t_env *env)
{
	t_ray			ray;
	unsigned int	row_buf[WINDOW_WIDTH];
	int				x;
	int				y;

	ray.orig = env->scene.camera.origin;
	ray.orig.w = 1.0f;
	setup_camera_basis(env);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			row_buf[x] = render_pixel(env, &ray, x, y);
			x++;
		}
		put_pixel_row(&env->window, y, row_buf);
		y++;
	}
}

void	render_loop(t_env *env)
{
	render_scene(env);
	mlx_put_image_to_window(env->window.mlx, env->window.x_window,
		env->window.img.img, 0, 0);
	mlx_loop(env->window.mlx);
}
