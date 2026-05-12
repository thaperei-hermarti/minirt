/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:15:21 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/09 19:35:58 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "img_bonus.h"
# include "objects_bonus.h"
# include "scene_bonus.h"

# define WINDOW_WIDTH 1228
# define WINDOW_HEIGHT 720

typedef struct s_window
{
	int				width;
	int				height;
	void			*mlx;
	void			*x_window;
	t_img_buffer	img;
}					t_window;

typedef struct s_env
{
	t_window		window;
	t_scene			scene;
}					t_env;

typedef struct s_shade_hit
{
	t_vec4			color;
	t_vec4			n;
	t_vec4			hit_p;
}					t_shade_hit;

typedef struct s_trace_ctx
{
	t_env			*env;
	t_ray			ray;
	int				depth;
	t_surface		*surface;
}					t_trace_ctx;

void				*init_env(t_env *env, int argc, char **argv);
void				*destroy_env(t_env *env);

void				*init_window(t_window *window, int width, int height,
						char *window_name);
void				*destroy_window(t_window *window);
int					close_window(t_env *env);

void				set_window_hooks(t_env *env);

int					key_hook(int keycode, void *param);

void				*init_img_buffer(t_window *window);
void				*destroy_img_buffer(t_window *window);

void				put_pixel_row(t_window *window, int y,
						unsigned int *colors);
void				render_loop(t_env *env);

int					load_scene_textures(t_env *env);
void				destroy_scene_textures(t_env *env);

t_uv				get_generic_uv(t_surface *s, t_vec4 n, t_vec4 hit_p);
void				apply_checkerboard(t_surface *s, t_uv uv);
t_vec4				perturb_normal(t_texture *tex, t_vec4 n, t_uv uv);

double				calc_shadow(t_env *env, t_vec4 hit_p, t_surface *obj,
						t_light *light);

typedef struct s_light_componets_params
{
	t_vec4			n;
	t_vec4			hit_p;
	double			shadow;
	t_light			*light;
}					t_light_componets_params;

t_vec4				calc_ambient(t_env *env, t_surface *obj);
t_vec4				calc_light_components(t_env *env, t_surface *obj,
						t_light_componets_params *p);
int					calc_lighting(t_env *env, t_vec4 n, t_vec4 hit_p,
						t_surface *obj);
int					cast_ray(t_ray *ray, t_env *env, double *out_t);
t_vec4				trace_ray(t_env *env, t_ray ray, int depth);

#endif
