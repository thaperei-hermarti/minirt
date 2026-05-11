/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normal_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:00:00 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/11 10:00:00 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "objects_bonus.h"
#include "rt_math_bonus.h"

t_vec4	get_surface_normal(t_surface s, t_vec4 hit_point)
{
	t_vec4	n;

	ft_memset(&n, 0, sizeof(t_vec4));
	n = vec4_mat4_mul(hit_point, s.obj.mat);
	return (vec4_normalize(n));
}
