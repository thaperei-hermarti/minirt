/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:15:41 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/07 12:15:50 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H
# include "scene_bonus.h"

typedef struct s_hash_item_parser
{
	char	*key;
	void	(*parse)(char **, t_scene *);
}	t_hash_item_parser;

void	parse_elements(t_scene *scene);
void	parse_optional_properties(char **arr, int start_idx,
			t_surface_parameters *s_params);

// Object parsers
void	parse_ambient(char **arr, t_scene *scene);
void	parse_camera(char **arr, t_scene *scene);
void	parse_light(char **arr, t_scene *scene);
void	parse_sphere(char **arr, t_scene *scene);
void	parse_plane(char **arr, t_scene *scene);
void	parse_cylinder(char **arr, t_scene *scene);
void	parse_cone(char **arr, t_scene *scene);
void	parse_hyperboloid(char **arr, t_scene *scene);
void	parse_paraboloid(char **arr, t_scene *scene);

// Low-level savers
void	save_double(const char *token, double *dst);
void	save_color(const char *token, t_color *dst);
void	save_vec4(const char *token, t_vec4 *dst);
#endif
