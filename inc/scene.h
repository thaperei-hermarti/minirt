/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:18:18 by hermarti          #+#    #+#             */
/*   Updated: 2026/04/29 20:12:51 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "objects.h"
# include "libft.h"

typedef struct s_ambient
{
	double			lightness;
	t_color			color;
}					t_ambient;

typedef struct s_camera
{
	t_vec4			origin;
	t_vec4			dir;
	t_vec4			right;
	t_vec4			up;
	double			fov_scale;
	double			aspect;
}					t_camera;

typedef struct s_light
{
	t_vec4			origin;
	double			brightness;
	t_color			color;
}					t_light;

typedef struct s_specular
{
	double			index;
	double			strenght;
	t_color			color;
}				t_specular;

typedef struct s_material
{
	t_color			color;
	t_specular		specular;
	double			reflect;
}				t_material;

typedef struct s_scene
{
	t_camera		camera;
	t_ambient		ambient;
	t_specular		specular;
	t_list			*objs;
	t_light			*light;
	t_surface		*surfaces;
	unsigned int	idx_obj;
	unsigned int	num_objs;
	unsigned int	num_lights;
}				t_scene;
#endif
