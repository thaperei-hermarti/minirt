/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:00:03 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/08 14:50:59 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "objects.h"
# include "scene.h"

# define WINDOW_WIDTH 1228
# define WINDOW_HEIGHT 720

typedef struct s_img_buffer
{
	void			*img;
	char			*img_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				pixel_size;
}					t_img_buffer;

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

double				calc_shadow(t_env *env, t_vec4 hit_p, t_surface *obj);

typedef struct s_light_componets_params
{
	t_vec4			n;
	t_vec4			hit_p;
	double			shadow;
}					t_light_componets_params;

t_vec4				calc_light_components(t_env *env, t_surface *obj,
						t_light_componets_params *p);
int					calc_lighting(t_env *env, t_vec4 n, t_vec4 hit_p,
						t_surface *obj);
int					cast_ray(t_ray *ray, t_env *env, double *out_t);

#endif
