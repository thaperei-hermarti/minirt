/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_objects_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:32:07 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/11 10:00:00 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation_bonus.h"

int	is_valid_sphere(char **arr)
{
	if (!arr || !arr[1] || !arr[2] || !arr[3])
		return (0);
	if (!is_valid_coordinates(arr[1]))
		return (0);
	if (!is_valid_float(arr[2]) || ft_atod(arr[2]) <= 0.0)
		return (0);
	if (!is_valid_color(arr[3]))
		return (0);
	if (!has_valid_optional_properties(arr, 4))
		return (0);
	return (1);
}

int	is_valid_plane(char **arr)
{
	if (!arr || !arr[1] || !arr[2] || !arr[3])
		return (0);
	if (!is_valid_coordinates(arr[1]) || !is_valid_normalized_vector(arr[2])
		|| !is_valid_color(arr[3]))
		return (0);
	if (!has_valid_optional_properties(arr, 4))
		return (0);
	return (1);
}

int	is_valid_cylinder(char **arr)
{
	if (!arr || !arr[1] || !arr[2] || !arr[3] || !arr[4] || !arr[5])
		return (0);
	if (!is_valid_coordinates(arr[1]) || !is_valid_normalized_vector(arr[2]))
		return (0);
	if (!is_valid_float(arr[3]) || ft_atod(arr[3]) <= 0.0)
		return (0);
	if (!is_valid_float(arr[4]) || ft_atod(arr[4]) <= 0.0)
		return (0);
	if (!is_valid_color(arr[5]))
		return (0);
	if (!has_valid_optional_properties(arr, 6))
		return (0);
	return (1);
}
