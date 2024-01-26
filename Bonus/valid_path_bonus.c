/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:52:44 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/26 03:46:08 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_flood_fill(char **map, int x, int y)
{
	if (y < 0 || y >= ft_strlen(map[0]) || x < 0 || \
			x >= line_num(map) || map[x][y] == '1' || \
			map[x][y] == 'F' || map[x][y] == 'E' || map[x][y] == 'N')
		return ;
	map[x][y] = 'F';
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x, y - 1);
	ft_flood_fill(map, x, y + 1);
}

void	ft_check_flood_fill(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (((map[i][j] == 'C') || (map[i][j] == 'E' \
				&& map[i - 1][j] != 'F' && map[i + 1][j] != 'F' && \
				map[i][j - 1] != 'F' && map[i][j + 1] != 'F')) \
				&& ft_printf("! Map ! -> ivalid path \n"))
				exit(EXIT_FAILURE);
			j++;
		}
		i++;
	}
}

void	check_valid_path(t_struct *s, char *av)
{
	int		fd;
	char	**tmp;

	fd = open(av, O_RDWR, 0777);
	if (fd == -1)
	{
		ft_printf("! MAP ! -> map doesnt exist\n");
		exit(EXIT_FAILURE);
	}
	tmp = get_map(fd);
	if (!tmp)
		exit(EXIT_FAILURE);
	ft_flood_fill(tmp, s->y, s->x);
	ft_check_flood_fill(tmp);
	ft_free_tab(tmp);
}
