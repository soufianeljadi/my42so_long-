/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:07:16 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/26 22:20:30 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_ckeck_extremes(char **map)
{
	int	i;
	int	last;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i++] != '1' && ft_printf("! MAP ! -> should be closed \n"))
			exit(EXIT_FAILURE);
	}
	i = 0;
	last = 0;
	while (map[i++] != NULL)
		last++;
	last--;
	i = 0;
	while (map[last][i])
	{
		if (map[last][i++] != '1'
			&& ft_printf("! MAP ! ->  should be closed\n"))
			exit(EXIT_FAILURE);
	}
}

void	map_ckeck_middle(char **map)
{
	int	i;

	i = 1;
	while (map[i] != NULL)
	{
		if ((map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			&& ft_printf("! MAP ! ->  should be closed\n"))
			exit(EXIT_FAILURE);
		i++;
	}
}

void	map_ckeck_lines_lenght(char **map)
{
	int	i;

	i = 0;
	if (!map[0])
	{
		ft_printf("! MAP ! -> empty map\n");
		exit(EXIT_FAILURE);
	}
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i])
			&& ft_printf("! MAP ! -> lines lenght are not the same\n"))
			exit(EXIT_FAILURE);
		i++;
	}
}

void	map_ckeck_present(t_struct *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] != 'E' && s->map[i][j] != 'C' &&
					s->map[i][j] != 'P' && s->map[i][j] != '1' &&
						s->map[i][j] != '0' && s->map[i][j] != 'N' &&
							ft_printf("! MAP ! -> unknown element\n"))
				exit(EXIT_FAILURE);
			j++;
		}
		i++;
	}
	if (s->player != 1 && ft_printf("! MAP ! -> player doesnt exist\n"))
		exit(EXIT_FAILURE);
	if (s->coins < 1 && ft_printf("! MAP ! -> collections number invalid\n"))
		exit(EXIT_FAILURE);
	if (s->exit != 1 && ft_printf("! MAP ! -> exit doesnt exist\n"))
		exit(EXIT_FAILURE);
}

void	parse_map(t_struct *s, char *av)
{
	map_ckeck_lines_lenght(s->map);
	map_ckeck_present(s);
	map_ckeck_extremes(s->map);
	map_ckeck_middle(s->map);
	check_valid_path(s, av);
}
