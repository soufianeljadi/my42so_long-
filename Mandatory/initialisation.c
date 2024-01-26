/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:08:58 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/26 21:22:46 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(int fd)
{
	char	*tmp;
	char	*line;
	char	**c;

	line = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (*tmp == '\n' && ft_printf("! MAP ! -> empty line\n"))
			exit(EXIT_FAILURE);
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	c = ft_split(line, '\n');
	free(line);
	return (c);
}

void	ber_check(char *map)
{
	if (ft_strlen(map) <= 4
		&& ft_printf("! MAP ! -> name should be something then '.ber'\n"))
		exit(EXIT_FAILURE);
	if (ft_strstr(map, ".ber") == 0
		&& ft_printf("! MAP ! -> format should be '.ber'\n"))
		exit(EXIT_FAILURE);
}

void	init_struct(t_struct *s, char *av)
{
	int		fd;

	ber_check(av);
	fd = open(av, O_RDWR, 0777);
	if (fd == -1)
	{
		ft_printf("! MAP ! -> map doesnt exist\n");
		exit(EXIT_FAILURE);
	}
	s->map = get_map(fd);
	s->height = line_num(s->map) * 50;
	s->width = ft_strlen(s->map[0]) * 50;
	get_player_position(s);
	get_exit_position(s);
	s->moves = 0;
	s->coins = get_element_number(s, 'C');
	s->exit = get_element_number(s, 'E');
	s->player = get_element_number(s, 'P');
}

int	ft_close(t_struct *s)
{
	(void)s;
	exit(0);
	return (0);
}

void	init_mlx(t_struct *s)
{
	s->mlx = mlx_init();
	if (!s->mlx && ft_printf("! MLX ! -> error\n"))
		exit(EXIT_FAILURE);
	s->win = mlx_new_window(s->mlx, s->width, s->height, "so_long");
	if (!s->win && ft_printf("! MLX ! -> error\n"))
		exit(EXIT_FAILURE);
	if ((ft_strlen(s->map[0]) > 163 || line_num(s->map) > 163)
		&& ft_printf("! MLX ! -> window too large\n"))
		exit(EXIT_FAILURE);
	load_img(s);
	put_img(s);
	mlx_hook(s->win, 2, 0, key_hook, s);
	mlx_hook(s->win, 17, 0, ft_close, s);
	mlx_loop(s->mlx);
}
