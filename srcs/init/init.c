/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:10:21 by gade-alm          #+#    #+#             */
/*   Updated: 2023/07/25 13:43:33 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_vars(t_game *game, t_render *render)
{
	game->win_width = 640;
	game->win_height = 480;
	render->img_height = 64;
	render->img_width = 64;
	render->dir_x = (-1.0 * (render->angle == 90)) + \
	((render->angle == 270) + 0.1);
	render->dir_y = (-1.0 * (render->angle == 0)) + (render->angle == 180);
	render->plane_y = 0.66 * ((render->angle == 270)) + (render->angle == 90);
	render->plane_x = 0.66 * ((render->angle == 0)) + (render->angle == 180);
	render->mv_speed = 0.05;
	render->rt_speed = 0.05;
	render->ceiling_text = check_colour(this()->ceiling);
	render->floor_text = check_colour(this()->floor);
}

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

t_render	*render(void)
{
	static t_render	render;

	return (&render);
}

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}
