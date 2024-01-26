/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 07:08:16 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/26 03:52:55 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_struct *s)
{
	mlx_put_image_to_window(s->mlx, s->win, s->space,
		s->x * 50, s->y * 50);
	mlx_put_image_to_window(s->mlx, s->win, s->down,
		s->x * 50, (s->y - 1) * 50);
	s->map[s->y][s->x] = '0';
	s->map[s->y - 1][s->x] = 'P';
	s->y--;
	s->moves++;
}

void	down(t_struct *s)
{
	mlx_put_image_to_window(s->mlx, s->win, s->space,
		s->x * 50, s->y * 50);
	mlx_put_image_to_window(s->mlx, s->win, s->down,
		s->x * 50, (s->y + 1) * 50);
	s->map[s->y][s->x] = '0';
	s->map[s->y + 1][s->x] = 'P';
	s->y++;
	s->moves++;
}

void	left(t_struct *s)
{
	mlx_put_image_to_window(s->mlx, s->win, s->space,
		s->x * 50, s->y * 50);
	mlx_put_image_to_window(s->mlx, s->win, s->down,
		(s->x - 1) * 50, s->y * 50);
	s->map[s->y][s->x] = '0';
	s->map[s->y][s->x - 1] = 'P';
	s->x--;
	s->moves++;
}

void	right(t_struct *s)
{
	mlx_put_image_to_window(s->mlx, s->win, s->space,
		s->x * 50, s->y * 50);
	mlx_put_image_to_window(s->mlx, s->win, s->down,
		(s->x + 1) * 50, s->y * 50);
	s->map[s->y][s->x] = '0';
	s->map[s->y][s->x + 1] = 'P';
	s->x++;
	s->moves++;
}
