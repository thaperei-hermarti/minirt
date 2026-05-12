/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_key_value_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 18:11:58 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/11 18:14:33 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation_bonus.h"

int	is_key_value_pair(char *str, char *key)
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

char	*get_key_value(char *str)
{
	char	*equal_pos;

	equal_pos = ft_strchr(str, '=');
	if (!equal_pos)
		return (NULL);
	return (equal_pos + 1);
}
