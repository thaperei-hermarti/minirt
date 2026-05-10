/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_optional_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 15:00:00 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/10 20:02:41 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation_bonus.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * Check if a string is in the format "key=value"
 */
static int	is_key_value_pair(char *str, char *key)
{
	int	key_len;

	if (!str || !key)
		return (0);
	key_len = ft_strlen(key);
	if (ft_strncmp(str, key, key_len) != 0)
		return (0);
	if (str[key_len] != '=')
		return (0);
	return (1);
}

/**
 * Extract the value part from a "key=value" string
 */
static char	*get_key_value(char *str)
{
	char	*equal_pos;

	equal_pos = ft_strchr(str, '=');
	if (!equal_pos)
		return (NULL);
	return (equal_pos + 1);
}

/**
 * Validate spec parameter: float > 0.0 and <= 1.0
 */
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

/**
 * Validate refl parameter: float > 0.0 and <= 1.0
 */
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

/**
 * Validate texture parameter: must be a valid file path
 */
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

/**
 * Check if string is any optional property (spec, refl, texture, or check)
 */
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
	if (is_check_flag(str))
		return (1);
	return (0);
}

/**
 * Validate all optional properties in array starting from start_idx
 * Checks:
 * - spec and refl are valid floats (0.0 < value <= 1.0)
 * - texture is a valid path
 * - check is a flag
 * - texture and check cannot co-exist
 * Returns 1 if valid, 0 if invalid
 */
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
		if (!is_optional_property(arr[i]))
			return (0);
		if (!is_valid_spec(arr[i]))
			return (0);
		if (!is_valid_refl(arr[i]))
			return (0);
		if (!is_valid_texture(arr[i]))
			return (0);
		if (is_key_value_pair(arr[i], "texture"))
			has_texture = 1;
		if (ft_strcmp(str, "check") == 0)
			has_check = 1;
		i++;
	}
	if (has_texture && has_check)
		return (0);
	return (1);
}
