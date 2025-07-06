/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:56:57 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/06 10:56:59 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	reload_player(t_data *data, int x, int y)
{
	static int		moves;
	char			next;

	next = data->map->grid[y][x];
	if (next == '1')
		return (0);
	if (next == 'C')
		data->map->collectables--;
	if (next == 'E' && data->map->collectables == 0)
		return (destroy_game(data));
	data->map->grid[data->map->player_y][data->map->player_x] = '0';
	if (data->map->player_y == data->map->exit_y
		&& data->map->player_x == data->map->exit_x)
		data->map->grid[data->map->player_y][data->map->player_x] = 'E';
	data->map->player_x = x;
	data->map->player_y = y;
	data->map->grid[data->map->player_y][data->map->player_x] = 'P';
	ft_printf("Moves: %d\n", ++moves);
	return (1);
}

int	handle_keys(int keycode, void *param)
{
	t_data	*data;

	data = param;
	if (keycode == XK_w || keycode == XK_Up)
		return (reload_player(data, data->map->player_x,
				data->map->player_y - 1), 0);
	else if (keycode == XK_a || keycode == XK_Left)
		return (reload_player(data, data->map->player_x - 1,
				data->map->player_y), 0);
	else if (keycode == XK_s || keycode == XK_Down)
		return (reload_player(data, data->map->player_x,
				data->map->player_y + 1), 0);
	else if (keycode == XK_d || keycode == XK_Right)
		return (reload_player(data, data->map->player_x + 1,
				data->map->player_y), 0);
	else if (keycode == XK_Escape)
		return (destroy_game(data), 0);
	return (1);
}

int	destroy_game(void *param)
{
	t_data	*data;

	data = param;
	clean_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	clean_map(data->map);
	free(data);
	exit(-1);
	return (0);
}
