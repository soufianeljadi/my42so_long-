/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:07:10 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/26 03:46:03 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_struct	s;

	if (ac == 2)
	{
		init_struct(&s, av[1]);
		parse_map(&s, av[1]);
		init_mlx(&s);
	}
	else
		write(1, "invalid arguments !\n", 20);
	return (0);
}
