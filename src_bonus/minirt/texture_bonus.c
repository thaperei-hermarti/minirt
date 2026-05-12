/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:45:17 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/10 16:39:38 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "scene_bonus.h"
#include "mlx.h"

int	load_texture(t_env *env, t_texture *tex, const char *path)
{
	if (tex->img.img)
		return (1);
	tex->img.img = mlx_xpm_file_to_image(env->window.mlx, (char *)path,
			&tex->width, &tex->height);
	if (!tex->img.img)
		return (0);
	tex->img.img_addr = mlx_get_data_addr(tex->img.img,
			&tex->img.bits_per_pixel, &tex->img.size_line,
			&tex->img.endian);
	return (tex->img.img_addr != NULL);
}

int	load_scene_textures(t_env *env)
{
	unsigned int	i;
	t_surface		*s;
	int				ok;

	ok = 1;
	i = 0;
	while (i < env->scene.num_objs)
	{
		s = &env->scene.surfaces[i];
		if (s->has_texture && s->texture_path)
		{
			if (!load_texture(env, &s->obj.texture, s->texture_path))
			{
				s->has_texture = 0;
				ok = 0;
			}
		}
		i++;
	}
	return (ok);
}

void	destroy_scene_textures(t_env *env)
{
	unsigned int	i;
	t_surface		*s;

	if (!env->window.mlx)
		return ;
	i = 0;
	while (env->scene.surfaces && i < env->scene.num_objs)
	{
		s = &env->scene.surfaces[i];
		if (s->obj.texture.img.img)
		{
			mlx_destroy_image(env->window.mlx, s->obj.texture.img.img);
			s->obj.texture.img.img = NULL;
			s->obj.texture.img.img_addr = NULL;
		}
		i++;
	}
}
