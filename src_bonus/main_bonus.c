/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:00:03 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/07 12:17:36 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_memory_bonus.h"
#include "minirt_bonus.h"
#include "validation_bonus.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_env	env;

	if (!init_env(&env, argc, argv))
		return (EXIT_FAILURE);
	if (!init_window(&env.window, WINDOW_WIDTH, WINDOW_HEIGHT, "MINIRT"))
	{
		free_scene(&env.scene);
		return (EXIT_FAILURE);
	}
	if (!load_scene_textures(&env))
	{
		show_error("Failed to load scene textures");
		destroy_env(&env);
		return (EXIT_FAILURE);
	}
	set_window_hooks(&env);
	render_loop(&env);
	destroy_env(&env);
	return (EXIT_SUCCESS);
}
