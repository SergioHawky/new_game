/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:57:17 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/06 11:16:17 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_putstr_fd("Invalid Argument!", 2), 0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->map = load_map(argv[1]);
	if (data->map == NULL)
		return (free(data),
			ft_putstr_fd("Erro: Failed to load the map\n", 2), 0);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, data->map->width * PX,
			data->map->height * PX, "So_long");
	if (!data->win)
		return (free(data->win), 0);
	images(data);
	mlx_loop_hook(data->mlx, put_img, data);
	mlx_key_hook(data->win, handle_keys, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, destroy_game, data);
	mlx_loop(data->mlx);
}
