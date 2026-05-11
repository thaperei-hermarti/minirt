/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:00:00 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/11 10:00:00 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "rt_math_bonus.h"
#include <math.h>

static t_color	sample_texture(t_texture *tex, float u, float v)
{
	int				x;
	int				y;
	char			*px;
	unsigned int	color;

	if (!tex->img.img || !tex->img.img_addr || tex->width <= 0
		|| tex->height <= 0)
		return ((t_color){255, 255, 255, 0});
	u = u - floorf(u);
	v = v - floorf(v);
	if (u < 0.0f)
		u += 1.0f;
	if (v < 0.0f)
		v += 1.0f;
	x = (int)(u * (tex->width - 1));
	y = (int)((1.0f - v) * (tex->height - 1));
	px = tex->img.img_addr + (y * tex->img.size_line) + (x
			* (tex->img.bits_per_pixel / 8));
	color = *(unsigned int *)px;
	return ((t_color){(color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF,
		0});
}

static float	sample_height(t_texture *tex, float u, float v)
{
	t_color	c;

	c = sample_texture(tex, u, v);
	return ((0.2126f * c.x + 0.7152f * c.y + 0.0722f * c.z) / 255.0f);
}

static void	get_tangent_bitangent(t_vec4 n, t_vec4 *tangent, t_vec4 *bitangent)
{
	t_vec4	reference;

	reference = (t_vec4){0, 1, 0, 0};
	if (fabs(n.y) >= 0.9)
		reference = (t_vec4){1, 0, 0, 0};
	*tangent = vec4_normalize(vec4_cross_prod(reference, n));
	*bitangent = vec4_normalize(vec4_cross_prod(n, *tangent));
}

t_vec4	perturb_normal(t_texture *tex, t_vec4 n, t_uv uv)
{
	t_vec4	tangent;
	t_vec4	bitangent;
	float	h;
	float	h_u;
	float	h_v;

	get_tangent_bitangent(n, &tangent, &bitangent);
	h = sample_height(tex, uv.u, uv.v);
	h_u = sample_height(tex, uv.u + (1.0f / 128.0f), uv.v);
	h_v = sample_height(tex, uv.u, uv.v + (1.0f / 128.0f));
	n = vec4_add(n, vec4_scale(tangent, (h_u - h) * 0.5f));
	n = vec4_add(n, vec4_scale(bitangent, (h_v - h) * 0.5f));
	return (vec4_normalize(n));
}
