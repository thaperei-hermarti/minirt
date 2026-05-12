/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:40:17 by hermarti          #+#    #+#             */
/*   Updated: 2026/04/29 20:24:48 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "rt_math.h"

t_vec4	vec4_cross_prod(t_vec4 a, t_vec4 b)
{
	t_vec4	res;

	res.x = (a.y * b.z) - (a.z * b.y);
	res.y = (a.z * b.x) - (a.x * b.z);
	res.z = (a.x * b.y) - (a.y * b.x);
	res.w = 0.0f;
	return (res);
}

t_vec4	vec4_scale(t_vec4 v, double scalar)
{
	t_vec4	res;

	res.x = v.x * scalar;
	res.y = v.y * scalar;
	res.z = v.z * scalar;
	res.w = v.w;
	return (res);
}

t_vec4	vec4_add(t_vec4 a, t_vec4 b)
{
	t_vec4	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	res.w = a.w;
	return (res);
}

t_vec4	vec4_sub(t_vec4 a, t_vec4 b)
{
	t_vec4	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	res.w = a.w;
	return (res);
}

t_vec4	vec4_reflect(t_vec4 v, t_vec4 n)
{
	t_vec4	res;

	res = vec4_sub(v, vec4_scale(n, 2 * vec4_dot_prod(v, n)));
	return (res);
}
