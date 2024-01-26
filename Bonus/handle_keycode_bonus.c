/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keycode_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 07:28:36 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/26 22:35:53 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(t_struct *s)
{
	if (s->map[s->y - 1][s->x] != '1' && s->map[s->y - 1][s->x] != 'E'
		&& s->map[s->y - 1][s->x] != 'N')
	{
		if (s->map[s->y - 1][s->x] == 'C')
			s->coins--;
		up(s);
		if (s->coins == 0)
			mlx_put_image_to_window(s->mlx, s->win, s->exit_o,
				s->e_x * 50, s->e_y * 50);
		mlx_put_image_to_window(s->mlx, s->win, s->up, s->x * 50, s->y * 50);
		ft_printf("Moves number : %d\n", s->moves);
	}
	else if (s->map[s->y - 1][s->x] == 'E' && s->coins == 0)
		exit(ft_printf("YOU WIN \n"));
	else if (s->map[s->y - 1][s->x] == 'N')
		exit(ft_printf("YOU LOSS \n"));
	else if (s->map[s->y - 1][s->x] == '1' || s->map[s->y - 1][s->x] == 'E')
		mlx_put_image_to_window(s->mlx, s->win, s->up, s->x * 50, s->y * 50);
}

void	move_down(t_struct *s)
{
	if (s->map[s->y + 1][s->x] != '1' && s->map[s->y + 1][s->x] != 'E'
		&& s->map[s->y + 1][s->x] != 'N')
	{
		if (s->map[s->y + 1][s->x] == 'C')
			s->coins--;
		down(s);
		if (s->coins == 0)
			mlx_put_image_to_window(s->mlx, s->win, s->exit_o,
				s->e_x * 50, s->e_y * 50);
		mlx_put_image_to_window(s->mlx, s->win, s->down, s->x * 50, s->y * 50);
		ft_printf("Moves number : %d\n", s->moves);
	}
	else if (s->map[s->y + 1][s->x] == 'E' && s->coins == 0)
		exit(ft_printf("YOU WIN \n"));
	else if (s->map[s->y + 1][s->x] == 'N')
		exit(ft_printf("YOU LOSS \n"));
	else if (s->map[s->y + 1][s->x] == '1' || s->map[s->y + 1][s->x] == 'E')
		mlx_put_image_to_window(s->mlx, s->win, s->down, s->x * 50, s->y * 50);
}

void	move_left(t_struct *s)
{
	if (s->map[s->y][s->x - 1] != '1' && s->map[s->y][s->x - 1] != 'E'
		&& s->map[s->y][s->x - 1] != 'N')
	{
		if (s->map[s->y][s->x - 1] == 'C')
			s->coins--;
		left(s);
		if (s->coins == 0)
			mlx_put_image_to_window(s->mlx, s->win, s->exit_o,
				s->e_x * 50, s->e_y * 50);
		mlx_put_image_to_window(s->mlx, s->win, s->left, s->x * 50, s->y * 50);
		ft_printf("Moves number : %d\n", s->moves);
	}
	else if (s->map[s->y][s->x - 1] == 'E' && s->coins == 0)
		exit(ft_printf("YOU WIN \n"));
	else if (s->map[s->y][s->x - 1] == 'N')
		exit(ft_printf("YOU LOSS \n"));
	else if (s->map[s->y][s->x - 1] == '1' || s->map[s->y][s->x - 1] == 'E')
		mlx_put_image_to_window(s->mlx, s->win, s->left, s->x * 50, s->y * 50);
}

void	move_right(t_struct *s)
{
	if (s->map[s->y][s->x + 1] != '1' && s->map[s->y][s->x + 1] != 'E'
		&& s->map[s->y][s->x + 1] != 'N')
	{
		if (s->map[s->y][s->x + 1] == 'C')
			s->coins--;
		right(s);
		if (s->coins == 0)
			mlx_put_image_to_window(s->mlx, s->win, s->exit_o,
				s->e_x * 50, s->e_y * 50);
		mlx_put_image_to_window(s->mlx, s->win, s->right, s->x * 50, s->y * 50);
		ft_printf("Moves number : %d\n", s->moves);
	}
	else if (s->map[s->y][s->x + 1] == 'E' && s->coins == 0)
		exit(ft_printf("YOU WIN \n"));
	else if (s->map[s->y][s->x + 1] == 'N')
		exit(ft_printf("YOU LOSS \n"));
	else if (s->map[s->y][s->x + 1] == '1' || s->map[s->y][s->x + 1] == 'E')
		mlx_put_image_to_window(s->mlx, s->win, s->right, s->x * 50, s->y * 50);
}

int	key_hook(int keycode, t_struct *s)
{
	if (keycode == W || keycode == KEYUP)
		move_up(s);
	if (keycode == S || keycode == KEYDOWN)
		move_down(s);
	if (keycode == A || keycode == KEYLEFT)
		move_left(s);
	if (keycode == D || keycode == KEYRIGHT)
		move_right(s);
	if (keycode == ESC)
		exit(1);
	return (0);
}
