/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:18:26 by hermarti          #+#    #+#             */
/*   Updated: 2026/04/29 21:14:01 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

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

typedef struct s_obj
{
	t_mat4			mat;
	t_vec4			coordinate;
	t_vec4			orientation;
	double			min;
	double			max;
	t_color			color;
}					t_obj;

typedef enum e_surface_type
{
	SPHERE,
	PLANE,
	CYLINDER
}					t_surface_type;

typedef struct s_surface
{
	t_obj			obj;
	t_surface_type	type;
	unsigned char	is_bounded;
}					t_surface;

typedef struct s_surface_parameters
{
	t_vec4			coordinate;
	t_vec4			orientation;
	t_vec4			w;
	t_vec4			l;
	double			diameter;
	double			height;
	t_surface_type	type;
	t_color			color;
	unsigned char	is_bounded : 1;
}					t_surface_parameters;

void				set_surface_sphere_quadric(t_surface_parameters *p);
void				set_surface_plane_quadric(t_surface_parameters *p);
void				set_surface_cylinder_quadric(t_surface_parameters *p);
void				set_surface_matrix(t_surface_parameters p, t_mat4 *m);
void				set_surface_type(t_surface_parameters *p);
t_surface			create_surface(t_surface_parameters p);
t_vec4				get_surface_normal(t_surface s, t_vec4 hit_point);
#endif
