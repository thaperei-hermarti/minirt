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

void	clamp_color(int *r, int *g, int *b)
{
	if (*r < 0)
		*r = 0;
	else if (*r > 255)
		*r = 255;
	if (*g < 0)
		*g = 0;
	else if (*g > 255)
		*g = 255;
	if (*b < 0)
		*b = 0;
	else if (*b > 255)
		*b = 255;
}

void	put_pixel(t_window *window, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < window->width && y >= 0 && y < window->height)
	{
		pxl = window->img.img_addr
			+ (y * window->img.size_line
				+ x * (window->img.bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}
