/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 06:46:38 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/26 03:37:49 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_struct *s)
{
	int	x;

	x = 50;
	s->wall = mlx_xpm_file_to_image(s->mlx, "./Mandatory/img/wall.xpm",
			&x, &x);
	s->space = mlx_xpm_file_to_image(s->mlx, "./Mandatory/img/space.xpm",
			&x, &x);
	s->down = mlx_xpm_file_to_image(s->mlx, "./Mandatory/img/player.xpm",
			&x, &x);
	s->coin = mlx_xpm_file_to_image(s->mlx, "./Mandatory/img/coin.xpm",
			&x, &x);
	s->exit_o = mlx_xpm_file_to_image(s->mlx, "./Mandatory/img/o_exit.xpm",
			&x, &x);
	s->exit_c = mlx_xpm_file_to_image(s->mlx, "./Mandatory/img/c_exit.xpm",
			&x, &x);
	if (!s->wall || !s->space || !s->down
		|| !s->coin || !s->exit_o || !s->exit_c)
	{
		ft_printf("! XPM ! -> invalid img path \n");
		exit(EXIT_FAILURE);
	}
}

void	draw_img(t_struct *s, int x, int y)
{
	if (s->map[y][x] == '1')
		mlx_put_image_to_window(s->mlx, s->win, s->wall, x * 50, y * 50);
	else if (s->map[y][x] == '0')
		mlx_put_image_to_window(s->mlx, s->win, s->space, x * 50, y * 50);
	else if (s->map[y][x] == 'P')
		mlx_put_image_to_window(s->mlx, s->win, s->down, x * 50, y * 50);
	else if (s->map[y][x] == 'C')
		mlx_put_image_to_window(s->mlx, s->win, s->coin, x * 50, y * 50);
	else if (s->map[y][x] == 'E' && s->coins == 0)
		mlx_put_image_to_window(s->mlx, s->win, s->exit_o, x * 50, y * 50);
	else if (s->map[y][x] == 'E' && s->coins != 0)
		mlx_put_image_to_window(s->mlx, s->win, s->exit_c, x * 50, y * 50);
}

void	put_img(t_struct *s)
{
	int	x;
	int	y;

	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			draw_img(s, x, y);
			x++;
		}
		y++;
	}
}
