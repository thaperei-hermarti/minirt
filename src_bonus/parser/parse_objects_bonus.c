/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:48:34 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/10 20:45:00 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "libft.h"

static void	parse_optional_properties(char **arr, int start_idx,
		t_surface_parameters *s_params)
{
	int		i;
	char	*eq_pos;
	char	*value;

	if (!arr || !s_params)
		return ;
	i = start_idx;
	while (arr[i])
	{
		eq_pos = ft_strchr(arr[i], '=');
		if (eq_pos)
		{
			value = eq_pos + 1;
			if (ft_strncmp(arr[i], "spec=", 5) == 0)
				s_params->reflectivity = ft_atof(value);
			else if (ft_strncmp(arr[i], "refl=", 5) == 0)
				s_params->reflectivity = ft_atof(value);
			else if (ft_strncmp(arr[i], "texture=", 8) == 0)
			{
				s_params->texture_path = ft_strdup(value);
				s_params->has_texture = 1;
			}
		}
		else if (ft_strcmp(arr[i], "check") == 0)
			s_params->is_checked = 1;
		i++;
	}
}

void	parse_sphere(char **arr, t_scene *scene)
{
	t_surface				*s;
	t_surface_parameters	s_params;

	s = &scene->surfaces[scene->idx_obj++];
	s_params = (t_surface_parameters){};
	save_vec4(arr[1], &s_params.coordinate);
	s_params.diameter = ft_atof(arr[2]);
	save_color(arr[3], &s_params.color);
	s_params.type = SPHERE;
	parse_optional_properties(arr, 4, &s_params);
	*s = create_surface(s_params);
}

void	parse_plane(char **arr, t_scene *scene)
{
	t_surface				*s;
	t_surface_parameters	s_params;

	s = &scene->surfaces[scene->idx_obj++];
	s_params = (t_surface_parameters){};
	save_vec4(arr[1], &s_params.coordinate);
	save_vec4(arr[2], &s_params.orientation);
	save_color(arr[3], &s_params.color);
	s_params.type = PLANE;
	parse_optional_properties(arr, 4, &s_params);
	*s = create_surface(s_params);
}

void	parse_cylinder(char **arr, t_scene *scene)
{
	t_surface				*s;
	t_surface_parameters	s_params;

	s = &scene->surfaces[scene->idx_obj++];
	s_params = (t_surface_parameters){};
	save_vec4(arr[1], &s_params.coordinate);
	save_vec4(arr[2], &s_params.orientation);
	s_params.diameter = ft_atof(arr[3]);
	s_params.height = ft_atof(arr[4]);
	save_color(arr[5], &s_params.color);
	s_params.type = CYLINDER;
	s_params.is_bounded = 1;
	parse_optional_properties(arr, 6, &s_params);
	*s = create_surface(s_params);
}

void	parse_cone(char **arr, t_scene *scene)
{
	t_surface				*s;
	t_surface_parameters	s_params;

	s = &scene->surfaces[scene->idx_obj++];
	s_params = (t_surface_parameters){};
	save_vec4(arr[1], &s_params.coordinate);
	save_vec4(arr[2], &s_params.orientation);
	s_params.angle = ft_atof(arr[3]);
	s_params.height = ft_atof(arr[4]);
	save_color(arr[5], &s_params.color);
	s_params.type = CONE;
	s_params.is_bounded = 1;
	parse_optional_properties(arr, 6, &s_params);
	*s = create_surface(s_params);
}

void	parse_hyperboloid(char **arr, t_scene *scene)
{
	t_surface				*s;
	t_surface_parameters	s_params;

	s = &scene->surfaces[scene->idx_obj++];
	s_params = (t_surface_parameters){};
	save_vec4(arr[1], &s_params.coordinate);
	save_vec4(arr[2], &s_params.orientation);
	s_params.a = ft_atof(arr[3]);
	s_params.b = ft_atof(arr[4]);
	s_params.c = ft_atof(arr[5]);
	s_params.height = ft_atof(arr[6]);
	save_color(arr[7], &s_params.color);
	s_params.type = HYPERBOLOID;
	s_params.is_bounded = 1;
	parse_optional_properties(arr, 8, &s_params);
	*s = create_surface(s_params);
}

void	parse_paraboloid(char **arr, t_scene *scene)
{
	t_surface				*s;
	t_surface_parameters	s_params;

	s = &scene->surfaces[scene->idx_obj++];
	s_params = (t_surface_parameters){};
	save_vec4(arr[1], &s_params.coordinate);
	save_vec4(arr[2], &s_params.orientation);
	s_params.k = ft_atof(arr[3]);
	s_params.height = ft_atof(arr[4]);
	save_color(arr[5], &s_params.color);
	s_params.type = PARABOLOID;
	s_params.is_bounded = 1;
	parse_optional_properties(arr, 6, &s_params);
	*s = create_surface(s_params);
}
