/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:49:14 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/08 14:49:15 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	put_pixel_row(t_window *window, int y, unsigned int *colors)
{
	unsigned int	*row;

	row = (unsigned int *)(window->img.img_addr + y * window->img.size_line);
	ft_memcpy(row, colors, window->width * window->img.pixel_size);
}
