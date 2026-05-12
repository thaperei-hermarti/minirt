/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_optional_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 15:00:00 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/11 18:15:36 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation_bonus.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static int	is_valid_spec(char *spec_str)
{
	char	*value;

	if (!is_key_value_pair(spec_str, "spec"))
		return (1);
	value = get_key_value(spec_str);
	if (!value || value[0] == '\0')
		return (0);
	if (!is_valid_float(value))
		return (0);
	return (is_between_zero_and_one(value));
}

static int	is_valid_refl(char *refl_str)
{
	char	*value;

	if (!is_key_value_pair(refl_str, "refl"))
		return (1);
	value = get_key_value(refl_str);
	if (!value || value[0] == '\0')
		return (0);
	if (!is_valid_float(value))
		return (0);
	return (is_between_zero_and_one(value));
}

static int	is_valid_texture(char *texture_str)
{
	char	*value;

	if (!is_key_value_pair(texture_str, "texture"))
		return (1);
	value = get_key_value(texture_str);
	if (!value || value[0] == '\0')
		return (0);
	return (is_valid_path(value));
}

static int	is_optional_property(char *str)
{
	if (!str)
		return (0);
	if (is_key_value_pair(str, "spec"))
		return (1);
	if (is_key_value_pair(str, "refl"))
		return (1);
	if (is_key_value_pair(str, "texture"))
		return (1);
	if (ft_strcmp(str, "check") == 0)
		return (1);
	return (0);
}

int	has_valid_optional_properties(char **arr, int start_idx)
{
	int	i;
	int	has_texture;
	int	has_check;

	if (!arr)
		return (1);
	has_texture = 0;
	has_check = 0;
	i = start_idx;
	while (arr[i])
	{
		if (!is_optional_property(arr[i]) || !is_valid_spec(arr[i])
			|| !is_valid_refl(arr[i]) || !is_valid_texture(arr[i]))
			return (0);
		if (is_key_value_pair(arr[i], "texture"))
			has_texture = 1;
		if (ft_strcmp(arr[i], "check") == 0)
			has_check = 1;
		i++;
	}
	if (has_texture && has_check)
		return (0);
	return (1);
}
