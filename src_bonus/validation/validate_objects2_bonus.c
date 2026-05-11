/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_objects2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:51:31 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/10 17:25:43 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation_bonus.h"

int	is_valid_cone(char **arr)
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
	if (arr[6] && !has_valid_optional_properties(arr, 6))
		return (0);
	return (1);
}

int	is_valid_hyperboloid(char **arr)
{
	if (!arr || !arr[1] || !arr[2] || !arr[3] || !arr[4] || !arr[5] || !arr[6]
		|| !arr[7])
		return (0);
	if (!is_valid_coordinates(arr[1]) || !is_valid_normalized_vector(arr[2]))
		return (0);
	if (!is_valid_float(arr[3]) || ft_atod(arr[3]) <= 0.0)
		return (0);
	if (!is_valid_float(arr[4]) || ft_atod(arr[4]) <= 0.0)
		return (0);
	if (!is_valid_float(arr[5]) || ft_atod(arr[5]) <= 0.0)
		return (0);
	if (!is_valid_float(arr[6]) || ft_atod(arr[6]) <= 0.0)
		return (0);
	if (!is_valid_color(arr[7]))
		return (0);
	if (arr[8] && !has_valid_optional_properties(arr, 8))
		return (0);
	return (1);
}

int	is_valid_paraboloid(char **arr)
{
	if (!arr || !arr[1] || !arr[2] || !arr[3] || !arr[4] || !arr[5])
		return (0);
	if (!is_valid_coordinates(arr[1]) || !is_valid_normalized_vector(arr[2]))
		return (0);
	if (!is_valid_float(arr[3]) || ft_atod(arr[3]) == 0.0)
		return (0);
	if (!is_valid_float(arr[4]) || ft_atod(arr[4]) <= 0.0)
		return (0);
	if (!is_valid_color(arr[5]))
		return (0);
	if (arr[6] && !has_valid_optional_properties(arr, 6))
		return (0);
	return (1);
}
