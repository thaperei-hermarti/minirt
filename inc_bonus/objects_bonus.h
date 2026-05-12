/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:15:11 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/11 18:58:37 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_BONUS_H
# define OBJECTS_BONUS_H

# include "img_bonus.h"

typedef struct s_vec4
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vec4;

typedef struct s_mat4
{
	double			m[4][4];
}					t_mat4;

typedef struct s_ray
{
	t_vec4			dir;
	t_vec4			orig;
	double			t;
}					t_ray;

typedef t_vec4		t_color;

typedef struct s_uv
{
	float			u;
	float			v;
}					t_uv;

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

typedef struct s_obj
{
	t_mat4			mat;
	t_vec4			coordinate;
	t_vec4			orientation;
	double			min;
	double			max;
	double			reflectivity;
	t_texture		texture;
	t_material		material;
}					t_obj;

typedef enum e_surface_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	HYPERBOLOID,
	PARABOLOID
}					t_surface_type;

typedef struct s_surface
{
	t_obj			obj;
	t_surface_type	type;
	char			*texture_path;
	unsigned char	is_bounded : 1;
	unsigned char	is_checked : 1;
	unsigned char	has_texture : 1;
}					t_surface;

typedef struct s_surface_parameters
{
	t_vec4			coordinate;
	t_vec4			orientation;
	t_vec4			w;
	t_vec4			l;
	double			diameter;
	double			height;
	double			angle;
	double			a;
	double			b;
	double			c;
	double			k;
	double			reflectivity;
	double			spec_strength;
	t_surface_type	type;
	t_color			color;
	char			*texture_path;
	unsigned char	is_bounded : 1;
	unsigned char	is_checked : 1;
	unsigned char	has_texture : 1;
}					t_surface_parameters;

void				set_surface_sphere_quadric(t_surface_parameters *p);
void				set_surface_plane_quadric(t_surface_parameters *p);
void				set_surface_cylinder_quadric(t_surface_parameters *p);

void				set_surface_cone_quadric(t_surface_parameters *p);
void				set_surface_hyperboloid_quadric(t_surface_parameters *p);
void				set_surface_paraboloid_quadric(t_surface_parameters *p);
void				set_surface_matrix(t_surface_parameters p, t_mat4 *m);
void				set_surface_type(t_surface_parameters *p);
t_surface			create_surface(t_surface_parameters p);
t_vec4				get_surface_normal(t_surface s, t_vec4 hit_point);
#endif
