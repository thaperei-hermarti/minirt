/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:48:34 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/11 18:03:52 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "libft.h"

void	parse_optional_properties(char **arr, int start_idx,
		t_surface_parameters *s_params)
{
	char	*equal_pos;
	char	*value;

	if (!arr || !s_params)
		return ;
	while (arr[start_idx])
	{
		equal_pos = ft_strchr(arr[start_idx], '=');
		if (equal_pos)
		{
			value = equal_pos + 1;
			if (ft_strncmp(arr[start_idx], "spec=", 5) == 0)
				s_params->spec_strength = ft_atod(value);
			else if (ft_strncmp(arr[start_idx], "refl=", 5) == 0)
				s_params->reflectivity = ft_atod(value);
			else if (ft_strncmp(arr[start_idx], "texture=", 8) == 0)
			{
				s_params->texture_path = ft_strdup(value);
				s_params->has_texture = 1;
			}
		}
		else if (ft_strcmp(arr[start_idx], "check") == 0)
			s_params->is_checked = 1;
		start_idx++;
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
