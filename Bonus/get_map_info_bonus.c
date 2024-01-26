/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 06:58:28 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/26 03:45:38 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player_position(t_struct *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == 'P')
			{
				s->y = i;
				s->x = j;
			}
			j++;
		}
		i++;
	}
}

void	get_exit_position(t_struct *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == 'E')
			{
				s->e_y = i;
				s->e_x = j;
			}
			j++;
		}
		i++;
	}
}

int	get_element_number(t_struct *s, char c)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == c)
			{
				n++;
			}
			j++;
		}
		i++;
	}
	return (n);
}

int	line_num(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}
