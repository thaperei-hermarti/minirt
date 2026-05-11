/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:57:43 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/11 17:59:25 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

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
