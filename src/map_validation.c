/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:57:33 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/06 10:57:35 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_extension(char *filename)
{
	char	*sub;

	sub = ft_strrchr(filename, '.');
	if (!sub)
		return (0);
	if (ft_strncmp(sub, ".ber", 4) != 0)
		return (0);
	return (1);
}

static int	check_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == '1' || map->grid[i][j] == '0'
				|| map->grid[i][j] == 'P' || map->grid[i][j] == 'E'
				|| map->grid[i][j] == 'C')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	check_format(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (map->height <= 2 || map->height * PX > 1080)
		return (0);
	else if (map->width <= 2 || map->width * PX > 1920)
		return (0);
	while (map->grid[i])
	{
		len = gnl_strlen(map->grid[i]);
		if (map->width == len)
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_walls(t_map *map)
{
	int	i;
	int	j;
	int	imax;
	int	jmax;

	i = 0;
	j = 0;
	imax = map->height - 1;
	jmax = map->width - 1;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] != '1' && (i == 0 || j == 0 || i == imax
					|| j == jmax))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_if_map_is_valid(t_map *map, char *filename)
{
	if (check_extension(filename) == 0)
		return (ft_putstr_fd("Erro:\nFile is not supported\n", 2), 0);
	if (check_format(map) == 0)
		return (ft_putstr_fd("Erro:\nInvalid Format\n", 2), 0);
	if (check_characters(map) == 0)
		return (ft_putstr_fd("Erro:\nInvalid Character\n", 2), 0);
	if (check_walls(map) == 0)
		return (ft_putstr_fd("Erro:\nInvalid Map\n", 2), 0);
	if (check_player(map) == 0)
		return (ft_putstr_fd("Erro:\nInvalid Player\n", 2), 0);
	if (check_exit(map) == 0)
		return (ft_putstr_fd("Erro:\nInvalid Exit\n", 2), 0);
	if (check_collectables(map) == 0)
		return (ft_putstr_fd("Erro:\nInvalid Collectable\n", 2), 0);
	if (prepare_to_flood(map) == 0)
		return (ft_putstr_fd("Erro:\nInvalid Path\n", 2), 0);
	return (1);
}
