/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:57:09 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/06 10:57:10 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(t_data *data)
{
	int	size;

	size = PX;
	data->img.coin = mlx_xpm_file_to_image(data->mlx, "assets/Gold/gold1.xpm",
			&size, &size);
	data->img.player = mlx_xpm_file_to_image(data->mlx,
			"assets/Player/player1.xpm", &size, &size);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "assets/Grass/tree.xpm",
			&size, &size);
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "assets/Grass/grass.xpm",
			&size, &size);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "assets/Grass/exit.xpm",
			&size, &size);
}

static void	get_img(t_data *data, int i, int j)
{
	if (data->map->grid[i][j] == '1')
		data->img.temp = data->img.wall;
	if (data->map->grid[i][j] == '0')
		data->img.temp = data->img.floor;
	if (data->map->grid[i][j] == 'E')
		data->img.temp = data->img.exit;
	if (data->map->grid[i][j] == 'C')
		data->img.temp = data->img.coin;
	if (data->map->grid[i][j] == 'P')
		data->img.temp = data->img.player;
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.temp, j * PX, i * PX);
}

int	put_img(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map->grid[i])
	{
		j = 0;
		while (data->map->grid[i][j])
		{
			get_img(data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	clean_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.coin);
	mlx_destroy_image(data->mlx, data->img.player);
	mlx_destroy_image(data->mlx, data->img.floor);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.exit);
}
