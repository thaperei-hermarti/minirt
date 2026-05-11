/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_properties2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:47:16 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/11 20:14:29 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation_bonus.h"
#include <fcntl.h>
#include <unistd.h>

int	is_valid_path(char *path)
{
	int	fd;
	int	str_len;

	if (!path)
		return (0);
	str_len = ft_strlen(path);
	if (str_len == 4 || ft_strcmp(path + str_len - 4, ".xpm") != 0)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	is_between_zero_and_one(char *number)
{
	double	num;

	num = ft_atod(number);
	return (num > 0.0 && num <= 1.0);
}
