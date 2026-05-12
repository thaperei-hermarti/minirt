/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:55:37 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/05 12:08:32 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "rt_math.h"
#include <math.h>

t_vec4	vec4_mul(t_vec4 a, t_vec4 b)
{
	t_vec4	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	res.w = a.w;
	return (res);
}

int	vec4_to_int(t_vec4 c)
{
	int	r;
	int	g;
	int	b;

	r = (int)(fmin(fmax(c.x, 0.0), 1.0) * 255.0);
	g = (int)(fmin(fmax(c.y, 0.0), 1.0) * 255.0);
	b = (int)(fmin(fmax(c.z, 0.0), 1.0) * 255.0);
	return ((r << 16) | (g << 8) | b);
}

t_vec4	norm_color(t_color c)
{
	return ((t_vec4){.x = c.x / 255.0, .y = c.y / 255.0, .z = c.z / 255.0,
		.w = 0.0});
}
