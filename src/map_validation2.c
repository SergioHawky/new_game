/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:57:43 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/06 10:57:44 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_player(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'P')
			{
				count++;
				map->player_y = i;
				map->player_x = j;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	check_exit(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'E')
			{
				count++;
				map->exit_y = i;
				map->exit_x = j;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	check_collectables(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	map->collectables = count;
	if (count < 1)
		return (0);
	return (1);
}

int	check_flood_fill(t_map *new_map, int x, int y, int collectables)
{
	static int	exit;
	static int	col;

	if (new_map->grid[y][x] == '1')
		return (0);
	if (new_map->grid[y][x] == 'E')
		exit++;
	if (new_map->grid[y][x] == 'C')
		col++;
	new_map->grid[y][x] = '1';
	check_flood_fill(new_map, x + 1, y, collectables);
	check_flood_fill(new_map, x - 1, y, collectables);
	check_flood_fill(new_map, x, y + 1, collectables);
	check_flood_fill(new_map, x, y - 1, collectables);
	if (exit == 1 && col == collectables)
		return (1);
	return (0);
}

int	prepare_to_flood(t_map *map)
{
	t_map	*new_map;
	int		i;
	int		res;

	i = 0;
	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (0);
	new_map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!new_map->grid)
		return (0);
	while (map->grid[i])
	{
		new_map->grid[i] = ft_strdup(map->grid[i]);
		i++;
	}
	new_map->grid[i] = NULL;
	new_map->collectables = map->collectables;
	new_map->player_x = map->player_x;
	new_map->player_y = map->player_y;
	res = check_flood_fill(new_map, new_map->player_x, new_map->player_y,
			map->collectables);
	return (clean_map(new_map), res);
}
