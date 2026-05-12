/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:15:04 by hermarti          #+#    #+#             */
/*   Updated: 2026/05/07 12:15:05 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_MEMORY_BONUS_H
# define FREE_MEMORY_BONUS_H
# include "scene_bonus.h"

void	free_arr(char **arr);
void	free_content(void *content);
void	free_scene(t_scene *scene);
#endif
