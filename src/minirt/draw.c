/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:21:07 by hermarti          #+#    #+#             */
/*   Updated: 2026/04/27 16:23:40 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel_row(t_window *window, int y, unsigned int *colors)
{
	unsigned int	*row;

	row = (unsigned int *)(window->img.img_addr + y * window->img.size_line);
	ft_memcpy(row, colors, window->width * window->img.pixel_size);
}
