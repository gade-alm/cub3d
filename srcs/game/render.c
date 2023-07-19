#include "cub3d.h"

static void	draw_back(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (y < game->win_height / 2 && x < game->win_width)
		{
			render()->buffer[y][x] = 0x1e5d6a;
			x++;
		}
		x = 0;
		while (y > game->win_height / 2 && x < game->win_width)
		{
			render()->buffer[y][x] = 0x91938a;
			x++;
		}
		y++;
	}
}

void	rendering(void)
{
	int	x;

	x = -1;
	while (++x < game()->win_width)
	{
		init_ray(render(), game(), x);
		render()->hit = 0;
		while (render()->hit == 0)
			find_hit_wall(render(), this());
		draw_size(render(), game());
		save_draw_numbers(render());
		textures_wall(render(), game(), x);
	}
}

int	start_game(void)
{
	draw_back(game());
	rendering();
	vertical_line(game(), render(), data());
	return (0);
}
