/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:47:38 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/08 14:47:39 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_bonus.h"
#include <stdlib.h>

void	free_content(void *content)
{
	free(content);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_scene(t_scene *scene)
{
	unsigned int	i;

	i = 0;
	while (scene->surfaces && i < scene->num_objs)
	{
		free(scene->surfaces[i].texture_path);
		scene->surfaces[i].texture_path = NULL;
		i++;
	}
	if (scene->light)
		free(scene->light);
	if (scene->surfaces)
		free(scene->surfaces);
	ft_lstclear(&(scene->objs), &free_content);
}
